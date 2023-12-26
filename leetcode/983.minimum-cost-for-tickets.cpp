/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

/*
    the recurrence relationship is:
        base case:
            0 costs 0$ regardless

        general case:
            using the days, we can calculate the cheapest that covers the previous number of days
            the tickets can only be in 1, 7, and 30 day subscriptions.

    1 2 3 4 5 6 7 8 9 10
    2 2 2 4 4 6 8
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        int maxDay = *max_element(days.begin(), days.end());
        vector<int> dp(maxDay + 1, INT_MAX);

        unordered_set<int> s;
        for (int i = 0; i < days.size(); ++i)
        {
            s.insert(days[i]);
        }

        dp[0] = 0;
        for (int i = 1; i < maxDay + 1; ++i)
        {
            if (s.count(i))
            {
                if (i >= 30)
                {
                    dp[i] = min(
                        {dp[i], dp[i - 1] + costs[0], dp[i - 7] + costs[1], dp[i - 30] + costs[2]});
                }
                else if (i >= 7)
                {
                    dp[i] = min({dp[i], dp[i - 1] + costs[0], dp[i - 7] + costs[1], costs[2]});
                }
                else if (i >= 1)
                {
                    dp[i] = min({dp[i], dp[i - 1] + costs[0], costs[1], costs[2]});
                }
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }

        return dp[maxDay];
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{1, 4, 6, 7, 8, 20};
    vector<int> c1{2, 7, 15};

    vector<int> v2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    vector<int> c2{2, 7, 15};

    vector<int> v3{1, 4, 6, 7, 8, 20};
    vector<int> c3{7, 2, 15};

    vector<int> v4{1, 2, 3, 4, 6, 8, 9, 10, 13, 14, 16, 17, 19, 21, 24, 26, 27, 28, 29};
    vector<int> c4{3, 14, 50};

    dump(obj.mincostTickets(v1, c1));
    dump(obj.mincostTickets(v2, c2));
    dump(obj.mincostTickets(v3, c3));
    dump(obj.mincostTickets(v4, c4));
    return 0;
}