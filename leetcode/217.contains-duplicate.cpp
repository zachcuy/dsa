/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (s.count(nums[i]))
            {
                return true;
            }
            s.insert(nums[i]);
        }

        return false;
    }
};
// @lc code=end
