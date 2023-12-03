/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (53.54%)
 * Likes:    19206
 * Dislikes: 363
 * Total Accepted:    1.4M
 * Total Submissions: 2.6M
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an integer array nums, return the length of the longest strictly
 * increasing subsequence.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,0,3,2,3]
 * Output: 4
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 * Follow up: Can you come up with an algorithm that runs in O(n log(n)) time
 * complexity?
 *
 */

/*

maintain another vector and perform bin search on it.

we replace the values in that vector with the values we encounter in the original array
if the vector is empty or the current element is the largest we've seen, then we append the element

*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    void bs(vector<int> &v, int val)
    {
        if (val < v[0])  // smallest encountered so far
        {
            v[0] = val;
        }
        else if (val > v[v.size() - 1])  // largest encountered so far
        {
            v.push_back(val);
        }
        else
        {
            // val should replace an element in the middle
            int L = 0;
            int R = v.size() - 1;
            while (L <= R)
            {
                int mid = (L + R) / 2;
                if (val < v[mid])
                {
                    R = mid - 1;
                }
                else if (val > v[mid])
                {
                    L = mid + 1;
                }
                else
                {
                    break;  // we already have the element in the vec so we do nothing
                }
            }
            if (v[L] > val)
            {
                v[L] = val;
            }
            else if (v[R] < val)
            {
                v[R] = val;
            }
        }
    }
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> sorted_vec{nums[0]};
        for (int i = 1; i < nums.size(); ++i)
        {
            bs(sorted_vec, nums[i]);
        }

        return sorted_vec.size();
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution obj;

    vector<int> v1{10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> v2{0, 1, 0, 3, 2, 3};
    vector<int> v3{7, 7, 7, 7, 7, 7, 7};

    cout << obj.lengthOfLIS(v1) << "\n\n";
    cout << obj.lengthOfLIS(v2) << "\n\n";
    cout << obj.lengthOfLIS(v3) << "\n\n";

    return 0;
}
