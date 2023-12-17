/*
 * @lc app=leetcode id=2006 lang=cpp
 *
 * [2006] Count Number of Pairs With Absolute Difference K
 *
 * https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/
 *
 * algorithms
 * Easy (83.05%)
 * Likes:    1527
 * Dislikes: 35
 * Total Accepted:    124.9K
 * Total Submissions: 150.1K
 * Testcase Example:  '[1,2,2,1]\n1'
 *
 * Given an integer array nums and an integer k, return the number of pairs (i,
 * j) where i < j such that |nums[i] - nums[j]| == k.
 *
 * The value of |x| is defined as:
 *
 *
 * x if x >= 0.
 * -x if x < 0.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,2,1], k = 1
 * Output: 4
 * Explanation: The pairs with an absolute difference of 1 are:
 * - [1,2,2,1]
 * - [1,2,2,1]
 * - [1,2,2,1]
 * - [1,2,2,1]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,3], k = 3
 * Output: 0
 * Explanation: There are no pairs with an absolute difference of 3.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,2,1,5,4], k = 2
 * Output: 3
 * Explanation: The pairs with an absolute difference of 2 are:
 * - [3,2,1,5,4]
 * - [3,2,1,5,4]
 * - [3,2,1,5,4]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
 * 1 <= k <= 99
 *
 *
 */

/*
    intuition: use hashmap to keep track of numbers

    possible values we need to find...
    if k = 1...

    nums[i] = 2
    2 - k = 2 - 1 = 1 so we need to find 1
    2 + k = 2 + 1 = 3 so we need to find 3

    nums[1] = 1
    1 - k = 1 - 1 = 0 so we need to find 0
    1 + k = 1 + 1 = 2 so we need to find 2
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int countKDifference(vector<int>& nums, int k)
    {
        unordered_map<int, int> m;  // num, freq
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int a = nums[i] - k;
            int b = nums[i] + k;

            if (m[a])
            {
                count += m[a];
            }
            if (m[b])
            {
                count += m[b];
            }

            // increment count for current frequency
            m[nums[i]]++;
        }

        return count;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{1, 2, 2, 1};
    vector<int> v2{1, 3};
    vector<int> v3{3, 2, 1, 5, 4};

    dump(obj.countKDifference(v1, 1));  // 4
    dump(obj.countKDifference(v2, 3));  // 0
    dump(obj.countKDifference(v3, 2));  // 3
    return 0;
}