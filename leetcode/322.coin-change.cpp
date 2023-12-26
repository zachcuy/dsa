/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

/*
    so we can start from 1 to the amount target

    then we can build the number of coins to reach the target using the coins we have

    later iterations, when we have a target like 6 and the coin we have is 4, then we have 2 left.
    we would have already solved the minimum number of coins to sum up to 2 so we can use that!
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            for (auto& coin : coins)
            {
                if (i - coin >= 0)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        if (dp[amount] > amount)
        {
            return -1;
        }
        return dp[amount];
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{1, 2, 5};
    vector<int> v2{2};
    vector<int> v3{1};

    dump(obj.coinChange(v1, 11));
    dump(obj.coinChange(v2, 3));
    dump(obj.coinChange(v3, 0));
    return 0;
}