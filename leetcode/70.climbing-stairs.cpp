/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (52.23%)
 * Likes:    20374
 * Dislikes: 693
 * Total Accepted:    2.7M
 * Total Submissions: 5.2M
 * Testcase Example:  '2'
 *
 * You are climbing a staircase. It takes n steps to reach the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 45
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    // int climbStairs(int n)
    // {
    //     if (n <= 2)
    //     {
    //         return n;
    //     }

    //     int a = 1;
    //     int b = 1;
    //     for (int i = 2; i <= n; ++i)
    //     {
    //         int tmp = a + b;
    //         a = b;
    //         b = tmp;
    //     }

    //     return b;
    // }

    // Revisited
    int climbStairs(int n)
    {
        // first step: can get there in 1 way
        // second step: can get there in 1 way
        // third step: can get there 1 + 1 = 2 ways
        // fourth step: can get there in 1 + 2 = 3 ways

        if (n <= 2)
        {
            return n;
        }

        int a = 1;  // 1
        int b = 2;  // 2
        for (int i = 2; i < n; ++i)
        {
            int next = a + b;
            a = b;
            b = next;
        }

        return b;
    }
};
// @lc code=end

int main()
{
    Solution obj;

    std::cout << obj.climbStairs(2) << "\n";  // 2
    std::cout << obj.climbStairs(3) << "\n";  // 3
    std::cout << obj.climbStairs(4) << "\n";  // 5
    std::cout << obj.climbStairs(5) << "\n";  // 8
}