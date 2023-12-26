/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

/*
    we have two targets and we have a vector of strings that have a number of 1's and 0's

    the targets are the limits for the number of 1's and 0's in each string
    we want use as many of those strings as possible

    2d dp with min/max to reach target
    we max out the number of strings we use
    limited by the m and n

    first, create a map of the string to counts

    then do 2d dp
    we do:
        for (0 : m) ->
            for (0 : n) ->
                for (str : strings) ->
                    if (num1 + dp[m-1][n] <= m and num0 + dp[m][n-1] <= n) ->
                        dp[m][n] = 1 + max(dp[m-1][n], d[m][n-1])
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int dp[601][101][101];
    // AC
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        memset(dp, -1, sizeof(dp));

        return solve(0, m, n, strs.size(), strs);
    }
    int solve(int start, int m, int n, int size, vector<string>& strs)
    {
        if (start >= size || m < 0 || n < 0) return 0;
        if (m == 0 && n == 0) return 0;
        if (dp[start][m][n] != -1) return dp[start][m][n];

        int i = start;
        int zeroes = count(strs[i].begin(), strs[i].end(), '0');
        int ones = strs[i].size() - zeroes;
        if (m >= zeroes && n >= ones)
            return dp[start][m][n] = max(1 + solve(i + 1, m - zeroes, n - ones, size, strs),
                                         solve(i + 1, m, n, size, strs));
        else
            return dp[start][m][n] = solve(i + 1, m, n, size, strs);
    }
    // int findMaxForm(vector<string>& strs, int m, int n)
    // {
    //     // count number of ones and zeros for each input string
    //     unordered_map<string, int> count1;
    //     unordered_map<string, int> count0;
    //     for (int i = 0; i < strs.size(); ++i)
    //     {
    //         for (int j = 0; j < strs[i].size(); ++j)
    //         {
    //             if (strs[i][j] == '0')
    //             {
    //                 count0[strs[i]]++;
    //             }
    //             else
    //             {
    //                 count1[strs[i]]++;
    //             }
    //         }
    //     }

    //     vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    //     set<int> ones;
    //     set<int> zeroes;
    //     for (int i = 1; i <= m; ++i)  // zeros
    //     {
    //         for (int j = 1; j <= n; ++j)  // ones
    //         {
    //             for (auto& str : strs)
    //             {
    //                 if (i - count0[str] >= 0 and j - count1[str] >= 0)
    //                 {
    //                     dp[i][j] =
    //                         max({dp[i][j], dp[i - count0[str]][j] + 1, dp[i][j - count1[str]] +
    //                         1});
    //                 }
    //             }
    //         }
    //     }

    //     return dp[m][n];
    // }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<string> s1{"10", "0001", "111001", "1", "0"};
    vector<string> s2{"10", "0", "1"};
    vector<string> s3{"0",     "11",   "1000", "01",   "0", "101",     "1", "1",  "1",  "0",
                      "0",     "0",    "0",    "1",    "0", "0110101", "0", "11", "01", "00",
                      "01111", "0011", "1",    "1000", "0", "11101",   "1", "0",  "10", "0111"};

    dump(obj.findMaxForm(s1, 5, 3));
    dump(obj.findMaxForm(s2, 1, 1));
    dump(obj.findMaxForm(s3, 9, 80));
    return 0;
}