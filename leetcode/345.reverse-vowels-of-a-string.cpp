/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (51.38%)
 * Likes:    4098
 * Dislikes: 2696
 * Total Accepted:    654.3K
 * Total Submissions: 1.3M
 * Testcase Example:  ''hello''
 *
 * Given a string s, reverse only all the vowels in the string and return it.
 *
 * The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both
 * lower and upper cases, more than once.
 *
 *
 * Example 1:
 * Input: s = 'hello'
 * Output: 'holle'
 * Example 2:
 * Input: s = 'leetcode'
 * Output: 'leotcede'
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s consist of printable ASCII characters.
 *
 *
 */

/*

can use two pointer at beginning to end, meet in middle

what about if there are an odd number of vowels?

assume there are an equal amount for initial attempt

cases:
both vowels, so we swap and increment
only one vowel, so we increment the other
both aren't vowels, so we increment both

*/
#include "includes.h"

// @lc code=start
class Solution
{
public:
    string reverseVowels(string s)
    {
        std::unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        int L = 0;
        int R = s.size() - 1;

        while (L < R)
        {
            if (vowels.count(s[L]) and vowels.count(s[R]))
            {
                // swap
                char tmp = s[L];
                s[L] = s[R];
                s[R] = tmp;

                // increment both
                L++;
                R--;
            }
            else if (vowels.count(s[L]) and !vowels.count(s[R]))
            {
                // increment R
                R--;
            }
            else if (!vowels.count(s[L]) and vowels.count(s[R]))
            {
                // increment L
                L++;
            }
            else
            {
                L++;
                R--;
            }
        }

        return s;
    }
};
// @lc code=end

int main()
{
    Solution obj;

    // std::string s = "Marge, let's \" went.\" I await news telegram.";
    std::string s = " apG0i4maAs::sA0m4i0Gp0";
    std::cout << obj.reverseVowels(s) << "\n";

    return 0;
}
