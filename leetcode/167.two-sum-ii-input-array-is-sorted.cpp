/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Medium (60.37%)
 * Likes:    10931
 * Dislikes: 1321
 * Total Accepted:    1.7M
 * Total Submissions: 2.8M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given a 1-indexed array of integers numbers that is already sorted in
 * non-decreasing order, find two numbers such that they add up to a specific
 * target number. Let these two numbers be numbers[index1] and numbers[index2]
 * where 1 <= index1 < index2 < numbers.length.
 *
 * Return the indices of the two numbers, index1 and index2, added by one as an
 * integer array [index1, index2] of length 2.
 *
 * The tests are generated such that there is exactly one solution. You may not
 * use the same element twice.
 *
 * Your solution must use only constant extra space.
 *
 *
 * Example 1:
 *
 *
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We
 * return [1, 2].
 *
 *
 * Example 2:
 *
 *
 * Input: numbers = [2,3,4], target = 6
 * Output: [1,3]
 * Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We
 * return [1, 3].
 *
 *
 * Example 3:
 *
 *
 * Input: numbers = [-1,0], target = -1
 * Output: [1,2]
 * Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We
 * return [1, 2].
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= numbers.length <= 3 * 10^4
 * -1000 <= numbers[i] <= 1000
 * numbers is sorted in non-decreasing order.
 * -1000 <= target <= 1000
 * The tests are generated such that there is exactly one solution.
 *
 *
 */

/*

The vector is already sorted in ascending order

there is only one solution per vector

solution must use O(1) extra space, so we can't use a hashmap like we did in the original two sum problem.

we can use a two pointer approach:

L = beginning
R = end

Then we check the sum of the values pointed to by L and R
    if bigger, decrement R
    else if smaller, increment L
    else return since we are at target
*/

#include "includes.h"
// @lc code=start
class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, const int &target)
    {
        int L = 0;
        int R = nums.size() - 1;

        while (L != R)
        {
            int sum = nums[L] + nums[R];

            if (sum > target)
            {
                R--;
            }
            else if (sum < target)
            {
                L++;
            }
            else
            {
                return {L + 1, R + 1};
            }
        }

        return {L + 1, R + 1};
    }
};
// @lc code=end

int main()
{
    // tests
    std::vector<int> v1{2, 7, 11, 15}; // target = 9
    std::vector<int> v2{2, 3, 4};      // target = 6
    std::vector<int> v3{-1, 0};        // target = -1

    Solution obj;
    std::vector<int> out = obj.twoSum(v1, 9);
    std::cout << out[0] << " " << out[1] << "\n";

    return 0;
}