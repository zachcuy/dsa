/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (64.06%)
 * Likes:    11039
 * Dislikes: 3256
 * Total Accepted:    1.8M
 * Total Submissions: 2.8M
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array nums containing n distinct numbers in the range [0, n],
 * return the only number in the range that is missing from the array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,0,1]
 * Output: 2
 * Explanation: n = 3 since there are 3 numbers, so all numbers are in the
 * range [0,3]. 2 is the missing number in the range since it does not appear
 * in nums.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1]
 * Output: 2
 * Explanation: n = 2 since there are 2 numbers, so all numbers are in the
 * range [0,2]. 2 is the missing number in the range since it does not appear
 * in nums.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * Explanation: n = 9 since there are 9 numbers, so all numbers are in the
 * range [0,9]. 8 is the missing number in the range since it does not appear
 * in nums.
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 10^4
 * 0 <= nums[i] <= n
 * All the numbers of nums are unique.
 *
 *
 *
 * Follow up: Could you implement a solution using only O(1) extra space
 * complexity and O(n) runtime complexity?
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int missingNumber(vector<int>& nums)
    {
        int len = nums.size();
        // summation of integers is: num_elements * (upper_bound + lower_bound) / 2
        int maxSum = (len * (len + 1)) / 2;

        int sum = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        return maxSum - sum;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<int> v1{3, 0, 1};
    vector<int> v2{0, 1};
    vector<int> v3{9, 6, 4, 2, 3, 5, 7, 0, 1};

    dump(obj.missingNumber(v1));  // 2
    dump(obj.missingNumber(v2));  // 2
    dump(obj.missingNumber(v3));  // 8
    return 0;
}