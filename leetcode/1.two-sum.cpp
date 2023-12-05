/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (50.81%)
 * Likes:    52189
 * Dislikes: 1711
 * Total Accepted:    11.1M
 * Total Submissions: 21.7M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * You can return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * Only one valid answer exists.
 *
 *
 *
 * Follow-up: Can you come up with an algorithm that is less than O(n^2) time
 * complexity?
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); ++i)
        {
            int remainder = target - nums[i];

            if (m.count(remainder))
            {
                return {i, m[remainder]};
            }
            else
            {
                m[nums[i]] = i;
            }
        }

        return {-1, -1};
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{2, 7, 11, 15};
    vector<int> v2{3, 2, 4};
    vector<int> v3{3, 3};

    obj.twoSum(v1, 9);  // [0, 1]
    // obj.twoSum(v2, 6);  // [1, 2]
    // obj.twoSum(v3, 6);  // [0, 1]
    return 0;
}