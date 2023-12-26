/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

/*
    Given an integer n, return the least number of perfect square numbers that sum to n

    so as we go from 1 to n, we need to find if the number is a square. If it is, that has a value
   of 1.

   recurrence relation is:
        base case:
            dp[0] = 0
            dp[1] = 1

        general case:
            only if it's cleanly divisible by j --> (i % j) must = 0
            and only if dp[j] is a square

            dp[i] = min(dp[j] + i/j, dp[i])

        at each value of i, calculate the squares

        0 1 2 3 4 5
        0 1 2 3 2 2


*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int determineSquare(int n)
    {
        int sq = sqrt(n);

        if (sq * sq == n)
        {
            return n;
        }
        else
        {
            return -1;
        }
    }
    // AC
    int numSquares(int n)
    {
        vector<int> dp(n + 1, n);

        vector<int> squares;
        for (int i = 0; i <= n; ++i)
        {
            if (determineSquare(i) != -1)
            {
                squares.push_back(i);
            }
        }

        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (auto& sq : squares)
            {
                if (i - sq >= 0)
                {
                    dp[i] = min(dp[i - sq] + 1, dp[i]);
                }
            }
        }

        return dp[n];
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    // dump(obj.numSquares(1));     // 1
    // dump(obj.numSquares(4));  // 1
    // dump(obj.numSquares(9));  // 1
    // dump(obj.numSquares(12));  // 3
    // dump(obj.numSquares(13));    // 2
    // dump(obj.numSquares(4869));  // 2
    // dump(obj.numSquares(8609));  // 2
    return 0;
}
