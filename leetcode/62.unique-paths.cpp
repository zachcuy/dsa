/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (63.68%)
 * Likes:    15934
 * Dislikes: 420
 * Total Accepted:    1.7M
 * Total Submissions: 2.6M
 * Testcase Example:  '3\n7'
 *
 * There is a robot on an m x n grid. The robot is initially located at the
 * top-left corner (i.e., grid[0][0]). The robot tries to move to the
 * bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move
 * either down or right at any point in time.
 *
 * Given the two integers m and n, return the number of possible unique paths
 * that the robot can take to reach the bottom-right corner.
 *
 * The test cases are generated so that the answer will be less than or equal
 * to 2 * 10^9.
 *
 *
 * Example 1:
 *
 *
 * Input: m = 3, n = 7
 * Output: 28
 *
 *
 * Example 2:
 *
 *
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation: From the top-left corner, there are a total of 3 ways to reach
 * the bottom-right corner:
 * 1. Right -> Down -> Down
 * 2. Down -> Down -> Right
 * 3. Down -> Right -> Down
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= m, n <= 100
 *
 *
 */

/*

dp
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC iterative dp
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> res(m, vector<int>(n, 1));
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 2; j >= 0; --j)
            {
                // add cell to the right and below
                int sum = 0;

                if (j + 1 < n)  // right
                {
                    sum += res[i][j + 1];
                }
                if (i + 1 < m)  // below
                {
                    sum += res[i + 1][j];
                }

                res[i][j] = sum;
            }
        }

        return res[0][0];
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution obj;

    cout << obj.uniquePaths(3, 7) << "\n";  // 28
    cout << obj.uniquePaths(3, 2) << "\n";  // 3
    cout << obj.uniquePaths(1, 1) << "\n";  // 1
    cout << obj.uniquePaths(1, 2) << "\n";  // 1
    cout << obj.uniquePaths(2, 1) << "\n";  // 1
    cout << obj.uniquePaths(2, 2) << "\n";  // 2
    return 0;
}
