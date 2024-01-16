/*
 * @lc app=leetcode id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    // int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
    // {
    //     int n = nums1.size();
    //     int m = nums2.size();

    //     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    //     for (int i = 1; i <= n; ++i)
    //     {
    //         for (int j = 1; j <= m; ++j)
    //         {
    //             if (nums1[i - 1] == nums2[j - 1])
    //             {
    //                 dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
    //             }
    //             else
    //             {
    //                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //             }
    //         }
    //     }

    //     return dp[n][m];
    // }
    // Space Optimized AC
    int maxUncrossedLines(const vector<int>& nums1, const vector<int>& nums2)
    {
        const int n = nums1.size();
        const int m = nums2.size();

        vector<int> a(m + 1, 0);
        vector<int> b(m + 1, 0);

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    b[j] = 1 + min({a[j], b[j - 1], a[j - 1]});
                }
                else
                {
                    b[j] = max(a[j], b[j - 1]);
                }
            }
            a = b;
        }

        return b[m];
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<int> v1{1, 4, 2};
    vector<int> v2{1, 2, 4};
    dump(obj.maxUncrossedLines(v1, v2));

    vector<int> v3{2, 5, 1, 2, 5};
    vector<int> v4{10, 5, 2, 1, 5, 2};
    dump(obj.maxUncrossedLines(v3, v4));

    vector<int> v5{1, 3, 7, 1, 7, 5};
    vector<int> v6{1, 9, 2, 5, 1};
    dump(obj.maxUncrossedLines(v5, v6));

    vector<int> v7{4, 4, 4, 2, 4, 1, 4, 3, 2, 4, 4, 2, 2, 2, 5, 2, 5, 4, 5, 1};
    vector<int> v8{2, 1, 5, 4, 2, 3, 5, 1, 2, 2};
    dump(obj.maxUncrossedLines(v7, v8));

    return 0;
}