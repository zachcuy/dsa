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

    int dfs(std::vector<std::vector<int>> &grid, int row, int col, std::unordered_set<std::pair<int, int>, hashFunction> visited)
    {
        // cases to make sure we stay within the confines of the grid: are on a wall denoted by a '1', off the far edges, or in a visited node
        if (row > row_dim - 1 or col > col_dim - 1 or row < 0 or col < 0 or grid[row][col] == 1 or visited.count({row, col}))
        {
            // we have reached a point where:
            // we are outside the grid OR
            // on a wall OR
            // on an already visited cell
            return 0;
        }
        else if (std::pair<int, int>{row, col} == goal)
        {
            for (auto &i : visited)
            {
                std::cout << "[ " << i.first << " " << i.second << " ]  ";
            }
            std::cout << "\n\n";
            return 1;
        }

        visited.insert(std::pair<int, int>{row, col});

        int count = 0;
        count += dfs(grid, row, col + 1, visited);
        count += dfs(grid, row, col - 1, visited);
        count += dfs(grid, row + 1, col, visited);
        count += dfs(grid, row - 1, col, visited);

        visited.erase(std::pair<int, int>{row, col});

        return count;
    }
};

int main()
{
    Graph g = Graph();

    g.print();

    std::unordered_set<std::pair<int, int>, hashFunction> visited;
    int dfs_count = g.dfs(g.grid, 0, 0, visited);
    std::cout << "dfs: " << dfs_count << "\n";

    return 0;
}