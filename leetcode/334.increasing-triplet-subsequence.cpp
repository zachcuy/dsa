/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 *
 * https://leetcode.com/problems/increasing-triplet-subsequence/description/
 *
 * algorithms
 * Medium (41.05%)
 * Likes:    7476
 * Dislikes: 392
 * Total Accepted:    466.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given an integer array nums, return true if there exists a triple of indices
 * (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such
 * indices exists, return false.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,4,5]
 * Output: true
 * Explanation: Any triplet where i < j < k is valid.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [5,4,3,2,1]
 * Output: false
 * Explanation: No triplet exists.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [2,1,5,0,4,6]
 * Output: true
 * Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4]
 * == 4 < nums[5] == 6.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5 * 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 *
 * Follow up: Could you implement a solution that runs in O(n) time complexity
 * and O(1) space complexity?
 */

/*

we can start with initializing three variables
a, b, c

start by initializing a to point to the first element in the list

quick check if length of vector is at least 3 (if it's not, then we automatically return false)

loop through vector starting at [1], since we already know the first one

at each element, check if we have a new lowest value, if we do, then update a
if it isn't, then make that our new B (as long as it's not already smaller than our current value of b)



*/
#include "includes.h"
// @lc code=start
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int a = INT_MAX;
        int b = INT_MAX;

        if (nums.size() < 3)
        {
            return false;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < a and i < nums.size() - 2)
            {
                // update a
                a = nums[i];
            }
            else if (nums[i] > a and nums[i] < b and i < nums.size() - 1)
            {
                b = nums[i];
            }
            else if (nums[i] > a and nums[i] > b and a < b)
            {
                // this occurs when we encounter any value for our last variable
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

int main()
{
    std::vector<int> v{5, 1, 5, 5, 2, 5, 4};
    std::vector<int> v2{9, 10, 5, 11, 10, 9, 8};
    Solution obj;

    obj.increasingTriplet(v2);

    return 0;
}