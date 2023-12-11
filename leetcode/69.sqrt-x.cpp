/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (37.97%)
 * Likes:    7636
 * Dislikes: 4385
 * Total Accepted:    1.7M
 * Total Submissions: 4.5M
 * Testcase Example:  '4'
 *
 * Given a non-negative integer x, return the square root of x rounded down to
 * the nearest integer. The returned integer should be non-negative as well.
 *
 * You must not use any built-in exponent function or operator.
 *
 *
 * For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: x = 4
 * Output: 2
 * Explanation: The square root of 4 is 2, so we return 2.
 *
 *
 * Example 2:
 *
 *
 * Input: x = 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since we round it down
 * to the nearest integer, 2 is returned.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= x <= 2^31 - 1
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int mySqrt(int x)
    {
        /*
        exp(log(x)/2)
        */

        return (exp(log(x + 0.00001) / 2));
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution obj;
    int x1 = 4;
    int x2 = 8;
    int x3 = 2147395600;

    dump(obj.mySqrt(x1));  // 2
    dump(obj.mySqrt(x2));  // 2
    dump(obj.mySqrt(x3));  // 46340
    return 0;
}