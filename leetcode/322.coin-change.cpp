/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (42.96%)
 * Likes:    17984
 * Dislikes: 408
 * Total Accepted:    1.6M
 * Total Submissions: 3.7M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given an integer array coins representing coins of different
 * denominations and an integer amount representing a total amount of money.
 *
 * Return the fewest number of coins that you need to make up that amount. If
 * that amount of money cannot be made up by any combination of the coins,
 * return -1.
 *
 * You may assume that you have an infinite number of each kind of coin.
 *
 *
 * Example 1:
 *
 *
 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 *
 *
 * Example 2:
 *
 *
 * Input: coins = [2], amount = 3
 * Output: -1
 *
 *
 * Example 3:
 *
 *
 * Input: coins = [1], amount = 0
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // int coinChange(vector<int>& coins, int amount)
    // {
    //     vector<int> dp(amount + 1, INT_MAX - 1);
    //     dp[0] = 0;  // takes 0 coins to make 0

    //     for (int i = 1; i <= amount; ++i)
    //     {
    //         for (int j = 0; j < coins.size(); j++)
    //         {
    //             if (i - coins[j] >= 0)
    //             {
    //                 dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
    //             }
    //         }
    //     }

    //     if (dp[amount] != INT_MAX - 1)
    //     {
    //         return dp[amount];
    //     }
    //     return -1;
    // }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{1, 2, 5};
    vector<int> v2{2};
    vector<int> v3{1};

    cout << obj.coinChange(v1, 11) << "\n";
    cout << obj.coinChange(v2, 3) << "\n";
    cout << obj.coinChange(v3, 0) << "\n";
    return 0;
}
