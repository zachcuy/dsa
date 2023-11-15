/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 *
 * https://leetcode.com/problems/find-pivot-index/description/
 *
 * algorithms
 * Easy (56.12%)
 * Likes:    7860
 * Dislikes: 796
 * Total Accepted:    958.5K
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,7,3,6,5,6]'
 *
 * Given an array of integers nums, calculate the pivot index of this array.
 *
 * The pivot index is the index where the sum of all the numbers strictly to
 * the left of the index is equal to the sum of all the numbers strictly to the
 * index's right.
 *
 * If the index is on the left edge of the array, then the left sum is 0
 * because there are no elements to the left. This also applies to the right
 * edge of the array.
 *
 * Return the leftmost pivot index. If no such index exists, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,7,3,6,5,6]
 * Output: 3
 * Explanation:
 * The pivot index is 3.
 * Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
 * Right sum = nums[4] + nums[5] = 5 + 6 = 11
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3]
 * Output: -1
 * Explanation:
 * There is no index that satisfies the conditions in the problem statement.
 *
 * Example 3:
 *
 *
 * Input: nums = [2,1,-1]
 * Output: 0
 * Explanation:
 * The pivot index is 0.
 * Left sum = 0 (no elements to the left of index 0)
 * Right sum = nums[1] + nums[2] = 1 + -1 = 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -1000 <= nums[i] <= 1000
 *
 *
 *
 * Note: This question is the same as 1991:
 * https://leetcode.com/problems/find-the-middle-index-in-array/
 *
 */

/*

left sum starts as nums[i], right sum starts as total sum - nums[i]

as we move the pointer, we decrease the right sum and increase the left sum

return the index when the left and right after equal

default return: -1
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int pivotIndex(vector<int>& nums)
    {
        int right = std::accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            right -= nums[i];
            if (left == right)
            {
                return i;
            }
            left += nums[i];
        }

        return -1;
    }
};
// @lc code=end

int main()
{
    vector<int> v1{1, 7, 3, 6, 5, 6};
    vector<int> v2{1, 2, 3};
    vector<int> v3{2, 1, -1};

    Solution obj;
    cout << obj.pivotIndex(v1) << "\n";
    cout << obj.pivotIndex(v2) << "\n";
    cout << obj.pivotIndex(v3) << "\n";
}