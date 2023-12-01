/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Medium (50.36%)
 * Likes:    32407
 * Dislikes: 1352
 * Total Accepted:    3.5M
 * Total Submissions: 6.9M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the subarray with the largest sum, and
 * return its sum.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: The subarray [4,-1,2,1] has the largest sum 6.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1]
 * Output: 1
 * Explanation: The subarray [1] has the largest sum 1.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 * Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    /*
    two pointers, specifically sliding window would be good for this
    since we want the largest subarray, we can keep expanding the sliding window
    unless the sum is negative.

    we can use Kadane's algorithm which is a two-pointer/sliding window technique
    update left and right when our sum is negative
    if it's not negative, then we keep adding the next, keep checking to update maxSum
    */
    int maxSubArray(std::vector<int> &nums)
    {
        if (!nums.size())
        {
            return 0;
        }

        int maxSum = nums[0];
        int sum = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            if (sum < 0)
            {
                sum = 0;
            }

            sum += nums[i];

            if (sum > maxSum)
            {
                maxSum = sum;
            }
        }

        return maxSum;
    }
};
// @lc code=end

int main()
{
    // test cases
    std::vector<int> v1{-2, 1, -3, 4, -1, 2, 1, -5, 4};  // res: 6
    std::vector<int> v2{1};                              // res: 1
    std::vector<int> v3{5, 4, -1, 7, 8};                 // res: 23

    // call solution
    Solution obj;
    std::cout << obj.maxSubArray(v1) << "\n";

    return 0;
}