/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (53.77%)
 * Likes:    9833
 * Dislikes: 258
 * Total Accepted:    857.5K
 * Total Submissions: 1.6M
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note: The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    void bt(vector<int>& nums, vector<vector<int>>& res, vector<int> sub, int target,
            set<vector<int>>& s)
    {
        if (target == 0)
        {
            sort(sub.begin(), sub.end());
            if (!s.count(sub))
            {
                s.insert(sub);
                res.push_back(sub);
            }
            return;
        }
        if (target < 0)
        {
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            // include
            sub.push_back(nums[i]);
            bt(nums, res, sub, target - nums[i], s);

            // exclude
            sub.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> sub;
        set<vector<int>> s;

        bt(candidates, res, sub, target, s);
        vecPrint2D(res);
        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    // vector<int> v1{10, 1, 2, 7, 6, 1, 5};
    vector<int> v1{5, 1, 3, 2};
    // vector<int> v2{2, 5, 2, 1, 2};

    obj.combinationSum2(v1, 8);
    // obj.combinationSum2(v2, 5);

    return 0;
}
