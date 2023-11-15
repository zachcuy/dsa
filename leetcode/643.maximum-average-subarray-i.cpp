/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 *
 * https://leetcode.com/problems/maximum-average-subarray-i/description/
 *
 * algorithms
 * Easy (43.11%)
 * Likes:    3085
 * Dislikes: 255
 * Total Accepted:    318.3K
 * Total Submissions: 738.6K
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 * You are given an integer array nums consisting of n elements, and an integer
 * k.
 *
 * Find a contiguous subarray whose length is equal to k that has the maximum
 * average value and return this value. Any answer with a calculation error
 * less than 10^-5 will be accepted.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,12,-5,-6,50,3], k = 4
 * Output: 12.75000
 * Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [5], k = 1
 * Output: 5.00000
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= k <= n <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */
/*

k is guaranteed to be less than or equal to the length of the nums vector

what was need is a pointer to the first value and the last value of our contiguous subarray
then we increment them by one

we find the greatest sum, we can use kadane's algo for that with a specified length

*/
#include "includes.h"

// @lc code=start
class Solution
{
   public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        // calculate the length of
        double maxSum = 0.0f;
        int R = k;

        for (int i = 0; i < k; ++i)
        {
            maxSum += nums[i];
        }

        double curSum = maxSum;
        while (R < nums.size())
        {
            curSum += nums[R] - nums[R - k];

            if (curSum > maxSum)
            {
                maxSum = curSum;
            }

            R++;
        }

        return maxSum / (double)k;
    }
};
// @lc code=end

int main()
{
    Solution obj;

    // test 1
    std::vector<int> v1{1, 12, -5, -6, 50, 3};
    int k1 = 4;

    // test 2
    std::vector<int> v2{5};
    int k2 = 1;

    obj.findMaxAverage(v1, k1);
    obj.findMaxAverage(v2, k2);

    return 0;
}