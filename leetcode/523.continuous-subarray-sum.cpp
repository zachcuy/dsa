/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 *
 * https://leetcode.com/problems/continuous-subarray-sum/description/
 *
 * algorithms
 * Medium (28.56%)
 * Likes:    5246
 * Dislikes: 510
 * Total Accepted:    421.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '[23,2,4,6,7]\n6'
 *
 * Given an integer array nums and an integer k, return true if nums has a good
 * subarray or false otherwise.
 *
 * A good subarray is a subarray where:
 *
 *
 * its length is at least two, and
 * the sum of the elements of the subarray is a multiple of k.
 *
 *
 * Note that:
 *
 *
 * A subarray is a contiguous part of the array.
 * An integer x is a multiple of k if there exists an integer n such that x = n
 * * k. 0 is always a multiple of k.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [23,2,4,6,7], k = 6
 * Output: true
 * Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up
 * to 6.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [23,2,6,4,7], k = 6
 * Output: true
 * Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose
 * elements sum up to 42.
 * 42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [23,2,6,4,7], k = 13
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
 * 0 <= sum(nums[i]) <= 2^31 - 1
 * 1 <= k <= 2^31 - 1
 *
 *
 */

/*

want to find out if the vec has a subarray that the sum of the subarray is a multiple of k
to figure out if it's a multiple of k or not, we can take the modulo of the prefix sums

 0  1  2  3  4
23  2  4  6  6
23 25 29 35 41

1 0
1 1

1 2 12
1 3 15

0 1 2
2 4 3
2 6 9

*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        // case 1: the length of nums is too short
        if (nums.size() < 2)
        {
            return false;
        }

        // calculate prefix sums
        vector<long long> res(nums.begin(), nums.end());
        for (size_t i = 1; i < res.size(); i++)
        {
            res[i] += res[i - 1];
        }
        for (size_t i = 0; i < res.size(); i++)
        {
            res[i] %= k;
        }

        unordered_map<long long, size_t> m;
        m[0] = -1;
        for (size_t i = 0; i < res.size(); i++)
        {
            if (m.count(res[i]) and i - m[res[i]] > 1)
            {
                return true;
            }
            else if (!m.count(res[i]))
            {
                m[res[i]] = i;
            }
        }

        return false;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<int> v1{23, 2, 4, 6, 7};
    vector<int> v2{23, 2, 6, 4, 7};
    vector<int> v3{23, 2, 6, 4, 7};
    vector<int> v4{23, 2, 4, 6, 6};
    vector<int> v5{1, 0};
    vector<int> v6{1, 2, 12};
    vector<int> v7{2, 4, 3};
    vector<int> v8{0, 1, 0, 3, 0, 4, 0, 4, 0};

    bool o1 = obj.checkSubarraySum(v1, 6);  // T
    boolPrint(o1);
    bool o2 = obj.checkSubarraySum(v2, 6);  // T
    boolPrint(o2);
    bool o4 = obj.checkSubarraySum(v4, 12);  // T
    boolPrint(o4);
    bool o7 = obj.checkSubarraySum(v7, 6);  // T
    boolPrint(o7);
    bool o3 = obj.checkSubarraySum(v3, 13);  // F
    boolPrint(o3);
    bool o5 = obj.checkSubarraySum(v5, 2);  // F
    boolPrint(o5);
    bool o6 = obj.checkSubarraySum(v6, 6);  // F
    boolPrint(o6);
    bool o8 = obj.checkSubarraySum(v8, 5);  // F
    boolPrint(o8);
    return 0;
}
