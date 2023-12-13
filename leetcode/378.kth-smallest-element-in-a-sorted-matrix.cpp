/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (62.02%)
 * Likes:    9618
 * Dislikes: 332
 * Total Accepted:    577.3K
 * Total Submissions: 929K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given an n x n matrix where each of the rows and columns is sorted in
 * ascending order, return the k^th smallest element in the matrix.
 *
 * Note that it is the k^th smallest element in the sorted order, not the k^th
 * distinct element.
 *
 * You must find a solution with a memory complexity better than O(n^2).
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
 * Output: 13
 * Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and
 * the 8^th smallest number is 13
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[-5]], k = 1
 * Output: -5
 *
 *
 *
 * Constraints:
 *
 *
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 300
 * -10^9 <= matrix[i][j] <= 10^9
 * All the rows and columns of matrix are guaranteed to be sorted in
 * non-decreasing order.
 * 1 <= k <= n^2
 *
 *
 *
 * Follow up:
 *
 *
 * Could you solve the problem with a constant memory (i.e., O(1) memory
 * complexity)?
 * Could you solve the problem in O(n) time complexity? The solution may be too
 * advanced for an interview but you may find reading this paper fun.
 *
 *
 */

/*

    we have square matrix with size n
    then we can use modulo math to figure out where to go
    given k = 8, with n = 3

    rows are sorted in ascending order
    cols are also sorted in ascending order

    however, rows and cols together are not sorted
    we cannot assume that all elements in the third row are bigger
    than all elements in the 2nd row

    1    5    9
    10   11   13
    12   13   15

*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        // use max heap
        priority_queue<int, vector<int>> pq;

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix.size(); ++j)
            {
                pq.push(matrix[i][j]);
                if (pq.size() > k)
                {
                    pq.pop();
                }
            }
        }

        return pq.top();
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<vector<int>> matrix1{{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    obj.kthSmallest(matrix1, 8);
    return 0;
}