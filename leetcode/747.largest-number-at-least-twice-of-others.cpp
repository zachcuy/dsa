/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 *
 * https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/
 *
 * algorithms
 * Easy (47.91%)
 * Likes:    1150
 * Dislikes: 879
 * Total Accepted:    226K
 * Total Submissions: 469.4K
 * Testcase Example:  '[3,6,1,0]'
 *
 * You are given an integer array nums where the largest integer is unique.
 *
 * Determine whether the largest element in the array is at least twice as much
 * as every other number in the array. If it is, return the index of the
 * largest element, or return -1 otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,6,1,0]
 * Output: 1
 * Explanation: 6 is the largest integer.
 * For every other number in the array x, 6 is at least twice as big as x.
 * The index of value 6 is 1, so we return 1.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,4]
 * Output: -1
 * Explanation: 4 is less than twice the value of 3, so we return -1.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 50
 * 0 <= nums[i] <= 100
 * The largest element in nums is unique.
 *
 *
 */

/*
go through array and track (largest and second largest product so far), largest element so far
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int dominantIndex(vector<int>& nums)
    {
        int largest = *max_element(nums.begin(), nums.end());
        int largestIdx = 0;
        int largestProd = 0;

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] == largest)
            {
                largestIdx = i;
            }
            else if (nums[i] * 2 > largestProd)
            {
                largestProd = nums[i] * 2;
            }
        }

        if (largest >= largestProd)
        {
            return largestIdx;
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<int> v1{3, 6, 1, 0};
    vector<int> v2{1, 2, 3, 4};

    cout << obj.dominantIndex(v1) << "\n";  // 1
    cout << obj.dominantIndex(v2) << "\n";  // -1

    return 0;
}
