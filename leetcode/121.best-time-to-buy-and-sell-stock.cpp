/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (53.49%)
 * Likes:    29262
 * Dislikes: 1013
 * Total Accepted:    4M
 * Total Submissions: 7.5M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day.
 *
 * You want to maximize your profit by choosing a single day to buy one stock
 * and choosing a different day in the future to sell that stock.
 *
 * Return the maximum profit you can achieve from this transaction. If you
 * cannot achieve any profit, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Note that buying on day 2 and selling on day 1 is not allowed because you
 * must buy before you sell.
 *
 *
 * Example 2:
 *
 *
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transactions are done and the max profit =
 * 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= prices.length <= 10^5
 * 0 <= prices[i] <= 10^4
 *
 *
 */

/*
keep track of smallest possible,
keep track of biggest profit

move l to r if we are at a smaller value
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int maxProfit(vector<int>& prices)
    {
        int l = 0;
        int r = 1;
        int maxProfit = 0;
        while (r < prices.size())
        {
            int profit = prices[r] - prices[l];
            maxProfit = max(maxProfit, profit);

            if (prices[r] < prices[l])
            {
                l = r;
            }
            r++;
        }

        return maxProfit;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{7, 1, 5, 3, 6, 4};
    vector<int> v2{7, 6, 4, 3, 1};

    cout << obj.maxProfit(v1) << "\n";  // 5
    cout << obj.maxProfit(v2) << "\n";  // 0
    return 0;
}