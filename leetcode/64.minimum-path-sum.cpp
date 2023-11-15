/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (62.92%)
 * Likes:    11870
 * Dislikes: 155
 * Total Accepted:    1.1M
 * Total Submissions: 1.7M
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right, which minimizes the sum of all numbers along its
 * path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
 * Output: 7
 * Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[1,2,3],[4,5,6]]
 * Output: 12
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 200
 * 0 <= grid[i][j] <= 200
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution {
   public:
    int dp(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& v)
    {
        if (i == grid.size() - 1 and j == grid[0].size() - 1) {
            return grid[i][j];
        }
        else if (i == grid.size() or j == grid[0].size()) {
            return INT_MAX;
        }
        else if (v[i][j] != 0) {
            return v[i][j];
        }

        v[i][j] =
            grid[i][j] + std::min(dp(grid, i + 1, j, v), dp(grid, i, j + 1, v));

        return v[i][j];
    }
    int minPathSum(vector<vector<int>>& grid)
    {
        vector<vector<int>> v(grid.size(), vector<int>(grid[0].size(), 0));

        return dp(grid, 0, 0, v);
    }
};
// @lc code=end

int main()
{
    Solution obj;

    vector<vector<int>> v1{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<vector<int>> v2{{1, 2, 3, 4}, {4, 5, 6, 7}, {4, 5, 6, 7},
                           {7, 8, 9, 9}, {1, 2, 3, 4}, {1, 2, 3, 4},
                           {9, 8, 7, 4}, {3, 2, 1, 1}, {1, 1, 1, 1}};

    std::cout << obj.minPathSum(v1) << "\n";
    std::cout << obj.minPathSum(v2) << "\n";
}