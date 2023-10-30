/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (63.34%)
 * Likes:    10856
 * Dislikes: 341
 * Total Accepted:    2.7M
 * Total Submissions: 4.3M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two std::strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 *
 *
 *
 * Follow up: What if the inputs contain Unicode characters? How would you
 * adapt your solution to such a case?
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        std::unordered_map<char, int> map;

        for (auto &i : s)
        {
            map[i]++;
        }

        for (auto &i : t)
        {
            map[i]--;
        }

        for (auto &i : map)
        {
            if (i.second != 0)
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

    obj.isAnagram("abcdefg", "hijklmnop");
    return 0;
}