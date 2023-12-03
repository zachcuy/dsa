/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (53.53%)
 * Likes:    4782
 * Dislikes: 335
 * Total Accepted:    344.1K
 * Total Submissions: 639.6K
 * Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n' +
  '[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * Given a 2D matrix matrix, handle multiple queries of the following
 * type:
 *
 *
 * Calculate the sum of the elements of matrix inside the rectangle defined by
 * its upper left corner (row1, col1) and lower right corner (row2, col2).
 *
 *
 * Implement the NumMatrix class:
 *
 *
 * NumMatrix(int[][] matrix) Initializes the object with the integer matrix
 * matrix.
 * int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the
 * elements of matrix inside the rectangle defined by its upper left corner
 * (row1, col1) and lower right corner (row2, col2).
 *
 *
 * You must design an algorithm where sumRegion works on O(1) time
 * complexity.
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
 * [[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1,
 * 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
 * Output
 * [null, 8, 11, 12]
 *
 * Explanation
 * NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1,
 * 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
 * numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
 * numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green
 * rectangle)
 * numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue
 * rectangle)
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 200
 * -10^4 <= matrix[i][j] <= 10^4
 * 0 <= row1 <= row2 < m
 * 0 <= col1 <= col2 < n
 * At most 10^4 calls will be made to sumRegion.
 *
 *
 */

/*

prefix sums but 2d version

*/
#include "includes.h"
// @lc code=start
// AC
class NumMatrix
{
   public:
    NumMatrix(vector<vector<int>>& matrix)
    {
        for (size_t i = 0; i < matrix.size(); i++)
        {
            vector<int> rowSum;
            int curSum = 0;
            for (size_t j = 0; j < matrix[i].size(); j++)
            {
                curSum += matrix[i][j];
                rowSum.push_back(curSum);
            }

            this->prefix.push_back(rowSum);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int res = 0;
        for (size_t i = row1; i <= row2; i++)
        {
            if (col1 == 0)
            {
                res += this->prefix[i][col2];
            }
            else
            {
                res += (this->prefix[i][col2] - this->prefix[i][col1 - 1]);
            }
        }

        return res;
    }

   private:
    vector<vector<int>> prefix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

int main(int argc, char const* argv[])
{
    vector<vector<int>> v1{
        {3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    NumMatrix obj(v1);

    vector<vector<int>> v2{{-4, -5}};
    NumMatrix obj2(v2);

    // cout << obj.sumRegion(2, 1, 4, 3) << "\n";  // 8
    // cout << obj.sumRegion(1, 1, 2, 2) << "\n";  // 11
    // cout << obj.sumRegion(1, 2, 2, 4) << "\n";  // 12

    cout << obj2.sumRegion(0, 0, 0, 0) << "\n";  // -4
    cout << obj2.sumRegion(0, 0, 0, 1) << "\n";  // -9
    cout << obj2.sumRegion(0, 1, 0, 1) << "\n";  // -9

    return 0;
}
