/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Medium (49.97%)
 * Likes:    19516
 * Dislikes: 366
 * Total Accepted:    1.8M
 * Total Submissions: 3.7M
 * Testcase Example:  '[1,2,3,1]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security systems
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 *
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the
 * police.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 400
 *
 *
 */

/*
we can start anywhere but we want to start at either the first or second
we have to skip a house if we choose to take the preceding one or
we can skip two houses in a row if it is better
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int rob(vector<int>& nums)
    {
        // only one house so we just rob that one
        if (nums.size() == 1)
        {
            return nums[0];
        }

        vector<int> res(nums.size() + 1, 0);
        res[0] = nums[0];
        res[1] = nums[1];

        for (int i = 2; i < nums.size(); ++i)
        {
            if (i == 2)
            {
                res[i] = nums[i] + res[i - 2];
            }
            else
            {
                res[i] = nums[i] + max(res[i - 2], res[i - 3]);
            }
        }

        return max(res[nums.size() - 1], res[nums.size() - 2]);
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<int> v1{1, 2, 3, 1};
    vector<int> v2{2, 7, 9, 3, 1};

    cout << obj.rob(v1) << "\n";
    cout << obj.rob(v2) << "\n";
    return 0;
}