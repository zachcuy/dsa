/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 *
 * https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/
 *
 * algorithms
 * Hard (45.16%)
 * Likes:    4382
 * Dislikes: 82
 * Total Accepted:    196.5K
 * Total Submissions: 434.7K
 * Testcase Example:  '[[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]]\n1'
 *
 * You are given an m x n integer matrix grid where each cell is either 0
 * (empty) or 1 (obstacle). You can move up, down, left, or right from and to
 * an empty cell in one step.
 *
 * Return the minimum number of steps to walk from the upper left corner (0, 0)
 * to the lower right corner (m - 1, n - 1) given that you can eliminate at
 * most k obstacles. If it is not possible to find such walk return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
 * Output: 6
 * Explanation:
 * The shortest path without eliminating any obstacle is 10.
 * The shortest path with one obstacle elimination at position (3,2) is 6. Such
 * path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
 * Output: -1
 * Explanation: We need to eliminate at least two obstacles to find such a
 * walk.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 40
 * 1 <= k <= m * n
 * grid[i][j] is either 0 or 1.
 * grid[0][0] == grid[m - 1][n - 1] == 0
 *
 *
 */

/*
    since we want the shortest path, we should use bfs in this case

    we can also do dfs but since we'd have to attempt many more operations, this wouldn't be a good
   approach.

    the Q will keep track of the cell we want to visit next (and the k value). we can move left,
   down, right.

    if we encounter a wall, then that will have the k value decreased.

    need to keep track of K and cells visited. The K can be used to determine our potential to keep
   moving.
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int shortestPath(vector<vector<int>>& grid, int k)
    {
        queue<tuple<int, int, int>> q;  // row, col, k
        q.push({0, 0, k});

        int level = 0;
        int M = grid.size();
        int N = grid[0].size();
        vector<vector<int>> visited(M, vector<int>(N, -1));
        while (q.size())
        {
            int len = q.size();

            //  0 1 2 3 4 5 6 7
            // {0,1,0,0,0,1,0,0}
            // {0,1,0,1,0,1,0,1}
            // {0,0,0,1,0,0,1,0}

            for (int i = 0; i < len; ++i)
            {
                // next cell to process
                auto [r, c, curK] = q.front();
                q.pop();

                // check goal
                if (r == M - 1 and c == N - 1)
                {
                    return level;
                }

                // add the potential next cells to the q
                vector<pair<int, int>> moves{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
                for (auto [dr, dc] : moves)
                {
                    // check if the move is legal
                    if (r + dr >= 0 and r + dr < M and c + dc >= 0 and c + dc < N and
                        visited[r + dr][c + dc] < curK)
                    {
                        visited[r + dr][c + dc] = curK;
                        // check if the next cell is a wall
                        // if it is, we do curK - 1, and check if the curK is valid
                        if (grid[r + dr][c + dc] == 1 and curK - 1 >= 0)
                        {
                            q.push({r + dr, c + dc, curK - 1});
                        }
                        else if (grid[r + dr][c + dc] == 0 and curK >= 0)
                        {
                            q.push({r + dr, c + dc, curK});
                        }
                    }
                }
            }
            level++;
        }

        return -1;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<vector<int>> grid1{{0, 0, 0}, {1, 1, 0}, {0, 0, 0}, {0, 1, 1}, {0, 0, 0}};
    vector<vector<int>> grid2{{0, 1, 1}, {1, 1, 1}, {1, 0, 0}};
    vector<vector<int>> grid3{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    vector<vector<int>> grid4{{0, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 0},
                              {0, 1}, {0, 1}, {0, 1}, {0, 0}, {1, 0}, {1, 0}, {0, 0}};
    vector<vector<int>> grid5{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                              {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
                              {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                              {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
                              {0, 1, 0, 1, 1, 1, 1, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
                              {0, 1, 1, 1, 1, 1, 1, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}};
    vector<vector<int>> grid6{
        {0, 1, 0, 0, 0, 1, 0, 0}, {0, 1, 0, 1, 0, 1, 0, 1}, {0, 0, 0, 1, 0, 0, 1, 0}};

    dump(obj.shortestPath(grid1, 1));  // 6
    dump(obj.shortestPath(grid2, 1));  // -1
    dump(obj.shortestPath(grid3, 5));  // 387
    dump(obj.shortestPath(grid4, 4));  // 14
    dump(obj.shortestPath(grid5, 1));  // 20
    dump(obj.shortestPath(grid6, 1));  // 13
    return 0;
}
// {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
// {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}
// {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}
// {0, 1, 0, 1, 1, 1, 1, 1, 1, 1}
// {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}
// {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}
// {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}
// {0, 1, 0, 1, 1, 1, 1, 1, 1, 1}
// {0, 1, 0, 1, 1, 1, 1, 0, 0, 0}
// {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}
// {0, 1, 1, 1, 1, 1, 1, 0, 1, 0}
// {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
