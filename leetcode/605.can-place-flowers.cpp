/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 *
 * https://leetcode.com/problems/can-place-flowers/description/
 *
 * algorithms
 * Easy (30.09%)
 * Likes:    5972
 * Dislikes: 1040
 * Total Accepted:    589.8K
 * Total Submissions: 2M
 * Testcase Example:  '[1,0,0,0,1]\n1'
 *
 * You have a long flowerbed in which some of the plots are planted, and some
 * are not. However, flowers cannot be planted in adjacent plots.
 *
 * Given an integer array flowerbed containing 0's and 1's, where 0 means empty
 * and 1 means not empty, and an integer n, return true if n new flowers can be
 * planted in the flowerbed without violating the no-adjacent-flowers rule and
 * false otherwise.
 *
 *
 * Example 1:
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: true
 * Example 2:
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= flowerbed.length <= 2 * 10^4
 * flowerbed[i] is 0 or 1.
 * There are no two adjacent flowers in flowerbed.
 * 0 <= n <= flowerbed.length
 *
 *
 */

/*

input: vector<int>, int
output: bool

in<vec> is either 1/0 denoting if there is a flower at a given position
in<int> is the number of flowers we want to plant
out<bool> is whether we can plant all n flowers can be planted

constraint: cannot have adjacent 1's

go through list, check element before/after current element to see if it's a 0
    only if current one is 0
    and if neighbors are 0, then flip current to 1, increment counter

*/
#include "includes.h"

// @lc code=start
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int count = 0;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for (int i = 1; i < flowerbed.size() - 1; ++i)
        {
            if (flowerbed[i] == 0)
            {
                if (flowerbed[i - 1] == 0 and flowerbed[i + 1] == 0)
                {
                    count++;
                    flowerbed[i] = 1;
                }
            }
        }

        return count >= n;
    }
};
// @lc code=end

int main()
{
    Solution obj;
    std::vector<int> v{1, 0, 0, 0, 1};
    std::cout << obj.canPlaceFlowers(v, 2) << "\n";
    return 0;
}