/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (45.89%)
 * Likes:    2958
 * Dislikes: 270
 * Total Accepted:    766.4K
 * Total Submissions: 1.7M
 * Testcase Example:  '27'
 *
 * Given an integer n, return true if it is a power of three. Otherwise, return
 * false.
 *
 * An integer n is a power of three, if there exists an integer x such that n
 * == 3^x.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 27
 * Output: true
 * Explanation: 27 = 3^3
 *
 *
 * Example 2:
 *
 *
 * Input: n = 0
 * Output: false
 * Explanation: There is no x where 3^x = 0.
 *
 *
 * Example 3:
 *
 *
 * Input: n = -1
 * Output: false
 * Explanation: There is no x where 3^x = (-1).
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= n <= 2^31 - 1
 *
 *
 *
 * Follow up: Could you solve it without loops/recursion?
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
        {
            return false;
        }

        int logVal = log(n) / log(3) + 0.00001;

        return pow(3, logVal) == n;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution obj;
    obj.isPowerOfThree(27);
    // obj.isPowerOfThree(0);
    // obj.isPowerOfThree(-1);
    obj.isPowerOfThree(45);
    obj.isPowerOfThree(243);
    return 0;
}