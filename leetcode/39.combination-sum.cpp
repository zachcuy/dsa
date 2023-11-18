/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (70.05%)
 * Likes:    17843
 * Dislikes: 366
 * Total Accepted:    1.7M
 * Total Submissions: 2.4M
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates where the chosen
 * numbers sum to target. You may return the combinations in any order.
 *
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen
 * numbers is different.
 *
 * The test cases are generated such that the number of unique combinations
 * that sum up to target is less than 150 combinations for the given input.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
 * times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 *
 *
 * Example 3:
 *
 *
 * Input: candidates = [2], target = 1
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= candidates.length <= 30
 * 2 <= candidates[i] <= 40
 * All elements of candidates are distinct.
 * 1 <= target <= 40
 *
 *
 */
/*

in: vec<int>, int
out: vec<vec<int>>

create combinations from input vector with replacement
the combinations must add up to target


*/

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    void generate(vector<int> candidates, vector<vector<int>>& res, vector<int>& tmp, int target,
                  int idx)
    {
        // base case 1: target reached
        if (target == 0)
        {
            res.push_back(tmp);
            return;
        }
        // base case 2: out of bounds, or target is negative
        if (target < 0 or idx >= candidates.size())
        {
            return;
        }

        // include current
        tmp.push_back(candidates[idx]);
        generate(candidates, res, tmp, target - candidates[idx], idx);

        // don't include current and move forward
        tmp.pop_back();
        generate(candidates, res, tmp, target, idx + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> tmp;

        generate(candidates, res, tmp, target, 0);
        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<int> v1{2, 3, 6, 7};
    int t1 = 7;

    vector<int> v2{2, 3, 5};
    int t2 = 8;

    vector<int> v3{2};
    int t3 = 1;

    obj.combinationSum(v1, t1);  // [[2,2,3],[7]]
    obj.combinationSum(v2, t2);  // [[2,2,2,2],[2,3,3],[3,5]]
    obj.combinationSum(v3, t3);  // []
    return 0;
}
