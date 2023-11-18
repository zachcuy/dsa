/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (56.56%)
 * Likes:    9208
 * Dislikes: 261
 * Total Accepted:    812.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,2]'
 *
 * Given an integer array nums that may contain duplicates, return all possible
 * subsets (the power set).
 *
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 *
 *
 * Example 1:
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    void generate(vector<int>& nums, vector<vector<int>>& res, vector<int>& tmp, int index,
                  set<vector<int>>& s)
    {
        // add tmp to result
        res.push_back(tmp);

        // loop to generate other subsets
        for (size_t i = index; i < nums.size(); i++)
        {
            // include current value
            tmp.push_back(nums[i]);

            // build subsets of current subset
            if (!s.count(tmp))
            {
                s.insert(tmp);
                generate(nums, res, tmp, i + 1, s);
            }

            // exclude current value
            tmp.pop_back();
        }

        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        // data variables
        vector<vector<int>> res;
        vector<int> tmp;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());

        // build subsets
        generate(nums, res, tmp, 0, s);

        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<int> v1{1, 2, 2};
    vector<int> v2{0};
    vector<int> v3{0, 0, 0};
    vector<int> v4{1, 1, 2, 2};
    vector<int> v5{4, 4, 4, 1, 4};

    // obj.subsetsWithDup(v1);
    // obj.subsetsWithDup(v2);
    // obj.subsetsWithDup(v3);
    // obj.subsetsWithDup(v4);
    obj.subsetsWithDup(
        v5);  // [[],[1],[1,4],[1,4,4],[1,4,4,4],[1,4,4,4,4],[4],[4,4],[4,4,4],[4,4,4,4]]

    return 0;
}
