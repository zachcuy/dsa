/*
 * @lc app=leetcode id=2594 lang=cpp
 *
 * [2594] Minimum Time to Repair Cars
 *
 * https://leetcode.com/problems/minimum-time-to-repair-cars/description/
 *
 * algorithms
 * Medium (42.51%)
 * Likes:    501
 * Dislikes: 24
 * Total Accepted:    13.3K
 * Total Submissions: 31.1K
 * Testcase Example:  '[4,2,3,1]\n10'
 *
 * You are given an integer array ranks representing the ranks of some
 * mechanics. ranksi is the rank of the i^th mechanic. A mechanic with a rank r
 * can repair n cars in r * n^2 minutes.
 *
 * You are also given an integer cars representing the total number of cars
 * waiting in the garage to be repaired.
 *
 * Return the minimum time taken to repair all the cars.
 *
 * Note: All the mechanics can repair the cars simultaneously.
 *
 *
 * Example 1:
 *
 *
 * Input: ranks = [4,2,3,1], cars = 10
 * Output: 16
 * Explanation:
 * - The first mechanic will repair two cars. The time required is 4 * 2 * 2 =
 * 16 minutes.
 * - The second mechanic will repair two cars. The time required is 2 * 2 * 2 =
 * 8 minutes.
 * - The third mechanic will repair two cars. The time required is 3 * 2 * 2 =
 * 12 minutes.
 * - The fourth mechanic will repair four cars. The time required is 1 * 4 * 4
 * = 16 minutes.
 * It can be proved that the cars cannot be repaired in less than 16
 * minutes.​​​​​
 *
 *
 * Example 2:
 *
 *
 * Input: ranks = [5,1,8], cars = 6
 * Output: 16
 * Explanation:
 * - The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5
 * minutes.
 * - The second mechanic will repair four cars. The time required is 1 * 4 * 4
 * = 16 minutes.
 * - The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8
 * minutes.
 * It can be proved that the cars cannot be repaired in less than 16
 * minutes.​​​​​
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= ranks.length <= 10^5
 * 1 <= ranks[i] <= 100
 * 1 <= cars <= 10^6
 *
 *
 */

/*

    intuition: use a priority queue to keep track of which mechanic to use next that would result in
   the lowest max time

    use a min heap

    time = index * (n^2)
*/
#include "includes.h"
// @lc code=start
struct Comparator
{
    bool operator()(const tuple<long long, long long, int>& a,
                    const tuple<long long, long long, int>& b)
    {
        return get<0>(a) > get<0>(b);
    }
};
class Solution
{
   public:
    // HEAP TLE: o(n lgk)
    // long long repairCars(vector<int>& ranks, int cars)
    // {
    //     priority_queue<tuple<long long, long long, int>, vector<tuple<long long, long long,
    //     int>>,
    //                    Comparator>
    //         pq;

    //     for (int i = 0; i < ranks.size(); ++i)
    //     {
    //         pq.push({ranks[i], 1, i});
    //     }

    //     long long maxTime = 0;
    //     int count = 0;
    //     while (count < cars)
    //     {
    //         // get next cheapest mechanic
    //         auto [nextCheapest, carsProcessed, idx] = pq.top();
    //         pq.pop();

    //         // update the max time
    //         maxTime = max(maxTime, nextCheapest);

    //         nextCheapest = ranks[idx] * (carsProcessed + 1) * (carsProcessed + 1);

    //         // add the mechanic back to heap
    //         pq.push({nextCheapest, carsProcessed + 1, idx});

    //         // go to next car
    //         count++;
    //     }

    //     return maxTime;
    // }

    bool binSearch(vector<int>& ranks, int cars, long long time)
    {
        long long carsProcessed = 0;
        for (int i = 0; i < ranks.size(); ++i)
        {
            // time = r * n * n
            carsProcessed += sqrt(time / ranks[i]);
        }

        return carsProcessed >= cars;
    }
    // AC: binary search version --> o(n lgn)
    long long repairCars(vector<int>& ranks, int cars)
    {
        long long lower = 1;
        long long upper = LONG_LONG_MAX - 2;

        while (lower <= upper)
        {
            long long time = (upper + lower) / 2;

            // get time
            if (binSearch(ranks, cars, time))
            {
                upper = time - 1;
            }
            else
            {
                lower = time + 1;
            }
        }

        return lower;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{4, 2, 3, 1};
    vector<int> v2{5, 1, 8};
    vector<int> v3{31, 31, 5,  19, 19, 10, 31, 18, 19, 3,  16, 20, 4,  16, 2,  25, 10, 16,
                   23, 18, 21, 23, 28, 6,  7,  29, 11, 11, 19, 20, 24, 19, 26, 12, 29, 29,
                   1,  14, 17, 26, 24, 7,  11, 28, 22, 14, 31, 12, 3,  19, 16, 26, 11};

    dump(obj.repairCars(v1, 10));      // 16
    dump(obj.repairCars(v2, 6));       // 16
    dump(obj.repairCars(v3, 736185));  // 2 358 388 332
    return 0;
}