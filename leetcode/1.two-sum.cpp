/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <vector>
#include <unordered_map>
// @lc code=start
class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            int diff = target - nums[i];

            if (m.count(diff) > 0)
            {
                return {i, m[diff]};
            }
            m[nums[i]] = i;
        }

        return {};
    }
};
// @lc code=end
