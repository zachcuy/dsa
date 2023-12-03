/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 *
 * https://leetcode.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (57.74%)
 * Likes:    5329
 * Dislikes: 446
 * Total Accepted:    1M
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,1,0,1,1,1]'
 *
 * Given a binary array nums, return the maximum number of consecutive 1's in
 * the array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive
 * 1s. The maximum number of consecutive 1s is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,0,1,1,0,1]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int globalMax = 0;
        int curMax = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                globalMax = max(globalMax, curMax);
                curMax = 0;
            }
            else
            {
                curMax++;
            }
        }

        return max(globalMax, curMax);
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    return 0;
}
