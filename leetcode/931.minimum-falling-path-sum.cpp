/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 *
 * https://leetcode.com/problems/minimum-falling-path-sum/description/
 *
 * algorithms
 * Medium (65.58%)
 * Likes:    5455
 * Dislikes: 132
 * Total Accepted:    294.7K
 * Total Submissions: 453.6K
 * Testcase Example:  '[[2,1,3],[6,5,4],[7,8,9]]'
 *
 * Given an n x n array of integers matrix, return the minimum sum of any
 * falling path through matrix.
 *
 * A falling path starts at any element in the first row and chooses the
 * element in the next row that is either directly below or diagonally
 * left/right. Specifically, the next element from position (row, col) will be
 * (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
 * Output: 13
 * Explanation: There are two falling paths with a minimum sum as shown.
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[-19,57],[-40,-5]]
 * Output: -59
 * Explanation: The falling path with a minimum sum is shown.
 *
 *
 *
 * Constraints:
 *
 *
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 100
 * -100 <= matrix[i][j] <= 100
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (j == 0)
                {
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j + 1]);
                }
                else if (j == m - 1)
                {
                    matrix[i][j] += min(matrix[i - 1][j - 1], matrix[i - 1][j]);
                }
                else
                {
                    matrix[i][j] +=
                        min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i - 1][j + 1]});
                }
            }
        }

        int smallestVal = INT_MAX;
        for (int i = 0; i < m; ++i)
        {
            smallestVal = min(smallestVal, matrix[n - 1][i]);
        }

        return smallestVal;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<vector<int>> v1{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    vector<vector<int>> v2{{-19, 57}, {-40, -5}};

    dump(obj.minFallingPathSum(v1));
    dump(obj.minFallingPathSum(v2));
    return 0;
}