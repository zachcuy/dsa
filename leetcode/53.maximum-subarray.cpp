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

/*
intuition: kadane's algorithm

*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int maxSubArray(vector<int>& nums)
    {
        int maxSum = -INT_MAX;
        int curSum = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            curSum += nums[i];

            if (curSum > maxSum)
            {
                maxSum = curSum;
            }
            if (curSum < 0)
            {
                curSum = 0;
            }
        }

        return maxSum;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<int> v1{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> v2{1};
    vector<int> v3{5, 4, -1, 7, 8};

    cout << obj.maxSubArray(v1) << "\n";  // 6
    cout << obj.maxSubArray(v2) << "\n";  // 1
    cout << obj.maxSubArray(v3) << "\n";  // 23
    return 0;
}
