/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

/*
    dp problem where we go through it row by row

    the first row will just have its current value

    subsequent rows will have the reccurence relation:
        dp[i][j] = curCell + min(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1])

    make sure to check if we are at the first or last column since we want to make sure we don't
   access an out of bounds cell

    return the smallest cell in the last row
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        size_t m = matrix.size();
        size_t n = matrix[0].size();

        int minPath = INT_MAX;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i != 0)
                {
                    if (j == 0)
                    {
                        // only check above and above-right
                        matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j + 1]);
                    }
                    else if (j == n - 1)
                    {
                        // only check above and above-left
                        matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j - 1]);
                    }
                    else
                    {
                        // check above, above-left, and above-right
                        matrix[i][j] +=
                            min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i - 1][j + 1]});
                    }
                }

                if (i == m - 1)
                {
                    minPath = min(minPath, matrix[i][j]);
                }
            }
        }

        return minPath;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<vector<int>> grid1{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    vector<vector<int>> grid2{{-19, 57}, {-40, -5}};

    dump(obj.minFallingPathSum(grid1));
    dump(obj.minFallingPathSum(grid2));
    return 0;
}