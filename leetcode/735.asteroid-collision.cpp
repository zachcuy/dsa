/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 *
 * https://leetcode.com/problems/asteroid-collision/description/
 *
 * algorithms
 * Medium (45.18%)
 * Likes:    7263
 * Dislikes: 826
 * Total Accepted:    409.9K
 * Total Submissions: 909.9K
 * Testcase Example:  '[5,10,-5]'
 *
 * We are given an array asteroids of integers representing asteroids in a
 * row.
 *
 * For each asteroid, the absolute value represents its size, and the sign
 * represents its direction (positive meaning right, negative meaning left).
 * Each asteroid moves at the same speed.
 *
 * Find out the state of the asteroids after all collisions. If two asteroids
 * meet, the smaller one will explode. If both are the same size, both will
 * explode. Two asteroids moving in the same direction will never meet.
 *
 *
 * Example 1:
 *
 *
 * Input: asteroids = [5,10,-5]
 * Output: [5,10]
 * Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never
 * collide.
 *
 *
 * Example 2:
 *
 *
 * Input: asteroids = [8,-8]
 * Output: []
 * Explanation: The 8 and -8 collide exploding each other.
 *
 *
 * Example 3:
 *
 *
 * Input: asteroids = [10,2,-5]
 * Output: [10]
 * Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide
 * resulting in 10.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= asteroids.length <= 10^4
 * -1000 <= asteroids[i] <= 1000
 * asteroids[i] != 0
 *
 *
 */

/*
in: vec<int>
    sign: direction (+ : right, - : left)
    value: size

out: vec<int>

using new vec<int> and iter through input
    same sign as previous -> push
    diff sign than previous -> replace last element with the greater of the two
        keep breaking down until all elements have the same sige or no more elements left to compare


ex:

5 10 -5

i = 0
stack: 5

i = 1
stack: 5, 10

i = 2
stack: 5, 10
5 < 10: 10

*/
#include "includes.h"
// @lc code=start
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &nums)
    {
        std::vector<int> out;

        // add first asteroid to out
        out.push_back(nums[0]);

        // go through rest of vector
        for (int i = 1; i < nums.size(); ++i)
        {
            while (out.size() and (out.back() > 0 and nums[i] < 0))
            {
                if (std::abs(nums[i]) < std::abs(out.back())) // new number is smaller
                {
                    // don't delete anything
                    nums[i] = 0;
                    break;
                }
                else if (std::abs(nums[i]) == std::abs(out.back()))
                {
                    out.pop_back();
                    nums[i] = 0;
                }
                else
                {
                    // new number is bigger
                    out.pop_back();
                }
            }
            if (nums[i])
            {
                out.push_back(nums[i]);
            }
        }

        return out;
    }
};
// @lc code=end

int main()
{
    Solution obj;

    std::vector<int> v1{5, 10, -5};
    std::vector<int> v2{8, -8};
    std::vector<int> v3{-5, -10, 10, 5};
    obj.asteroidCollision(v1);
    obj.asteroidCollision(v2);
    obj.asteroidCollision(v3);
}