/*
 * @lc app=leetcode id=1287 lang=cpp
 *
 * [1287] Element Appearing More Than 25% In Sorted Array
 *
 * https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/
 *
 * algorithms
 * Easy (59.10%)
 * Likes:    970
 * Dislikes: 52
 * Total Accepted:    92.3K
 * Total Submissions: 155.7K
 * Testcase Example:  '[1,2,2,6,6,6,6,7,10]'
 *
 * Given an integer array sorted in non-decreasing order, there is exactly one
 * integer in the array that occurs more than 25% of the time, return that
 * integer.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [1,2,2,6,6,6,6,7,10]
 * Output: 6
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [1,1]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 10^4
 * 0 <= arr[i] <= 10^5
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int findSpecialInteger(vector<int>& arr)
    {
        /*
        go through the array, keep track of most frequent element and its frequency
        keep track of current element and its frequency, update most frequent
        */

        int curFreq = 0;
        int curNum = 0;
        int maxFreq = 0;
        int maxNum = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (arr[i] != curNum)
            {
                curNum = arr[i];
                curFreq = 1;
            }
            else
            {
                curFreq++;
            }
            if (curFreq > maxFreq)
            {
                maxFreq = curFreq;
                maxNum = curNum;
            }
        }

        return maxNum;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{1, 2, 2, 6, 6, 6, 6, 7, 10};
    vector<int> v2{1, 1};
    vector<int> v3{1};

    dump(obj.findSpecialInteger(v1));
    dump(obj.findSpecialInteger(v2));
    dump(obj.findSpecialInteger(v3));
    return 0;
}