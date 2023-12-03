/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
 *
 * https://leetcode.com/problems/transpose-matrix/description/
 *
 * algorithms
 * Easy (65.84%)
 * Likes:    3121
 * Dislikes: 429
 * Total Accepted:    276.8K
 * Total Submissions: 418.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a 2D integer array matrix, return the transpose of matrix.
 *
 * The transpose of a matrix is the matrix flipped over its main diagonal,
 * switching the matrix's row and column indices.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[1,4,7],[2,5,8],[3,6,9]]
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[1,2,3],[4,5,6]]
 * Output: [[1,4],[2,5],[3,6]]
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 1000
 * 1 <= m * n <= 10^5
 * -10^9 <= matrix[i][j] <= 10^9
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix)
    {
        vector<vector<int>> res;

        for (size_t i = 0; i < matrix[0].size(); i++)
        {
            vector<int> tmp;
            for (size_t j = 0; j < matrix.size(); j++)
            {
                tmp.push_back(matrix[j][i]);
            }
            res.push_back(tmp);
        }

        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    return 0;
}
