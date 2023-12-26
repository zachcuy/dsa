/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

/*
    we can use bfs to solve this and keep the one that is the cheapest, which is really just
   dijkstra since this is a weighted graph where all edge weights are positive.

    we can only move right or down.

    the recurrence relationship is:

    base case:
        we start at the beginning which we always have to take so
        dp[0][0] = grid[0][0]

    general case:
        we only care about the cost from the cell above and the cell to the left of our current
   cell, since we can only move right/down
        dp[i][j] = curCell + min(dp[i-1][j], dp[i][j-1])

    make sure to check if we are at the first row or first col since we don't want to access an out
   of bounds index
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 and j == 0)
                {
                    // do nothing
                }
                else if (i == 0)
                {
                    // only check to the left
                    grid[i][j] += grid[i][j - 1];
                }
                else if (j == 0)
                {
                    // only check above
                    grid[i][j] += grid[i - 1][j];
                }
                else
                {
                    // every cell that isn't the start, first row, or first col
                    grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
                }
            }
        }

        return grid[m - 1][n - 1];
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<vector<int>> g1{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<vector<int>> g2{{1, 2, 3}, {4, 5, 6}};

    dump(obj.minPathSum(g1));
    dump(obj.minPathSum(g2));
    return 0;
}