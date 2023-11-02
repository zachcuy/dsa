/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of std::strings
 *
 * https://leetcode.com/problems/greatest-common-divisor-of-std::strings/description/
 *
 * algorithms
 * Easy (52.21%)
 * Likes:    4454
 * Dislikes: 976
 * Total Accepted:    289.4K
 * Total Submissions: 556.6K
 * Testcase Example:  '"ABCABC"\n"ABC"'
 *
 * For two std::strings s and t, we say "t divides s" if and only if s = t + ... + t
 * (i.e., t is concatenated with itself one or more times).
 *
 * Given two std::strings str1 and str2, return the largest std::string x such that x
 * divides both str1 and str2.
 *
 *
 * Example 1:
 *
 *
 * Input: str1 = "ABCABC", str2 = "ABC"
 * Output: "ABC"
 *
 *
 * Example 2:
 *
 *
 * Input: str1 = "ABABAB", str2 = "ABAB"
 * Output: "AB"
 *
 *
 * Example 3:
 *
 *
 * Input: str1 = "LEET", str2 = "CODE"
 * Output: ""
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= str1.length, str2.length <= 1000
 * str1 and str2 consist of English uppercase letters.
 *
 *
 */
#include "includes.h"

// @lc code=start
class Solution
{
public:
    std::string gcdOfStrings(std::string str1, std::string str2)
    {
        int L = 0;

        // euclidean algorithm for GCD
        int a = str1.size();
        int b = str2.size();
        int gcd = 0;
        while (a != 0 and b != 0)
        {
            gcd = a % b;
            a = b;
            b = gcd;
        }

        std::string divisor;
        while (L < a)
        {
            if (str1[L] == str2[L])
            {
                divisor += str1[L];
            }
            else
            {
                break;
            }
            L++;
        }

        // check if divisor is actually equal to the strings
        for (int i = 0; i < str1.size(); ++i)
        {
            if (str1[i] != divisor[i % a])
            {
                return "";
            }
        }
        for (int i = 0; i < str2.size(); ++i)
        {
            if (str2[i] != divisor[i % a])
            {
                return "";
            }
        }

        return divisor;
    }
};
// @lc code=end

int main()
{
    Solution obj;

    std::cout << obj.gcdOfStrings("ABCDEF", "ABC") << "\n";

    return 0;
}