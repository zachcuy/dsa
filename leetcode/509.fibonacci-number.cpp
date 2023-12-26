/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 *
 * https://leetcode.com/problems/fibonacci-number/description/
 *
 * algorithms
 * Easy (70.36%)
 * Likes:    7770
 * Dislikes: 337
 * Total Accepted:    1.6M
 * Total Submissions: 2.3M
 * Testcase Example:  '2'
 *
 * The Fibonacci numbers, commonly denoted F(n) form a sequence, called the
 * Fibonacci sequence, such that each number is the sum of the two preceding
 * ones, starting from 0 and 1. That is,
 *
 *
 * F(0) = 0, F(1) = 1
 * F(n) = F(n - 1) + F(n - 2), for n > 1.
 *
 *
 * Given n, calculate F(n).
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: 1
 * Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3
 * Output: 2
 * Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
 *
 *
 * Example 3:
 *
 *
 * Input: n = 4
 * Output: 3
 * Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 30
 *
 *
 */

/*

    top-down (memoization + recursion) works since there are subproblems

    we can do bottom up and not have the overhead of memoization + recursion


    we only need last two numbers, so we keep updating as we go along
    base case is 0 and 1

*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int fib(int n)
    {
        if (n == 0 or n == 1)
        {
            return n;
        }
        int n1 = 0;
        int n2 = 1;

        for (int i = 2; i <= n; ++i)
        {
            int tmp = n1 + n2;
            n1 = n2;
            n2 = tmp;
        }

        return n2;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution obj;
    dump(obj.fib(2));
    dump(obj.fib(3));
    dump(obj.fib(4));
    dump(obj.fib(5));
    return 0;
}