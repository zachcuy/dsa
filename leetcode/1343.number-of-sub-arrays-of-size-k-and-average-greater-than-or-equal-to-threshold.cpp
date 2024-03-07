/*
 * @lc app=leetcode id=1343 lang=cpp
 *
 * [1343] Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 *
 * https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/
 *
 * algorithms
 * Medium (68.17%)
 * Likes:    1526
 * Dislikes: 97
 * Total Accepted:    82.6K
 * Total Submissions: 121.1K
 * Testcase Example:  '[2,2,2,2,5,5,5,8]\n3\n4'
 *
 * Given an array of integers arr and two integers k and threshold, return the
 * number of sub-arrays of size k and average greater than or equal to
 * threshold.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
 * Output: 3
 * Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6
 * respectively. All other sub-arrays of size 3 have averages less than 4 (the
 * threshold).
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
 * Output: 6
 * Explanation: The first 6 sub-arrays of size 3 have averages greater than 5.
 * Note that averages are not integers.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 10^5
 * 1 <= arr[i] <= 10^4
 * 1 <= k <= arr.length
 * 0 <= threshold <= 10^4
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC - basic sliding window
    // int numOfSubarrays(vector<int>& arr, int k, int threshold)
    // {
    //     int sum = 0;
    //     // build first window's sum
    //     for (int i = 0; i < k; ++i)
    //     {
    //         sum += arr[i];
    //     }

    //     int count = 0;
    //     int average = sum / k;
    //     if (average >= threshold)
    //     {
    //         count++;
    //     }

    //     // iterate through rest of array
    //     for (int i = k; i < arr.size(); ++i)
    //     {
    //         sum += arr[i] - arr[i - k];
    //         average = sum / k;
    //         if (average >= threshold)
    //         {
    //             count++;
    //         }
    //     }

    //     return count;
    // }
    // AC - prefix sums
    int numOfSubarrays(vector<int>& arr, int k, int threshold)
    {
        // generate prefix sum
        for (int i = 1; i < arr.size(); ++i)
        {
            arr[i] += arr[i - 1];
        }

        int count = 0;
        for (int i = k - 1; i < arr.size(); ++i)
        {
            int average = 0;
            if (i == k - 1)
            {
                average = arr[i] / k;
            }
            else
            {
                average = (arr[i] - arr[i - k]) / k;
            }

            if (average >= threshold)
            {
                count++;
            }
        }

        return count;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{2, 2, 2, 2, 5, 5, 5, 8};
    vector<int> v2{11, 13, 17, 23, 29, 31, 7, 5, 2, 3};

    dump(obj.numOfSubarrays(v1, 3, 4));  // 3
    dump(obj.numOfSubarrays(v2, 3, 5));  // 6
    return 0;
}