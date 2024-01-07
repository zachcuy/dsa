/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

/*
    do two runs
        one assuming the first house is taken and ignore the last one
        second one assuming the last house is taken and ignore the first one

    0 1 2 3 4 5 6
    1 2 3 1 2 3 1
    1 2 4 3 6 6 7

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
        else if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        // here we assume we took the first house
        for (int i = 2; i < nums.size() - 1; ++i)
        {
            if (i == 2)
            {
                dp[i] = nums[i] + dp[0];
            }
            else
            {
                dp[i] = nums[i] + max(dp[i - 2], dp[i - 3]);
            }
        }
        int firstMax = max(dp[nums.size() - 2], dp[nums.size() - 3]);

        dp[0] = 0;
        dp[1] = nums[1];
        // here we assume we take the last house
        for (int i = 2; i < nums.size(); ++i)
        {
            if (i == 2)
            {
                dp[i] = nums[i] + dp[0];
            }
            else
            {
                dp[i] = nums[i] + max(dp[i - 2], dp[i - 3]);
            }
        }
        int lastMax = max(dp[nums.size() - 1], dp[nums.size() - 2]);

        return max(firstMax, lastMax);
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{2, 3, 2};
    vector<int> v2{1, 2, 3, 1};
    vector<int> v3{1, 2, 3};
    vector<int> v4{200, 3, 140, 20, 10};

    dump(obj.rob(v1));  // 3
    dump(obj.rob(v2));  // 4
    dump(obj.rob(v3));  // 3
    dump(obj.rob(v4));  // 340
    return 0;
}
