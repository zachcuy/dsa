/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (71.65%)
 * Likes:    15667
 * Dislikes: 647
 * Total Accepted:    2.5M
 * Total Submissions: 3.5M
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers nums, every element appears twice except
 * for one. Find that single one.
 *
 * You must implement a solution with a linear runtime complexity and use only
 * constant extra space.
 *
 *
 * Example 1:
 * Input: nums = [2,2,1]
 * Output: 1
 * Example 2:
 * Input: nums = [4,1,2,1,2]
 * Output: 4
 * Example 3:
 * Input: nums = [1]
 * Output: 1
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * -3 * 10^4 <= nums[i] <= 3 * 10^4
 * Each element in the array appears twice except for one element which appears
 * only once.
 *
 *
 */

/*
maintain a count of the number we currently have.
if we encounter a second of it, it can no longer be our number
if we never encounter a second of it, then we know it's our number

use bitwise operator (xor), the xor of two equal numbers is 0.
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int singleNumber(vector<int>& nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            res = (res xor nums[i]);
        }

        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{2, 2, 1};
    vector<int> v2{4, 1, 2, 1, 2};
    vector<int> v3{1};

    obj.singleNumber(v1);
    obj.singleNumber(v2);
    obj.singleNumber(v3);
    return 0;
}