/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

/*
    recursive:

    we start at 1 A, which has a value of 1.

    To copy our current number of A's, that is +1
    To paste our current copied value, that is +1

    so to go from 1 to 2, we do copy + paste = 2 actions

    to go from 2 to 3, we do paste again so total actions = 2 + 1 = 3

    to go from 3 to 4, we do paste again so total actions = 3 + 1 = 4
    another option is to go to 2, then copy + paste which is 2 + 2 = 4

    from 4 to 5, we paste again from the 1... so we do 4 + 1 = 5

    from 5 to 6, we paste again so we do 5 + 1 = 6
    another option is to copy and paste starting from 1 to 3 so we get 3 then copy and paste so
   thats 3 + 2 = 5
    how did we get to 3? well, we do 6 / 2 = 3, which has value of 3 so 3 + 2 = 5

    from 6 to 7, doing 7 / 2 = 3.5 = 3 which doesn't work because 7 is not evenly divisible by 3. So
   we have a total cost of +7.

    from 7 to 8, we can do 8 / 2 = 4 and to go from 4 costs us 4. To get to 8 we copy and paste and
   thats +2, so we have a total cost of +6

   from 8 to 9, we can do 9 / 2 = 4.5 = 4 but 4 does not cleanly break us down


*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int minSteps(int n)
    {
        if (n <= 1)
        {
            return 0;
        }

        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                if (!(i % j))
                {
                    dp[i] = min(dp[j] + i / j, dp[i]);
                }
            }
            dump(dp);
        }

        return dp[n];
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    // dump(obj.minSteps(1));   // 0
    // dump(obj.minSteps(2));   // 2
    // dump(obj.minSteps(3));   // 3
    // dump(obj.minSteps(4));   // 4
    dump(obj.minSteps(5));  // 5
    // dump(obj.minSteps(6));   // 5
    // dump(obj.minSteps(7));   // 7
    // dump(obj.minSteps(8));   // 6
    // dump(obj.minSteps(9));   // 6
    // dump(obj.minSteps(10));  // 7
    return 0;
}