/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (53.41%)
 * Likes:    19132
 * Dislikes: 360
 * Total Accepted:    1.4M
 * Total Submissions: 2.6M
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an integer array nums, return the length of the longest strictly
 * increasing subsequence.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,0,3,2,3]
 * Output: 4
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 * Follow up: Can you come up with an algorithm that runs in O(n log(n)) time
 * complexity?
 *
 */

/*

building from increasing triplet subsequence problem 334

in: vec<int>
out: int = length of subsequence

subsequence must meet the requirements:
i < j < k
v[i] < v[j] < v[k]

keep track of smallest/second-smallest/third-smallest/...
use a vector

search the vector using binary search (since it'll be sorted!)
binary search returns the index of where we want the value to go
if it's not greater than the last value, and it doesn't meet any of the other reqs
we don't do anything

0 1 2 3 4 5  6 7 8 9 10
3 5 6 2 5 4 19 5 6 7 12

sorted:
3: 3
5: 3 5
6: 3 5 6
2: 2 5 6
5: 2 5 6
4: 2 4 6
19: 2 4 6 19
5: 2 4 5 19
6: 2 4 5 6
7: 2 4 5 6 7
12: 2 4 5 6 7 12

we want the index where we are bigger than the previous but smaller than the current
edge case: we are too big so we just add at the end
edge case: we are too small so we just replace the first

*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    void binSearch(std::vector<int> &v, int target)
    {
        // edge case: ending
        if (target > v[v.size() - 1])
        {
            v.push_back(target);
        }
        // edge case: beginning
        else if (target <= v[0])
        {
            v[0] = target;
        }
        else
        {
            // search for where to place it (not the ends)
            int L = 0;
            int R = v.size() - 1;
            int mid = 0;
            while (L <= R)
            {
                mid = ((R + L) / 2);

                if (v[mid] > target)
                {
                    R = mid - 1;
                }
                else if (v[mid] < target)
                {
                    L = mid + 1;
                }
                else
                {
                    return;
                }
            }

            if (v[mid] < target and v[mid + 1] > target)
            {
                v[mid + 1] = target;
            }
            else
            {
                v[mid] = target;
            }
        }
    }
    int lengthOfLIS(vector<int> &nums)
    {
        std::vector<int> sorted{INT_MAX};

        for (int i = 0; i < nums.size(); ++i)
        {
            // insert value using bin search
            binSearch(sorted, nums[i]);
        }

        return sorted.size();
    }
};
// @lc code=end

int main()
{
    Solution obj;
    std::vector<int> v1{10, 9, 2, 5, 3, 7, 101, 18};
    std::vector<int> v2{0, 1, 0, 3, 2, 3};
    std::vector<int> v3{7, 7, 7, 7, 7, 7, 7};
    std::vector<int> v4{4, 10, 4, 10, 3, 8, 9};
    std::vector<int> v5{1, 3, 6, 7, 9, 4, 10, 5, 6};
    std::vector<int> v6{3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12};
    std::vector<int> v7{
        -813, 82,   -728, -82,  -432, 887,  -551, 324,  -315, 306,  -164, -499,  -873, -613, 932,
        177,  61,   52,   1000, -710, 372,  -306, -584, -332, -500, 407,  399,   -648, 290,  -866,
        222,  562,  993,  -338, -590, 303,  -16,  -134, 226,  -648, 909,  582,   177,  899,  -343,
        55,   629,  248,  333,  1,    -921, 143,  629,  981,  -435, 681,  844,   349,  613,  457,
        797,  695,  485,  15,   710,  -450, -775, 961,  -445, -905, 466,  942,   995,  -289, -397,
        434,  -14,  34,   -903, 314,  862,  -441, 507,  -966, 525,  624,  -706,  39,   152,  536,
        874,  -364, 747,  -35,  446,  -608, -554, -411, 987,  -354, -700, -34,   395,  -977, 544,
        -330, 596,  335,  -612, 28,   586,  228,  -664, -841, -999, -100, -620,  718,  489,  346,
        450,  772,  941,  952,  -560, 58,   999,  -879, 396,  -101, 897,  -1000, -566, -296, -555,
        938,  941,  475,  -260, -52,  193,  379,  866,  226,  -611, -177, 507,   910,  -594, -856,
        156,  71,   -946, -660, -716, -295, -927, 148,  620,  201,  706,  570,   -659, 174,  637,
        -293, 736,  -735, 377,  -687, -962, 768,  430,  576,  160,  577,  -329,  175,  51,   699,
        -113, 950,  -364, 383,  5,    748,  -250, -644, -576, -227, 603,  832,   -483, -237, 235,
        893,  -336, 452,  -526, 372,  -418, 356,  325,  -180, 134,  -698};

    std::cout << obj.lengthOfLIS(v1) << "\n";  // 4
    std::cout << obj.lengthOfLIS(v2) << "\n";  // 4
    std::cout << obj.lengthOfLIS(v3) << "\n";  // 1
    std::cout << obj.lengthOfLIS(v4) << "\n";  // 3
    std::cout << obj.lengthOfLIS(v5) << "\n";  // 6
    std::cout << obj.lengthOfLIS(v6) << "\n";  // 6
    std::cout << obj.lengthOfLIS(v7) << "\n";  // 25
}