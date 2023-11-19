/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (44.17%)
 * Likes:    10821
 * Dislikes: 359
 * Total Accepted:    754.9K
 * Total Submissions: 1.7M
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 * or false otherwise.
 *
 * In other words, return true if one of s1's permutations is the substring of
 * s2.
 *
 *
 * Example 1:
 *
 *
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 *
 *
 * Example 2:
 *
 *
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s1.length, s2.length <= 10^4
 * s1 and s2 consist of lowercase English letters.
 *
 *
 */

/*

in: two strings
out: bool : true if s1 is a permutation of s2
quick edge case: len(s1) > len(s2)

sliding window approach is good because s2 needs to have the letters in s1 to be contiguous
use map to keep track of letter frequency of s1

at each window, check the letter frequency of subset(s2)
if they are all the same, then it's a permutation, so we return true

0 1 2 3 4
a b c d e   // 4
a b         // 2

0 1 2 3
d c d a
a d c

4 - 3 + 1 = 2

*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    bool checkMapEquality(unordered_map<char, int> m1, unordered_map<char, int> m2)
    {
        for (auto& p : m1)
        {
            m2[p.first] -= p.second;
        }

        for (auto& p : m2)
        {
            if (p.second != 0)
            {
                return false;
            }
        }

        return true;
    }
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
        {
            return false;
        }

        unordered_map<char, int> m;
        for (auto& el : s1)
        {
            m[el]++;
        }

        // go through main string and keep track of letter freqs
        size_t ptr = 0;

        // map to keep track of letters of main string
        unordered_map<char, int> sub;

        while (ptr < s2.size())
        {
            sub[s2[ptr]]++;
            if (ptr >= s1.size())
            {
                sub[s2[ptr - s1.size()]]--;
            }
            if (checkMapEquality(m, sub))
            {
                return true;
            }
            ptr++;
        }

        return false;
    }
};
// @lc code=end

int main()
{
    //
    Solution obj;

    string a1{"ab"};
    string b1{"eidbaooo"};

    string a2{"ab"};
    string b2{"eidboaoo"};

    string a3{"hello"};
    string b3{"ooolleoooleh"};

    string a4{"adc"};
    string b4{"dcda"};

    string a5{"ccc"};
    string b5{"cbac"};

    boolPrint(obj.checkInclusion(a1, b1));  // T
    boolPrint(obj.checkInclusion(a2, b2));  // F
    boolPrint(obj.checkInclusion(a3, b3));  // F
    boolPrint(obj.checkInclusion(a4, b4));  // T
    boolPrint(obj.checkInclusion(a5, b5));  // F
    return 0;
}