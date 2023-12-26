/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

/*
    iterate through the loop and count the number of 1s.

    THEN:
    the number of ones on the right hand side is the total number minus the number of ones we have
   encountered on the left hand side

    then we can calculate the score. the score on the left is the index minus the number of 1s we
    have encountered so far. the number of ones is



*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int maxScore(string s)
    {
        int totalOnes = 0;
        for (auto& digit : s)
        {
            if (digit == '1')
            {
                totalOnes++;
            }
        }

        int score = 0;
        int curOnes = 0;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            if (s[i] == '1')
            {
                curOnes++;
            }
            int tmp = (totalOnes - curOnes) + (i + 1 - curOnes);
            score = max(score, tmp);
        }

        return score;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    string s1{"011101"};
    string s2{"00111"};
    string s3{"1111"};
    string s4{"00"};

    dump(obj.maxScore(s1));  // 5
    dump(obj.maxScore(s2));  // 5
    dump(obj.maxScore(s3));  // 3
    dump(obj.maxScore(s4));  // 1
    return 0;
}