/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (40.17%)
 * Likes:    13604
 * Dislikes: 484
 * Total Accepted:    1M
 * Total Submissions: 2.6M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * You are given a 0-indexed array of integers nums of length n. You are
 * initially positioned at nums[0].
 *
 * Each element nums[i] represents the maximum length of a forward jump from
 * index i. In other words, if you are at nums[i], you can jump to any nums[i +
 * j] where:
 *
 *
 * 0 <= j <= nums[i] and
 * i + j < n
 *
 *
 * Return the minimum number of jumps to reach nums[n - 1]. The test cases are
 * generated such that you can reach nums[n - 1].
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2. Jump
 * 1 step from index 0 to 1, then 3 steps to the last index.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,3,0,1,4]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 1000
 * It's guaranteed that you can reach nums[n - 1].
 *
 *
 */

/*

since we know that we can definitely get to the end,

we can take the greedy approach and go to the cell that provides the FARTHEST index

so if we have
2 3 1 1 4

at 0, we can go to [1] or [2] which is 3 or 1
3 means we can go to [1] + 3 = [4]
1 means we can go to [2] + 1 = [3]

so choose the bigger one

if we ever find a value that already meets the end, then we can return current step + 1

*/

// @lc code=start
#include "includes.h"

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int count = 0;

        int maxDistance = 0;
        int i = 0;

        while (i <= maxDistance)
        {
            int cur = nums[i];
        }

        return 0;
    }
};
// @lc code=end

int main()
{

    return 0;
}