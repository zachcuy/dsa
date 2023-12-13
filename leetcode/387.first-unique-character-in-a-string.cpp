/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (60.16%)
 * Likes:    8359
 * Dislikes: 270
 * Total Accepted:    1.5M
 * Total Submissions: 2.5M
 * Testcase Example:  '"leetcode"'
 *
 * Given a string s, find the first non-repeating character in it and return
 * its index. If it does not exist, return -1.
 *
 *
 * Example 1:
 * Input: s = "leetcode"
 * Output: 0
 * Example 2:
 * Input: s = "loveleetcode"
 * Output: 2
 * Example 3:
 * Input: s = "aabb"
 * Output: -1
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of only lowercase English letters.
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int firstUniqChar(string s)
    {
        // use map to get frequencies
        unordered_map<char, pair<int, int>> freq;

        for (int i = 0; i < s.size(); ++i)
        {
            char letter = s[i];
            if (!freq.count(letter))
            {
                freq[letter].second = i;
            }
            freq[letter].first++;
        }

        // get first occurrence
        int index_of_earliest = INT_MAX;

        for (auto [key, p] : freq)
        {
            auto [count, index] = p;

            if (count == 1 and index < index_of_earliest)
            {
                index_of_earliest = index;
            }
        }

        if (index_of_earliest == INT_MAX)
        {
            return -1;
        }
        return index_of_earliest;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    string s1{"loveleetcode"};
    dump(obj.firstUniqChar(s1));
    return 0;
}