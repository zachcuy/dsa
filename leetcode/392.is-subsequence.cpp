/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 *
 * https://leetcode.com/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (48.00%)
 * Likes:    9004
 * Dislikes: 480
 * Total Accepted:    1.2M
 * Total Submissions: 2.4M
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * Given two strings s and t, return true if s is a subsequence of t, or false
 * otherwise.
 *
 * A subsequence of a string is a new string that is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (i.e., "ace" is a
 * subsequence of "abcde" while "aec" is not).
 *
 *
 * Example 1:
 * Input: s = "abc", t = "ahbgdc"
 * Output: true
 * Example 2:
 * Input: s = "axc", t = "ahbgdc"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 100
 * 0 <= t.length <= 10^4
 * s and t consist only of lowercase English letters.
 *
 *
 *
 * Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k
 * >= 10^9, and you want to check one by one to see if t has its subsequence.
 * In this scenario, how would you change your code?
 */

/*

use two pointers
start at beginning, if we find the letter in s in t, then we increment s and t
otherwise, we increment only t

*/

#include "includes.h"
// @lc code=start
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (!s.size())
        {
            return true;
        }
        else if (s.size() and !t.size())
        {
            return false;
        }

        int a = 0;
        int b = 0;

        while (a < s.size() and b < t.size())
        {
            if (s[a] == t[b])
            {
                a++;
                b++;
            }
            else
            {
                b++;
            }
        }

        return a == s.size();
    }
};
// @lc code=end

int main()
{
    Solution o;
    std::string a = "axc";
    std::string b = "ahbgdc";

    std::cout << o.isSubsequence(a, b) << "\n";
}