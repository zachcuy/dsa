/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int maxProfit(vector<int>& prices)
    {
        int maxProfit = 0;
        int maxElement = 0;
        int minElement = INT_MAX;

        for (int i = 0; i < prices.size(); ++i)
        {
            if (prices[i] < minElement)
            {
                minElement = prices[i];
                maxElement = prices[i];
            }
            else if (prices[i] > maxElement)
            {
                maxElement = prices[i];
            }
            maxProfit = max(maxProfit, maxElement - minElement);
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

    dump(obj.maxProfit(v1));
    dump(obj.maxProfit(v2));
    return 0;
}