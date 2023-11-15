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

/*

rule 1 means that we can freely reorder the string, so letter position doesn't actually matter
rule 2 means that we care about the frequencies of a letter and if the letters are the same
-> this means that we cannot have one string that has a unique letter!

easy edge case: strings must have the same length

use two maps to count the frequencies of each letter on each string, each frequency must be present
in the other map

in: cabbba, abbccc

aabbbc
abbccc

a: 2
b: 3
c: 1

a: 1
b: 2
c: 3

in: uau, ssx

auu
xss

a: 1
u: 2

s: 2
x: 1

use a third map to keep track of how often each frequency occurs
automatically return false if we have a letter that only appears in one string but not the other

*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.size() != word2.size())
        {
            return false;
        }

        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        for (auto& i : word1)
        {
            m1[i]++;
        }
        for (auto& i : word2)
        {
            m2[i]++;
        }

        unordered_map<int, int> m3;
        for (auto& p : m1)
        {
            m3[p.second]++;
            if (!m2.count(p.first))
            {
                return false;
            }
        }
        for (auto& p : m2)
        {
            m3[p.second]--;
            if (!m1.count(p.first))
            {
                return false;
            }
        }

        for (auto& p : m3)
        {
            if (p.second)
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

int main()
{
    Solution obj;

    string a1 = "abc";
    string b1 = "bca";

    string a2 = "a";
    string b2 = "aa";

    string a3 = "cabbba";
    string b3 = "abbccc";

    string a4 = "uau";
    string b4 = "ssx";

    string a5 = "abbzzca";
    string b5 = "babzzcz";

    cout << obj.closeStrings(a1, b1) << "\n";  // true
    cout << obj.closeStrings(a2, b2) << "\n";  // false
    cout << obj.closeStrings(a3, b3) << "\n";  // true
    cout << obj.closeStrings(a4, b4) << "\n";  // false
    cout << obj.closeStrings(a5, b5) << "\n";  // false
}