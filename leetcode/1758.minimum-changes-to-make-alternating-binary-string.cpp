/*
 * @lc app=leetcode id=1758 lang=cpp
 *
 * [1758] Minimum Changes To Make Alternating Binary String
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int minOperations(string s)
    {
        int evenStart = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            // assume we have the pattern 101010...
            if (!(i % 2) and s[i] != '1')
            {
                evenStart++;
            }
            else if (i % 2 and s[i] != '0')
            {
                evenStart++;
            }
        }

        int oddStart = s.size() - evenStart;
        return min(evenStart, oddStart);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution obj;

    string s1{"0100"};
    string s2{"10"};
    string s3{"1111"};
    string s4{"10010100"};

    dump(obj.minOperations(s1));  // 1
    dump(obj.minOperations(s2));  // 0
    dump(obj.minOperations(s3));  // 2
    dump(obj.minOperations(s4));  // 3
    return 0;
}