/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (71.69%)
 * Likes:    5407
 * Dislikes: 2216
 * Total Accepted:    962.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two integer arrays nums1 and nums2, return an array of their
 * intersection. Each element in the result must be unique and you may return
 * the result in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * Explanation: [4,9] is also accepted.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> m1;
        unordered_set<int> m2;

        for (int i = 0; i < nums1.size(); ++i)
        {
            m1.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); ++i)
        {
            m2.insert(nums2[i]);
        }

        vector<int> res;
        for (auto& key : m1)
        {
            if (m2.count(key))
            {
                res.push_back(key);
            }
        }

        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{1, 2, 2, 1};
    vector<int> v2{2, 2};

    dump(obj.intersection(v2, v1));
    return 0;
}