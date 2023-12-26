/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

/*
    The cheapest to get to the end of array --> vec.size()

    the general template for solving a problem like this using the iterative approach is

    if the size is <= 2, then the cheapest is the minimum between the two values

    if the size is > 2, then we have a base case of the first two values.
        the recurrence relation is curStep + min(dp[i-1], dp[i-2])
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int dp[1001];
    // AC
    int minCostClimbingStairs(vector<int>& cost)
    {
        if (cost.size() == 2)
        {
            return min(cost[0], cost[1]);
        }

        dp[0] = cost[0];
        dp[1] = cost[1];
        cost.push_back(0);
        for (int i = 2; i < cost.size(); ++i)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        return dp[cost.size() - 1];
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<int> v1{10, 15, 20};
    vector<int> v2{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    dump(obj.minCostClimbingStairs(v1));
    dump(obj.minCostClimbingStairs(v2));
    return 0;
}