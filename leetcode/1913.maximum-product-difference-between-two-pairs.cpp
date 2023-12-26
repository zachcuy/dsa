/*
 * @lc app=leetcode id=1913 lang=cpp
 *
 * [1913] Maximum Product Difference Between Two Pairs
 *
 * https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/
 *
 * algorithms
 * Easy (81.03%)
 * Likes:    1438
 * Dislikes: 63
 * Total Accepted:    213.6K
 * Total Submissions: 257.2K
 * Testcase Example:  '[5,6,2,7,4]'
 *
 * The product difference between two pairs (a, b) and (c, d) is defined as (a
 * * b) - (c * d).
 *
 *
 * For example, the product difference between (5, 6) and (2, 7) is (5 * 6) -
 * (2 * 7) = 16.
 *
 *
 * Given an integer array nums, choose four distinct indices w, x, y, and z
 * such that the product difference between pairs (nums[w], nums[x]) and
 * (nums[y], nums[z]) is maximized.
 *
 * Return the maximum such product difference.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [5,6,2,7,4]
 * Output: 34
 * Explanation: We can choose indices 1 and 3 for the first pair (6, 7) and
 * indices 2 and 4 for the second pair (2, 4).
 * The product difference is (6 * 7) - (2 * 4) = 34.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,2,5,9,7,4,8]
 * Output: 64
 * Explanation: We can choose indices 3 and 6 for the first pair (9, 8) and
 * indices 1 and 5 for the second pair (2, 4).
 * The product difference is (9 * 8) - (2 * 4) = 64.
 *
 *
 *
 * Constraints:
 *
 *
 * 4 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^4
 *
 */

/*
    intuition: similar to LIS, keep track of the two largest and two smallest
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int maxProductDifference(vector<int>& nums)
    {
        int largest1 = 0;
        int largest2 = 0;

        int smallest1 = INT_MAX;
        int smallest2 = INT_MAX;

        for (auto& num : nums)
        {
            if (num > largest1)
            {
                largest2 = largest1;
                largest1 = num;
            }
            else if (num > largest2)
            {
                largest2 = num;
            }

            if (num < smallest1)
            {
                smallest2 = smallest1;
                smallest1 = num;
            }
            else if (num < smallest2)
            {
                smallest2 = num;
            }
        }

        return (largest1 * largest2) - (smallest1 * smallest2);
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{5, 6, 2, 7, 4};
    vector<int> v2{4, 2, 5, 9, 7, 4, 8};

    dump(obj.maxProductDifference(v1));
    dump(obj.maxProductDifference(v2));
    return 0;
}