/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.size() - 1;

        while (l < r)
        {
            if (!isalnum(s[l]))
            {
                l++;
            }
            else if (!isalnum(s[r]))
            {
                r--;
            }
            else
            {
                s[l] = tolower(s[l]);
                s[r] = tolower(s[r]);

                if (s[l] != s[r])
                {
                    return false;
                }
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
    return 0;
}