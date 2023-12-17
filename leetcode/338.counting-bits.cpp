/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/description/
 *
 * algorithms
 * Easy (77.57%)
 * Likes:    10675
 * Dislikes: 490
 * Total Accepted:    989.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '2'
 *
 * Given an integer n, return an array ans of length n + 1 such that for each i
 * (0 <= i <= n), ans[i] is the number of 1's in the binary representation of
 * i.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: [0,1,1]
 * Explanation:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 *
 *
 * Example 2:
 *
 *
 * Input: n = 5
 * Output: [0,1,1,2,1,2]
 * Explanation:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 * 3 --> 11
 * 4 --> 100
 * 5 --> 101
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 10^5
 *
 *
 *
 * Follow up:
 *
 *
 * It is very easy to come up with a solution with a runtime of O(n log n). Can
 * you do it in linear time O(n) and possibly in a single pass?
 * Can you do it without using any built-in function (i.e., like
 * __builtin_popcount in C++)?
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    vector<int> countBits(int n)
    {
        if (n == 0)  // o(1)
        {
            return {0};
        }
        if (n == 1)  // o(1)
        {
            return {0, 1};
        }

        vector<int> res{0, 1};        // holds the 1-bit count for each number, index = i
        int nextReset = 4;            // next time we reset innerCount
        int innerCount = 0;           // keep track of how far we've gotten in current power subset
        for (int i = 2; i <= n; ++i)  // o(n)
        {
            if (i == nextReset)
            {
                innerCount = 0;
                nextReset *= 2;
            }

            res.push_back(1 + res[innerCount]);
            innerCount++;
        }

        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution obj;

    dump(obj.countBits(5));
    return 0;
}