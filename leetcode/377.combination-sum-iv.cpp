/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 *
 * https://leetcode.com/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (53.95%)
 * Likes:    7203
 * Dislikes: 642
 * Total Accepted:    458K
 * Total Submissions: 847.8K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * Given an array of distinct integers nums and a target integer target, return
 * the number of possible combinations that add up to target.
 *
 * The test cases are generated so that the answer can fit in a 32-bit
 * integer.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3], target = 4
 * Output: 7
 * Explanation:
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * Note that different sequences are counted as different combinations.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [9], target = 3
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 1000
 * All the elements of nums are unique.
 * 1 <= target <= 1000
 *
 *
 *
 * Follow up: What if negative numbers are allowed in the given array? How does
 * it change the problem? What limitation we need to add to the question to
 * allow negative numbers?
 *
 */

/*
    order matters so we don't have to sort, and we can reuse numbers
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC: top down (recursion + memoization)
    // int dp(vector<int>& nums, int target, int idx, map<int, int>& memo, vector<int>& tmp)
    // {
    //     if (target < 0)
    //     {
    //         return 0;
    //     }
    //     else if (memo.count(target))
    //     {
    //         return memo[target];
    //     }
    //     else if (target == 0)
    //     {
    //         return 1;
    //     }

    //     int count = 0;
    //     for (int i = 0; i < nums.size(); ++i)
    //     {
    //         // include current number
    //         tmp.push_back(nums[i]);
    //         count += dp(nums, target - nums[i], i, memo, tmp);

    //         // exclude current number
    //         tmp.pop_back();
    //     }

    //     return memo[target] = count;
    // }
    // int combinationSum4(vector<int>& nums, int target)
    // {
    //     map<int, int> memo;
    //     vector<int> tmp;
    //     int ans = dp(nums, target, 0, memo, tmp);

    //     return ans;
    // }

    // bottom up (tabulation)
    int combinationSum4(vector<int>& nums, int target)
    {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; ++i)
        {
            for (auto num : nums)
            {
                if (i - num >= 0 and dp[i] <= INT_MAX)
                {
                    dp[i] += static_cast<long long>(dp[i - num]);
                }
            }
        }

        return dp[target];
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<int> v1{1, 2, 3};
    vector<int> v2{9};
    vector<int> v3{4, 2, 1};
    vector<int> v4{10,  20,  30,  40,  50,  60,  70,  80,  90,  100, 110, 120, 130, 140, 150,
                   160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300,
                   310, 320, 330, 340, 350, 360, 370, 380, 390, 400, 410, 420, 430, 440, 450,
                   460, 470, 480, 490, 500, 510, 520, 530, 540, 550, 560, 570, 580, 590, 600,
                   610, 620, 630, 640, 650, 660, 670, 680, 690, 700, 710, 720, 730, 740, 750,
                   760, 770, 780, 790, 800, 810, 820, 830, 840, 850, 860, 870, 880, 890, 900,
                   910, 920, 930, 940, 950, 960, 970, 980, 990, 111};

    dump(obj.combinationSum4(v1, 4));
    dump(obj.combinationSum4(v2, 3));
    // dump(obj.combinationSum4(v3, 32));
    dump(obj.combinationSum4(v4, 999));
    return 0;
}