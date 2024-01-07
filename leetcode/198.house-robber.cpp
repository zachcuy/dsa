/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int rob(vector<int>& nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        vector<int> dp(nums.size(), 0);

        dp[0] = nums[0];
        dp[1] = nums[1];
        for (int i = 2; i < nums.size(); ++i)
        {
            if (i == 2)
            {
                dp[i] = nums[0] + nums[i];
            }
            else
            {
                dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
            }
        }

        return max(dp[nums.size() - 1], dp[nums.size() - 2]);
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{1, 2, 3, 1};
    vector<int> v2{2, 7, 9, 3, 1};

    dump(obj.rob(v1));
    dump(obj.rob(v2));
    return 0;
}