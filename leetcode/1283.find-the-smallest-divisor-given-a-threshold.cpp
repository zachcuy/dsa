/*
 * @lc app=leetcode id=1283 lang=cpp
 *
 * [1283] Find the Smallest Divisor Given a Threshold
 *
 * https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
 *
 * algorithms
 * Medium (58.11%)
 * Likes:    2676
 * Dislikes: 182
 * Total Accepted:    144.6K
 * Total Submissions: 247.5K
 * Testcase Example:  '[1,2,5,9]\n6'
 *
 * Given an array of integers nums and an integer threshold, we will choose a
 * positive integer divisor, divide all the array by it, and sum the division's
 * result. Find the smallest divisor such that the result mentioned above is
 * less than or equal to threshold.
 *
 * Each result of the division is rounded to the nearest integer greater than
 * or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
 *
 * The test cases are generated so that there will be an answer.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,5,9], threshold = 6
 * Output: 5
 * Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1.
 * If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5
 * the sum will be 5 (1+1+1+2).
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [44,22,33,11,1], threshold = 5
 * Output: 44
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5 * 10^4
 * 1 <= nums[i] <= 10^6
 * nums.length <= threshold <= 10^6
 *
 *
 */

/*

    choose a number between 1 and max_element

    divide each number and if it has a non-zero remainder, add 1 to it
    sum all the results of the division operations

    naive:
        go from 1 to divisor and stop when we don't decrease the result

    binary search:
        start with 1 to max_element
        choose middle element
            if the threshold is met --> make that the upper bound
            if the threshold is not met --> make that + 1 the lower bound


*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int binSearch(int l, int u)
    {
        int mid = (l + u) / 2;
        return mid;
    }
    // AC
    int smallestDivisor(vector<int>& nums, int threshold)
    {
        int lower = 1;
        int upper = *max_element(nums.begin(), nums.end());

        int minDivisor = INT_MAX;
        while (lower <= upper)
        {
            int divisor = binSearch(lower, upper);
            int curSum = 0;
            for (int i = 0; i < nums.size(); ++i)
            {
                curSum += nums[i] / divisor;
                if (nums[i] % divisor)
                {
                    curSum++;
                }
            }

            if (curSum <= threshold)
            {
                // check if we update minDivisor
                if (divisor < minDivisor)
                {
                    minDivisor = divisor;
                }
                upper = divisor - 1;
            }
            else
            {
                lower = divisor + 1;
            }
        }

        return minDivisor;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{1, 2, 5, 9};
    vector<int> v2{44, 22, 33, 11, 1};

    // dump(obj.smallestDivisor(v1, 6));
    dump(obj.smallestDivisor(v2, 5));
    return 0;
}