/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 *
 * https://leetcode.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (70.96%)
 * Likes:    2519
 * Dislikes: 328
 * Total Accepted:    1.1M
 * Total Submissions: 1.6M
 * Testcase Example:  '3'
 *
 * Given an integer n, return a string array answer (1-indexed) where:
 *
 *
 * answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
 * answer[i] == "Fizz" if i is divisible by 3.
 * answer[i] == "Buzz" if i is divisible by 5.
 * answer[i] == i (as a string) if none of the above conditions are true.
 *
 *
 *
 * Example 1:
 * Input: n = 3
 * Output: ["1","2","Fizz"]
 * Example 2:
 * Input: n = 5
 * Output: ["1","2","Fizz","4","Buzz"]
 * Example 3:
 * Input: n = 15
 * Output:
 * ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^4
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> ans;

        for (int i = 1; i <= n; ++i)
        {
            if (!(i % 3) and !(i % 5))
            {
                ans.push_back("FizzBuzz");
            }
            else if (!(i % 3) and (i % 5))
            {
                ans.push_back("Fizz");
            }
            else if ((i % 3) and !(i % 5))
            {
                ans.push_back("Buzz");
            }
            else
            {
                ans.push_back(to_string(i));
            }
        }

        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution obj;
    dump(obj.fizzBuzz(3));
    dump(obj.fizzBuzz(5));
    dump(obj.fizzBuzz(15));
    return 0;
}