/*
 * @lc app=leetcode id=2299 lang=cpp
 *
 * [2299] Strong Password Checker II
 *
 * https://leetcode.com/problems/strong-password-checker-ii/description/
 *
 * algorithms
 * Easy (55.13%)
 * Likes:    324
 * Dislikes: 38
 * Total Accepted:    36.8K
 * Total Submissions: 67K
 * Testcase Example:  '"IloveLe3tcode!"'
 *
 * A password is said to be strong if it satisfies all the following
 * criteria:
 *
 *
 * It has at least 8 characters.
 * It contains at least one lowercase letter.
 * It contains at least one uppercase letter.
 * It contains at least one digit.
 * It contains at least one special character. The special characters are the
 * characters in the following string: "!@#$%^&*()-+".
 * It does not contain 2 of the same character in adjacent positions (i.e.,
 * "aab" violates this condition, but "aba" does not).
 *
 *
 * Given a string password, return true if it is a strong password. Otherwise,
 * return false.
 *
 *
 * Example 1:
 *
 *
 * Input: password = "IloveLe3tcode!"
 * Output: true
 * Explanation: The password meets all the requirements. Therefore, we return
 * true.
 *
 *
 * Example 2:
 *
 *
 * Input: password = "Me+You--IsMyDream"
 * Output: false
 * Explanation: The password does not contain a digit and also contains 2 of
 * the same character in adjacent positions. Therefore, we return false.
 *
 *
 * Example 3:
 *
 *
 * Input: password = "1aB!"
 * Output: false
 * Explanation: The password does not meet the length requirement. Therefore,
 * we return false.
 *
 *
 * Constraints:
 *
 *
 * 1 <= password.length <= 100
 * password consists of letters, digits, and special characters:
 * "!@#$%^&*()-+".
 *
 *
 */

/*

*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    bool strongPasswordCheckerII(string password)
    {
        int upper = 0;
        int lower = 0;
        int digit = 0;
        int special = 0;
        int len = password.size();

        for (int i = 0; i < password.size(); ++i)
        {
            char letter = password[i];
            if (isupper(letter))
            {
                upper = 1;
            }
            if (islower(letter))
            {
                lower = 1;
            }
            if (isdigit(letter))
            {
                digit = 1;
            }
            if (ispunct(letter))
            {
                special = 1;
            }
            if (i > 0 and password[i] == password[i - 1])
            {
                return false;
            }
        }

        if (upper and lower and digit and special and len >= 8)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution obj;
    string s1 = "IloveLe3tcode!";
    string s2 = "Me+You--IsMyDream";
    string s3 = "1aB!";
    string s4 = "j1A!A!A!";

    // dump(obj.strongPasswordCheckerII(s1));
    // dump(obj.strongPasswordCheckerII(s2));
    // dump(obj.strongPasswordCheckerII(s3));
    dump(obj.strongPasswordCheckerII(s4));  // T
    return 0;
}