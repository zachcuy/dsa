/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (65.89%)
 * Likes:    11898
 * Dislikes: 260
 * Total Accepted:    738.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * Given an array of integers temperatures represents the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to
 * wait after the i^th day to get a warmer temperature. If there is no future
 * day for which this is possible, keep answer[i] == 0 instead.
 *
 *
 * Example 1:
 * Input: temperatures = [73,74,75,71,69,72,76,73]
 * Output: [1,1,4,2,1,1,0,0]
 * Example 2:
 * Input: temperatures = [30,40,50,60]
 * Output: [1,1,1,0]
 * Example 3:
 * Input: temperatures = [30,60,90]
 * Output: [1,1,0]
 *
 *
 * Constraints:
 *
 *
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    vector<int> dailyTemperatures(vector<int>& v)
    {
        stack<int> s;
        s.push(0);

        for (int i = 1; i < v.size(); ++i)
        {
            int cur = v[i];

            while (s.size() and v[s.top()] < cur)
            {
                size_t el = s.top();
                s.pop();

                v[el] = (i - el);
            }
            s.push(i);
        }

        while (s.size())
        {
            size_t el = s.top();
            s.pop();

            v[el] = 0;
        }

        return v;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<int> v1{73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> v2{30, 40, 50, 60};
    vector<int> v3{30, 60, 90};
    vector<int> v4{89, 62, 70, 58, 47, 47, 46, 76, 100, 70};

    obj.dailyTemperatures(v1);  // 1,1,4,2,1,1,0,0
    obj.dailyTemperatures(v2);  // 1,1,1,0
    obj.dailyTemperatures(v3);  // 1,1,0
    obj.dailyTemperatures(v4);  // 8,1,5,4,3,2,1,1,0,0
    return 0;
}
