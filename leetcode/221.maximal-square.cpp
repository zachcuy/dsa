/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int maximalSquare(vector<vector<char>>& matrix)
    {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));

        int maxDim = 0;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (i == 0 or j == 0 or matrix[i][j] - '0' == 0)
                {
                    dp[i][j] = matrix[i][j] - '0';
                }
                else
                {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
                maxDim = max(dp[i][j], maxDim);
            }
        }

        return maxDim * maxDim;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<vector<int>> grid1{{1, 0, 1, 0, 0}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}};
    vector<vector<int>> grid2{{0, 1}, {1, 0}};
    vector<vector<int>> grid3{{0}};
    vector<vector<char>> grid4{{'1', '0'}};
    vector<vector<char>> grid5{{'1', '1', '1', '1', '0'},
                               {'1', '1', '1', '1', '0'},
                               {'1', '1', '1', '1', '1'},
                               {'1', '1', '1', '1', '1'},
                               {'0', '0', '1', '1', '1'}};

    // dump(obj.maximalSquare(grid1));
    // dump(obj.maximalSquare(grid2));
    // dump(obj.maximalSquare(grid3));
    // dump(obj.maximalSquare(grid4)); // 1
    dump(obj.maximalSquare(grid5));  // 16
    return 0;
}