/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower/description/
 *
 * algorithms
 * Easy (52.58%)
 * Likes:    3443
 * Dislikes: 454
 * Total Accepted:    567.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '10\n6'
 *
 * We are playing the Guess Game. The game is as follows:
 *
 * I pick a number from 1 to n. You have to guess which number I picked.
 *
 * Every time you guess wrong, I will tell you whether the number I picked is
 * higher or lower than your guess.
 *
 * You call a pre-defined API int guess(int num), which returns three possible
 * results:
 *
 *
 * -1: Your guess is higher than the number I picked (i.e. num > pick).
 * 1: Your guess is lower than the number I picked (i.e. num < pick).
 * 0: your guess is equal to the number I picked (i.e. num == pick).
 *
 *
 * Return the number that I picked.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 10, pick = 6
 * Output: 6
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1, pick = 1
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: n = 2, pick = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2^31 - 1
 * 1 <= pick <= n
 *
 *
 */

/*

in: int
out: n

call function: guess(int) -> int

do binary search

*/
#include "includes.h"
int guess(int n)
{
    int pick = 1702766719;
    if (n > pick)
    {
        return -1;
    }
    else if (n < pick)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
   public:
    int guessNumber(int n)
    {
        long long L = 1;
        long long R = n;

        while (L <= R)
        {
            long long mid = (L + R) / 2;
            int result = guess(mid);
            if (result == -1)
            {
                // mid is too high, decrease R
                R = mid - 1;
            }
            else if (result == 1)
            {
                // mid is too low, increase L
                L = mid + 1;
            }
            else
            {
                // guess is correct
                return mid;
            }
        }

        return -1;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution obj;

    int n1 = 10;
    int n2 = 2126753390;
    cout << obj.guessNumber(n1) << "\n";
    cout << obj.guessNumber(n2) << "\n";

    return 0;
}
