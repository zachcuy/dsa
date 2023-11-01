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

Can't rob adjacent houses so we always have to skip between houses

might need to skip two houses so we can rob better ones

1 2 3 1
best is 1 + 3 = 4

2 7 9 3 1
best is 2 + 9 + 1 = 12

2 7 9 3 1 9
best is 2 + 9 + 9 = 20

this is a DP problem

*/

#include "includes.h"
// @lc code=start
class Solution
{
public:
    int rob(std::vector<int> &nums)
    {
        int n = nums.size();
        std::vector<int> v(n, 0);

        if (n == 1)
        {
            return nums[0];
        }

        // need to keep track of two values,
        v[0] = nums[0];
        v[1] = nums[1];

        // dp loop (pushing)
        for (int i = 2; i < n; ++i)
        {
            if (i == 2)
            {
                v[i] = v[i - 2] + nums[i];
            }
            else
            {
                v[i] = std::max(v[i - 2], v[i - 3]) + nums[i];
            }
        }

        return std::max(v[n - 1], v[n - 2]);
    }
};
// @lc code=end

int main()
{
    // tests
    std::vector<int> v1{1, 2, 3, 1};    // 4
    std::vector<int> v2{2, 7, 9, 3, 1}; // 12
    std::vector<int> v3{0, 3, 2, 4};    // 4

    Solution obj;
    int out = obj.rob(v1);
    std::cout << out << "\n\n";

    return 0;
}