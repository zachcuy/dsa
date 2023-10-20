/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

#include <vector>
#include <algorithm>
// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        std::vector<int> v;

        // all negative numbers are not palindromes
        if (x < 0)
        {
            return false;
        }

        // only positive numbers
        // get numbers and put into a vector
        while (x > 0)
        {
            v.push_back(x % 10);
            x /= 10;
        }

        // check if forward is same as backwards
        const int len = v.size();
        for (int i = 0; i < v.size() / 2; ++i)
        {
            if (v[i] != v[len - i - 1])
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
