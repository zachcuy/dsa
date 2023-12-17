/*
 * @lc app=leetcode id=1800 lang=cpp
 *
 * [1800] Maximum Ascending Subarray Sum
 *
 * https://leetcode.com/problems/maximum-ascending-subarray-sum/description/
 *
 * algorithms
 * Easy (62.54%)
 * Likes:    694
 * Dislikes: 23
 * Total Accepted:    49.6K
 * Total Submissions: 79.4K
 * Testcase Example:  '[10,20,30,5,10,50]'
 *
 * Given an array of positive integers nums, return the maximum possible sum of
 * an ascending subarray in nums.
 *
 * A subarray is defined as a contiguous sequence of numbers in an array.
 *
 * A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i
 * where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is
 * ascending.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,20,30,5,10,50]
 * Output: 65
 * Explanation: [5,10,50] is the ascending subarray with the maximum sum of
 * 65.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [10,20,30,40,50]
 * Output: 150
 * Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum
 * of 150.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [12,17,15,13,10,11,12]
 * Output: 33
 * Explanation: [10,11,12] is the ascending subarray with the maximum sum of
 * 33.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 100
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int maxAscendingSum(vector<int>& nums)
    {
        int maxSum = nums[0];
        int curSum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] <= nums[i - 1])
            {
                // reset currrent sum because the element is not larger than previous
                curSum = nums[i];
            }
            else
            {
                curSum += nums[i];
            }

            maxSum = max(curSum, maxSum);
        }

        return maxSum;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{10, 20, 30, 5, 10, 50};
    vector<int> v2{10, 20, 30, 40, 50};
    vector<int> v3{12, 17, 15, 13, 10, 11, 12};
    vector<int> v4{100, 10, 1};

    dump(obj.maxAscendingSum(v1));
    dump(obj.maxAscendingSum(v2));
    dump(obj.maxAscendingSum(v3));
    dump(obj.maxAscendingSum(v4));
    return 0;
}