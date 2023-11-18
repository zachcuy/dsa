/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (69.38%)
 * Likes:    7857
 * Dislikes: 207
 * Total Accepted:    816.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * chosen from the range [1, n].
 *
 * You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4, k = 2
 * Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
 * Explanation: There are 4 choose 2 = 6 total combinations.
 * Note that combinations are unordered, i.e., [1,2] and [2,1] are considered
 * to be the same combination.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1, k = 1
 * Output: [[1]]
 * Explanation: There is 1 choose 1 = 1 total combination.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 20
 * 1 <= k <= n
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    void combos(int index, vector<vector<int>>& res, vector<int>& tmp, int n, int k)
    {
        if (tmp.size() == k)
        {
            res.push_back(tmp);
            return;
        }
        if (index > n)
        {
            return;
        }

        for (size_t i = index; i <= n; i++)
        {
            // include current number
            tmp.push_back(i);
            combos(i + 1, res, tmp, n, k);

            // exclude current number
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        // data variables
        vector<vector<int>> res;
        vector<int> tmp;

        // generate subsets
        combos(1, res, tmp, n, k);

        return res;
    }
};
// @lc code=end

int main()
{
    Solution obj;

    int n1 = 4, k1 = 2;
    // int n2 = 1, k2 = 1;

    obj.combine(n1, k1);
    // obj.combine(n2, k2);
}