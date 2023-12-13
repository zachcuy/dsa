/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (77.27%)
 * Likes:    8075
 * Dislikes: 1140
 * Total Accepted:    2.3M
 * Total Submissions: 3M
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * Write a function that reverses a string. The input string is given as an
 * array of characters s.
 *
 * You must do this by modifying the input array in-place with O(1) extra
 * memory.
 *
 *
 * Example 1:
 * Input: s = ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * Example 2:
 * Input: s = ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] is a printable ascii character.
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    void reverseString(vector<char>& s)
    {
        int l = 0;
        int r = s.size() - 1;

        while (l <= r)
        {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<char> v1{'h', 'e', 'l', 'l', 'o'};
    obj.reverseString(v1);
    dump(v1);

    vector<char> v2{'H', 'a', 'n', 'n', 'a', 'h'};
    obj.reverseString(v2);
    dump(v2);
    return 0;
}