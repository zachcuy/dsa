#include "includes.h"

struct hashFunction
{
    size_t operator()(const pair<int,
                                 int> &x) const
    {
        return x.first ^ x.second;
    }
};

struct Graph
{
    std::vector<std::vector<int>> grid{{0, 0, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 1}, {0, 1, 0, 0}};
    std::pair<int, int> goal = {grid.size() - 1, grid.size() - 1};

    // assume square matrix
    int row_dim = grid.size();
    int col_dim = grid.size();

    void print()
    {
        for (auto &i : grid)
        {
            for (auto &j : i)
            {
                std::cout << j << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n\n";
    }

    int bfs(std::vector<std::vector<int>> &grid)
    {
        // use a Q
        std::queue<std::pair<int, int>> q;

        // add starting location
        q.push(std::pair<int, int>{0, 0});

        // to keep track of already visited nodes, use a set
        std::unordered_set<std::pair<int, int>, hashFunction> visited{};

        int length = 0;
        while (q.size())
        {
            for (int i = 0; i < q.size(); ++i)
            {
                // get cell
                std::pair<int, int> cur = q.front();
                q.pop();

                // check if loc is out of bounds OR a wall OR already visited
                if (cur.first > row_dim - 1 or cur.second > col_dim - 1 or cur.first < 0 or cur.second < 0 or grid[cur.first][cur.second] == 1 or visited.count(cur))
                {
                    continue;
                }
                else if (cur == goal) // this is only checked if we are at a valid node
                {
                    return length + 1;
                }

                // add adjacent nodes to the q, only if we haven't already visited it
                if (!visited.count({cur.first, cur.second + 1}))
                {
                    q.push(std::pair<int, int>{cur.first, cur.second + 1}); // right
                }
                if (!visited.count({cur.first + 1, cur.second}))
                {
                    q.push(std::pair<int, int>{cur.first + 1, cur.second}); // down
                }

                if (!visited.count({cur.first, cur.second - 1}))
                {
                    q.push(std::pair<int, int>{cur.first, cur.second - 1}); // left
                }

                if (!visited.count({cur.first - 1, cur.second}))
                {
                    q.push(std::pair<int, int>{cur.first - 1, cur.second}); // up
                }

                // add current cell to visited
                visited.insert(cur);
            }
            length++;
        }

        return 0;
    }
};

int main()
{
    Graph g = Graph();

    g.print();

    int bfs_count = g.bfs(g.grid);
    std::cout << "bfs: " << bfs_count << "\n";

    return 0;
}