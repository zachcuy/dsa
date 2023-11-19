/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 *
 * https://leetcode.com/problems/koko-eating-bananas/description/
 *
 * algorithms
 * Medium (49.75%)
 * Likes:    9489
 * Dislikes: 471
 * Total Accepted:    495.3K
 * Total Submissions: 1M
 * Testcase Example:  '[3,6,7,11]\n8'
 *
 * Koko loves to eat bananas. There are n piles of bananas, the i^th pile has
 * piles[i] bananas. The guards have gone and will come back in h hours.
 *
 * Koko can decide her bananas-per-hour eating speed of k. Each hour, she
 * chooses some pile of bananas and eats k bananas from that pile. If the pile
 * has less than k bananas, she eats all of them instead and will not eat any
 * more bananas during this hour.
 *
 * Koko likes to eat slowly but still wants to finish eating all the bananas
 * before the guards return.
 *
 * Return the minimum integer k such that she can eat all the bananas within h
 * hours.
 *
 *
 * Example 1:
 *
 *
 * Input: piles = [3,6,7,11], h = 8
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: piles = [30,11,23,4,20], h = 5
 * Output: 30
 *
 *
 * Example 3:
 *
 *
 * Input: piles = [30,11,23,4,20], h = 6
 * Output: 23
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= piles.length <= 10^4
 * piles.length <= h <= 10^9
 * 1 <= piles[i] <= 10^9
 *
 *
 */

/*

From the input
-> the lower is the smallest value
-> the upper bound to be the largest value

3 6 7 11

lower: 3
upper: 11
mid: 7

check if the mid works, then save this to be the current lowest
    -> check by doing sum (each element divided by the value of mid)

if it works (result <= h), then we save it and update the current answer. Then decrease the upper
bound. if it doesn't work (result > h), then we don't save it and increase the lowest bound

*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // binary search
    long long calcTime(vector<int>& piles, long long mid, long long lower, long long upper)
    {
        long long h = 0;

        for (auto& pile : piles)
        {
            if (pile == mid or pile < mid)
            {
                h++;
            }
            else
            {
                // bigger than guess
                long long remainder = pile % mid;
                h += pile / mid;
                if (remainder)
                {
                    h++;
                }
            }
        }

        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h)
    {
        long long lower = 1;
        long long upper = *max_element(piles.begin(), piles.end());
        long long answer = upper;

        while (lower <= upper)
        {
            long long mid = (upper + lower) / 2;
            long long time = calcTime(piles, mid, lower, upper);

            if (time <= h)
            {
                upper = ((upper + lower) / 2) - 1;

                // update answer
                if (mid < answer)
                {
                    answer = mid;
                }
            }
            else
            {
                lower = ((upper + lower) / 2) + 1;
            }
        }

        return answer;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<int> v1{3, 6, 7, 11};
    vector<int> v2{30, 11, 23, 4, 20};
    vector<int> v3{30, 11, 23, 4, 20};
    vector<int> v4{312884470};
    vector<int> v5{805306368, 805306368, 805306368};

    obj.minEatingSpeed(v1, 8);           // 4
    obj.minEatingSpeed(v2, 5);           // 30
    obj.minEatingSpeed(v3, 6);           // 23
    obj.minEatingSpeed(v4, 312884469);   // 2
    obj.minEatingSpeed(v5, 1000000000);  // 3
    return 0;
}
