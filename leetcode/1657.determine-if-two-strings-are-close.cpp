/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 *
 * https://leetcode.com/problems/determine-if-two-strings-are-close/description/
 *
 * algorithms
 * Medium (54.03%)
 * Likes:    2707
 * Dislikes: 156
 * Total Accepted:    159.2K
 * Total Submissions: 296.3K
 * Testcase Example:  '"abc"\n"bca"'
 *
 * Two strings are considered close if you can attain one from the other using
 * the following operations:
 *
 *
 * Operation 1: Swap any two existing characters.
 *
 *
 * For example, abcde -> aecdb
 *
 *
 * Operation 2: Transform every occurrence of one existing character into
 * another existing character, and do the same with the other
 * character.
 *
 * For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into
 * a's)
 *
 *
 *
 *
 * You can use the operations on either string as many times as necessary.
 *
 * Given two strings, word1 and word2, return true if word1 and word2 are
 * close, and false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: word1 = "abc", word2 = "bca"
 * Output: true
 * Explanation: You can attain word2 from word1 in 2 operations.
 * Apply Operation 1: "abc" -> "acb"
 * Apply Operation 1: "acb" -> "bca"
 *
 *
 * Example 2:
 *
 *
 * Input: word1 = "a", word2 = "aa"
 * Output: false
 * Explanation: It is impossible to attain word2 from word1, or vice versa, in
 * any number of operations.
 *
 *
 * Example 3:
 *
 *
 * Input: word1 = "cabbba", word2 = "abbccc"
 * Output: true
 * Explanation: You can attain word2 from word1 in 3 operations.
 * Apply Operation 1: "cabbba" -> "caabbb"
 * Apply Operation 2: "caabbb" -> "baaccc"
 * Apply Operation 2: "baaccc" -> "abbccc"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word1.length, word2.length <= 10^5
 * word1 and word2 contain only lowercase English letters.
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    bool closeStrings(string word1, string word2)
    {
        unordered_map<char, int> freq1;
        for (const auto& c : word1)
        {
            freq1[c]++;
        }

        unordered_map<char, int> freq2;
        for (const auto& c : word2)
        {
            freq2[c]++;
        }

        unordered_map<int, int> inverse_freq1;
        for (const auto& [c, freq] : freq1)
        {
            inverse_freq1[freq]++;
        }

        for (const auto& [c, freq] : freq2)
        {
            if (!inverse_freq1[freq])
            {
                return false;
            }
            else
            {
                inverse_freq1[freq]--;
            }
        }

        return true;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    string a1{"abc"};
    string a2{"bca"};

    string b1{"a"};
    string b2{"aa"};

    string c1{"cabbba"};
    string c2{"abbccc"};

    string d1{"uau"};
    string d2{"ssx"};

    dump(obj.closeStrings(a1, a2));  // t
    dump(obj.closeStrings(b1, b2));  // f
    dump(obj.closeStrings(c1, c2));  // t
    dump(obj.closeStrings(d1, d2));  // f
    return 0;
}