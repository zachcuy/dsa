/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> m;

        for (auto& c : s)
        {
            m[c]++;
        }

        for (auto& c : t)
        {
            m[c]--;
        }

        for (auto& [key, val] : m)
        {
            if (val)
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
