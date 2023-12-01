/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (38.58%)
 * Likes:    18112
 * Dislikes: 1043
 * Total Accepted:    1.6M
 * Total Submissions: 4.2M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * You are given an integer array nums. You are initially positioned at the
 * array's first index, and each element in the array represents your maximum
 * jump length at that position.
 *
 * Return true if you can reach the last index, or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 * jump length is 0, which makes it impossible to reach the last index.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^5
 *
 *
 */

/*

input: vector<int>
output: bool (signifies if we can go from start to end)

start position: 0
end position: vec.size() - 1

at a given element, we can jump forward <= element number of indices

so if the vector is
2 3 1 1 4

starting at i = 0
we can go to indices: 0 + 1 and 0 + 2
so we can access the "3" or the "1"

--- first attempt ---
we can solve this using bfs or dfs
bfs / dfs gives TLE
can try using a visited set so we don't visit the same node twice...
using a set still causes a TLE

---------------------


--- second attempt ---
we can be greedy and go as far as we can from each node...
we can do this with dfs
still using a set to save some time

very slow though (~10% time complexity)
also uses a lot of space (~5% space complexity)

---------------------

*/
#include "includes.h"

// @lc code=start
class Solution
{
   public:
    // AC
    // bool canJump(vector<int> &nums)
    // {
    //     if (nums.size() == 1)
    //     {
    //         return true;
    //     }

    //     int maxDistance = 0;
    //     int i = 0;

    //     while (i <= maxDistance)
    //     {
    //         if (nums[i] + i > maxDistance)
    //         {
    //             // update max distance
    //             maxDistance = nums[i] + i;
    //         }

    //         if (maxDistance >= nums.size() - 1)
    //         {
    //             return true;
    //         }

    //         i++;
    //     }

    //     return false;
    // }

    // AC (revisited)
    bool canJump(vector<int>& nums)
    {
        // at each point, we can reach i + nums[i], so we need to see if we can reach the end or not
        int maxDistance = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > maxDistance)
            {
                return false;
            }
            maxDistance = max(maxDistance, nums[i] + i);

            if (maxDistance >= nums.size() - 1)
            {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

int main()
{
    std::vector<int> nums{2, 3, 1, 1, 4};
    std::vector<int> nums2{3, 2, 1, 0, 4};

    Solution obj;
    std::cout << obj.canJump(nums) << "\n\n";
    std::cout << obj.canJump(nums2) << "\n\n";

    return 0;
}