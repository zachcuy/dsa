/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (45.79%)
 * Likes:    8572
 * Dislikes: 8062
 * Total Accepted:    2.5M
 * Total Submissions: 5.4M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * A phrase is a palindrome if, after converting all uppercase letters into
 * lowercase letters and removing all non-alphanumeric characters, it reads the
 * same forward and backward. Alphanumeric characters include letters and
 * numbers.
 *
 * Given a string s, return true if it is a palindrome, or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 *
 *
 * Example 3:
 *
 *
 * Input: s = " "
 * Output: true
 * Explanation: s is an empty string "" after removing non-alphanumeric
 * characters.
 * Since an empty string reads the same forward and backward, it is a
 * palindrome.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 2 * 10^5
 * s consists only of printable ASCII characters.
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.size() - 1;

        while (l < r)
        {
            // conversions
            char left = tolower(s[l]);
            char right = tolower(s[r]);

            if (!isalnum(left))
            {
                l++;
                continue;
            }
            if (!isalnum(right))
            {
                r--;
                continue;
            }
            if (left != right)
            {
                return false;
            }
            else
            {
                l++;
                r--;
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution obj;
    string s1{"A man, a plan, a canal: Panama"};
    string s2{"race a car"};
    string s3{" "};

    dump(obj.isPalindrome(s1));
    dump(obj.isPalindrome(s2));
    dump(obj.isPalindrome(s3));
    return 0;
}