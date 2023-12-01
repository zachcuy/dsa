/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (77.30%)
 * Likes:    18203
 * Dislikes: 294
 * Total Accepted:    1.9M
 * Total Submissions: 2.4M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    void bt(vector<int> nums, vector<vector<int>>& res, vector<int>& sub)
    {
        // base case: no more numbers left
        if (!nums.size())
        {
            res.push_back(sub);
            return;
        }

        // go through the remaining numbers
        for (size_t i = 0; i < nums.size(); i++)
        {
            vector<int> tmp = nums;

            // use current as starting point
            sub.push_back(tmp[i]);
            tmp.erase(tmp.begin() + i);
            bt(tmp, res, sub);

            // move to next
            sub.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> sub;

        bt(nums, res, sub);
        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<int> v1{1, 2, 3};
    vector<int> v2{0, 1};
    vector<int> v3{1};

    obj.permute(v1);
    obj.permute(v2);
    obj.permute(v3);

    return 0;
}
