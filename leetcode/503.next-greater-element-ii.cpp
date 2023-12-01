/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 *
 * https://leetcode.com/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (63.43%)
 * Likes:    7521
 * Dislikes: 179
 * Total Accepted:    349.6K
 * Total Submissions: 550.9K
 * Testcase Example:  '[1,2,1]'
 *
 * Given a circular integer array nums (i.e., the next element of
 * nums[nums.length - 1] is nums[0]), return the next greater number for every
 * element in nums.
 *
 * The next greater number of a number x is the first greater number to its
 * traversing-order next in the array, which means you could search circularly
 * to find its next greater number. If it doesn't exist, return -1 for this
 * number.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2;
 * The number 2 can't find next greater number.
 * The second 1's next greater number needs to search circularly, which is also
 * 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,4,3]
 * Output: [2,3,4,-1,4]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

/*

use a mono stack.

since we want the next greater element, we should use a mono decreasing stack.

also, since we want the circular, we can do it twice with the remaining stack values
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        vector<int> ans(nums.size(), -INT_MAX);
        stack<int> s;

        for (int i = 0; i < nums.size(); ++i)
        {
            while (s.size() and nums[s.top()] < nums[i])
            {
                ans[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            while (s.size() and nums[s.top()] < nums[i])
            {
                ans[s.top()] = nums[i];
                s.pop();
            }
        }

        while (s.size())
        {
            ans[s.top()] = -1;
            s.pop();
        }

        return ans;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<int> v1{1, 2, 1};
    vector<int> v2{1, 2, 3, 4, 3};

    obj.nextGreaterElements(v1);
    obj.nextGreaterElements(v2);
    return 0;
}
