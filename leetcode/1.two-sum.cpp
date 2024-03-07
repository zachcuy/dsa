/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include "includes.h"
// @lc code=start
class Solution
{
public:
    // AC: very easy problem
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            int remainder = target - nums[i];

            if (m.count(remainder)) {
                return {m[remainder], i};
            } else {
                m[nums[i]] = i;
            }
        }

        return {-1, -1};
    }
};
// @lc code=end
