/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

/*
    min path sum on a triangle

    base case:
        value at first cell dp[0] = vec[0][0]

    general case:
        dp[i] = min(dp[i-1][j] + curCell, dp[i-1][j-1] + curCell)
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int minimumTotal(vector<vector<int>>& triangle)
    {
        vector<vector<int>> dp;

        for (auto& row : triangle)
        {
            vector<int> tmp;
            for (auto& cell : row)
            {
                tmp.push_back(INT_MAX);
            }
            dp.push_back(tmp);
        }

        dp[0][0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i)
        {
            for (int j = 0; j < triangle[i].size(); ++j)
            {
                int curCell = triangle[i][j];
                if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j] + curCell;
                }
                else if (j == triangle[i].size() - 1)
                {
                    dp[i][j] = dp[i - 1][j - 1] + curCell;
                }
                else
                {
                    dp[i][j] = min({dp[i - 1][j], dp[i - 1][j - 1]}) + curCell;
                }
            }
        }

        return *min_element(dp[dp.size() - 1].begin(), dp[dp.size() - 1].end());
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<vector<int>> triangle1{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    vector<vector<int>> triangle2{{-10}};

    dump(obj.minimumTotal(triangle1));
    dump(obj.minimumTotal(triangle2));
    return 0;
}