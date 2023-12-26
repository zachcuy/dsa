/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 *
 * https://leetcode.com/problems/longest-common-subsequence/description/
 *
 * algorithms
 * Medium (57.64%)
 * Likes:    12527
 * Dislikes: 161
 * Total Accepted:    861.4K
 * Total Submissions: 1.5M
 * Testcase Example:  '"abcde"\n"ace"'
 *
 * Given two strings text1 and text2, return the length of their longest common
 * subsequence. If there is no common subsequence, return 0.
 *
 * A subsequence of a string is a new string generated from the original string
 * with some characters (can be none) deleted without changing the relative
 * order of the remaining characters.
 *
 *
 * For example, "ace" is a subsequence of "abcde".
 *
 *
 * A common subsequence of two strings is a subsequence that is common to both
 * strings.
 *
 *
 * Example 1:
 *
 *
 * Input: text1 = "abcde", text2 = "ace"
 * Output: 3
 * Explanation: The longest common subsequence is "ace" and its length is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: text1 = "abc", text2 = "abc"
 * Output: 3
 * Explanation: The longest common subsequence is "abc" and its length is 3.
 *
 *
 * Example 3:
 *
 *
 * Input: text1 = "abc", text2 = "def"
 * Output: 0
 * Explanation: There is no such common subsequence, so the result is 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= text1.length, text2.length <= 1000
 * text1 and text2 consist of only lowercase English characters.
 *
 *
 */

/*

    input: 2 strings
    goal: find the length of the longest common subsequence

    we can delete characters from either string, so that means we might need delete characters from
    the first string only, from the second string only, both, or none.

    so we need to be able to "skip" or delete from either the first string or the second string or
   both

   we can build the combinations for all characters but that will take too long
   what if we build the string, taking letters from the left to the right of each string

   that way, we can end a path earlier if we have a difference between characters?
   the largest it can be is the shorter of either s1 or s2

   hwoever, we still need to go through both of them...

   I feel like we need to memoize both strings' status.

*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // TOP DOWN (recursion + memoization DP)
    // int dp(string& s1, string& s2, int idx, int jdx, vector<vector<int>>& m, int& len1, int&
    // len2)
    // {
    //     if (idx >= len1 or jdx >= len2)
    //     {
    //         return 0;
    //     }

    //     if (m[idx][jdx] != -1)
    //     {
    //         return m[idx][jdx];
    //     }

    //     if (idx < len1 and jdx < len2 and s1[idx] == s2[jdx])
    //     {
    //         // keep both so we just move on
    //         return m[idx][jdx] = 1 + dp(s1, s2, idx + 1, jdx + 1, m, len1, len2);
    //     }
    //     else
    //     {
    //         // case 1: increment only s1
    //         // case 2: increment only s2
    //         return m[idx][jdx] = max(dp(s1, s2, idx + 1, jdx, m, len1, len2),
    //                                  dp(s1, s2, idx, jdx + 1, m, len1, len2));
    //     }
    // }
    // int longestCommonSubsequence(string& text1, string& text2)
    // {
    //     int len1 = text1.size();
    //     int len2 = text2.size();
    //     vector<vector<int>> memo(len1 + 1, vector<int>(len2 + 1, -1));
    //     int ans = dp(text1, text2, 0, 0, memo, len1, len2);
    //     return ans;
    // }

    // BOTTOM UP (tabulated DP)
    // int longestCommonSubsequence(string& text1, string& text2)
    // {
    //     vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

    //     for (int i = 1; i <= text1.size(); ++i)
    //     {
    //         for (int j = 1; j <= text2.size(); ++j)
    //         {
    //             if (text1[i - 1] == text2[j - 1])
    //             {
    //                 dp[i][j] = 1 + dp[i - 1][j - 1];
    //             }
    //             else
    //             {
    //                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //             }
    //         }
    //     }

    //     return dp[text1.size()][text2.size()];
    // }

    // BOTTOM UP (tabulated DP) : SPACE OPTIMIZED
    int longestCommonSubsequence(string& text1, string& text2)
    {
        vector<int> v1(text2.size() + 1, 0);
        vector<int> v2(text2.size() + 1, 0);

        for (int i = 1; i <= text1.size(); ++i)
        {
            for (int j = 1; j <= text2.size(); ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    v2[j] = 1 + v1[j - 1];
                }
                else
                {
                    v2[j] = max(v1[j], v2[j - 1]);
                }
            }
            v1 = v2;
        }

        return v2[text2.size()];
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    string a1 = "abcde";
    string a2 = "abc";

    string b1 = "abc";
    string b2 = "abc";

    string c1 = "abc";
    string c2 = "def";

    string d1 = "abc";
    string d2 = "abcde";

    string e1 = "abcde";
    string e2 = "ae";

    string f1 = "ae";
    string f2 = "abcde";

    string g1 = "bsbininm";
    string g2 = "jmjkbkjkv";

    dump(obj.longestCommonSubsequence(a1, a2));  // 3
    dump(obj.longestCommonSubsequence(b1, b2));  // 3
    dump(obj.longestCommonSubsequence(c1, c2));  // 0
    dump(obj.longestCommonSubsequence(d1, d2));  // 3
    dump(obj.longestCommonSubsequence(e1, e2));  // 2
    dump(obj.longestCommonSubsequence(f1, f2));  // 2
    dump(obj.longestCommonSubsequence(g1, g2));  // 1
    return 0;
}