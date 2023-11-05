/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (61.40%)
 * Likes:    15543
 * Dislikes: 392
 * Total Accepted:    2.6M
 * Total Submissions: 4.2M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an integer array nums, move all 0's to the end of it while maintaining
 * the relative order of the non-zero elements.
 *
 * Note that you must do this in-place without making a copy of the array.
 *
 *
 * Example 1:
 * Input: nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * Example 2:
 * Input: nums = [0]
 * Output: [0]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 *
 * Follow up: Could you minimize the total number of operations done?
 */

/*

Start at the end and swap until the zero is at the end OR it's next to a 0.

move first zero from right
0 1 0 3 9
0 1 3 0 9
0 1 3 9 0

move second zero from right
1 0 3 9 0
1 3 0 9 0
1 3 9 0 0

*/

/*

better way:

use two pointers

L and R

L finds the closest 0 from the beginning
R becomes equal to L and is moved right until we find a non-zero or we reach the end

If either L and R reach the end, then we terminate


*/

/*

best way:

keep a pointer that keeps track of the index we want to put the next NON-ZERO in
start this pointer at 0

as we iterate through the array, we check if the element is non-zero
if it is non-zero, then we swap the element with the value where j is pointing

in the case that we have a vector that starts with non-zero like

1 2 0 3 4 5

we would find a non-zero on the first iteration, and swap with itself (doesn't do anything)

*/

#include "includes.h"

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int cur = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                // swap
                int tmp = nums[i];
                nums[i] = nums[cur];
                nums[cur] = tmp;

                // move cur forward
                cur++;
            }
        }
    }
};
// @lc code=end

int main()
{
    std::vector<int> v1{0, 1, 0, 3, 12};
    std::vector<int> v2{0};
    std::vector<int> v3{1, 2, 3};
    std::vector<int> v4{0, 0, 0};
    std::vector<int> v5{0, 1, 2, 0, 0, 3, 0, 4, 0, 5, 6, 7, 0, 0, 0, 8};

    Solution obj;
    obj.moveZeroes(v1);
    obj.moveZeroes(v2);
    obj.moveZeroes(v3);
    obj.moveZeroes(v4);
    obj.moveZeroes(v5);

    return 0;
}