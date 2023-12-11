#include "includes.h"
/*

we can make up to k deletions, if we have a mismatching element, then we increment either l or r by
1 and check the remaining



*/

class Solution
{
   public:
    bool isPalindrome(string s, int l, int r)
    {
        while (l <= r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
    bool isValidPalindrome(string s, int k)
    {
        // change up to k values, and then check if it's a palindrome or not
        int l = 0;
        int r = s.size() - 1;
        int count = 0;

        while (l <= r)
        {
            if (s[l] != s[r])
            {
                count++;
            }
            l++;
            r--;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution obj;

    return 0;
}