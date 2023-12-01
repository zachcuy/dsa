/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 *
 * https://leetcode.com/problems/min-cost-climbing-stairs/description/
 *
 * algorithms
 * Easy (64.17%)
 * Likes:    10863
 * Dislikes: 1648
 * Total Accepted:    1M
 * Total Submissions: 1.6M
 * Testcase Example:  '[10,15,20]'
 *
 * You are given an integer array cost where cost[i] is the cost of i^th step
 * on a staircase. Once you pay the cost, you can either climb one or two
 * steps.
 *
 * You can either start from the step with index 0, or the step with index 1.
 *
 * Return the minimum cost to reach the top of the floor.
 *
 *
 * Example 1:
 *
 *
 * Input: cost = [10,15,20]
 * Output: 15
 * Explanation: You will start at index 1.
 * - Pay 15 and climb two steps to reach the top.
 * The total cost is 15.
 *
 *
 * Example 2:
 *
 *
 * Input: cost = [1,100,1,1,1,100,1,1,100,1]
 * Output: 6
 * Explanation: You will start at index 0.
 * - Pay 1 and climb two steps to reach index 2.
 * - Pay 1 and climb two steps to reach index 4.
 * - Pay 1 and climb two steps to reach index 6.
 * - Pay 1 and climb one step to reach index 7.
 * - Pay 1 and climb two steps to reach index 9.
 * - Pay 1 and climb one step to reach the top.
 * The total cost is 6.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= cost.length <= 1000
 * 0 <= cost[i] <= 999
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // recursion AC
    // int count(std::vector<int>& cost, int n, std::unordered_map<int, int>& m)
    // {
    //     if (n <= 1) {
    //         return cost[n];
    //     }
    //     if (m.count(n)) {
    //         return m[n];
    //     }

    //     int c = (n == cost.size() ? 0 : cost[n]);
    //     m[n] = c + std::min(count(cost, n - 1, m), count(cost, n - 2, m));

    //     return m[n];
    // }
    // int minCostClimbingStairs(vector<int>& cost)
    // {
    //     std::unordered_map<int, int> m;
    //     return count(cost, cost.size(), m);
    // }

    // Iterative
    // int minCostClimbingStairs(vector<int>& cost)
    // {
    //     /*

    //     starting from the bottom, we can calculate the cost at our current step
    //     + the minimum between the next two steps

    //     */

    //     std::vector<int> v(cost.size() + 1, 0);
    //     for (int i = 0; i < cost.size(); ++i) {
    //         if (i <= 1) {
    //             v[i] = cost[i];
    //         }
    //         else {
    //             v[i] = cost[i] + std::min(v[i - 1], v[i - 2]);
    //         }
    //     }

    //     return std::min(v[cost.size() - 1], v[cost.size() - 2]);
    // }

    // revisited (nov 20, 2023)
    int minCostClimbingStairs(vector<int>& cost)
    {
        // can start on i = 0 or i = 1

        vector<int> dp(cost.size(), INT_MAX);

        for (int i = 0; i < cost.size(); ++i)
        {
            if (i <= 1)
            {
                dp[i] = cost[i];
            }
            else
            {
                dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
            }
        }

        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};
// @lc code=end

int main()
{
    Solution obj;

    std::vector<int> v1{10, 15, 20};                          // 15
    std::vector<int> v2{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};  // 6

    std::cout << obj.minCostClimbingStairs(v1) << "\n\n\n";
    std::cout << obj.minCostClimbingStairs(v2) << "\n\n\n";
}