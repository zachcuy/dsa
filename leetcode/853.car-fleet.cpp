/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 *
 * https://leetcode.com/problems/car-fleet/description/
 *
 * algorithms
 * Medium (50.33%)
 * Likes:    3148
 * Dislikes: 773
 * Total Accepted:    196K
 * Total Submissions: 388.7K
 * Testcase Example:  '12\n[10,8,0,5,3]\n[2,4,1,1,3]'
 *
 * There are n cars going to the same destination along a one-lane road. The
 * destination is target miles away.
 *
 * You are given two integer array position and speed, both of length n, where
 * position[i] is the position of the i^th car and speed[i] is the speed of the
 * i^th car (in miles per hour).
 *
 * A car can never pass another car ahead of it, but it can catch up to it and
 * drive bumper to bumper at the same speed. The faster car will slow down to
 * match the slower car's speed. The distance between these two cars is ignored
 * (i.e., they are assumed to have the same position).
 *
 * A car fleet is some non-empty set of cars driving at the same position and
 * same speed. Note that a single car is also a car fleet.
 *
 * If a car catches up to a car fleet right at the destination point, it will
 * still be considered as one car fleet.
 *
 * Return the number of car fleets that will arrive at the destination.
 *
 *
 * Example 1:
 *
 *
 * Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
 * Output: 3
 * Explanation:
 * The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting
 * each other at 12.
 * The car starting at 0 does not catch up to any other car, so it is a fleet
 * by itself.
 * The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting
 * each other at 6. The fleet moves at speed 1 until it reaches target.
 * Note that no other cars meet these fleets before the destination, so the
 * answer is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: target = 10, position = [3], speed = [3]
 * Output: 1
 * Explanation: There is only one car, hence there is only one fleet.
 *
 *
 * Example 3:
 *
 *
 * Input: target = 100, position = [0,2,4], speed = [4,2,1]
 * Output: 1
 * Explanation:
 * The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting
 * each other at 4. The fleet moves at speed 2.
 * Then, the fleet (speed 2) and the car starting at 4 (speed 1) become one
 * fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches
 * target.
 *
 *
 *
 * Constraints:
 *
 *
 * n == position.length == speed.length
 * 1 <= n <= 10^5
 * 0 < target <= 10^6
 * 0 <= position[i] < target
 * All the values of position are unique.
 * 0 < speed[i] <= 10^6
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    double calcTime(int target, int pos, int vel)
    {
        double res = 0;
        double distance = target - pos;
        res = distance / vel;

        return res;
    }
    // AC
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        // sort cars by position
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); ++i)
        {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(),
             [](pair<int, int> a, pair<int, int> b) { return (a.first > b.first); });

        int count = 0;
        double maxTime = 0;
        for (int i = 0; i < cars.size(); ++i)
        {
            double curTime = calcTime(target, cars[i].first, cars[i].second);
            if (maxTime < curTime)
            {
                // update maxTime
                maxTime = curTime;
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
    vector<int> p1{10, 8, 0, 5, 3};
    vector<int> s1{2, 4, 1, 1, 3};

    vector<int> p2{3};
    vector<int> s2{3};

    vector<int> p3{0, 2, 4};
    vector<int> s3{4, 2, 1};

    vector<int> p4{6, 8};
    vector<int> s4{3, 2};

    vector<int> p5{0, 4, 2};
    vector<int> s5{2, 1, 3};

    vector<int> p6{8, 3, 7, 4, 6, 5};
    vector<int> s6{4, 4, 4, 4, 4, 4};

    vector<int> p7{11, 14, 13, 6};
    vector<int> s7{2, 2, 6, 7};

    dump(obj.carFleet(12, p1, s1));   // 3
    dump(obj.carFleet(10, p2, s2));   // 1
    dump(obj.carFleet(100, p3, s3));  // 1
    dump(obj.carFleet(10, p4, s4));   // 2
    dump(obj.carFleet(10, p5, s5));   // 1
    dump(obj.carFleet(10, p6, s6));   // 6
    dump(obj.carFleet(16, p7, s7));   // 2

    return 0;
}