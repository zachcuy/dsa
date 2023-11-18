/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (76.22%)
 * Likes:    16127
 * Dislikes: 238
 * Total Accepted:    1.6M
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of unique elements, return all possible subsets
 * (the power set).
 *
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0]
 * Output: [[],[0]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    void calcSubset(vector<int>& A, vector<vector<int>>& res, vector<int>& subset, int index)
    {
        // Add the current subset to the result list
        res.push_back(subset);
        vecPrint2D(res);

        // Generate subsets by recursively including and
        // excluding elements
        for (int i = index; i < A.size(); i++)
        {
            // Include the current element in the subset
            subset.push_back(A[i]);

            // Recursively generate subsets with the current
            // element included
            calcSubset(A, res, subset, i + 1);

            // Exclude the current element from the subset
            // (backtracking)
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& A)
    {
        vector<int> subset;
        vector<vector<int>> res;
        calcSubset(A, res, subset, 0);
        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<int> v1{1, 2, 3};
    vector<int> v2{0};

    vector<vector<int>> o1 = obj.subsets(v1);
    // vecPrint2D(o1);

    // vector<vector<int>> o2 = obj.subsets(v2);
    // vecPrint2D(o2);

    return 0;
}
