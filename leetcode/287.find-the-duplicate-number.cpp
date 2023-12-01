/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (59.36%)
 * Likes:    21842
 * Dislikes: 3784
 * Total Accepted:    1.4M
 * Total Submissions: 2.4M
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * Given an array of integers nums containing n + 1 integers where each integer
 * is in the range [1, n] inclusive.
 *
 * There is only one repeated number in nums, return this repeated number.
 *
 * You must solve the problem without modifying the array nums and uses only
 * constant extra space.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3,4,2,2]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,1,3,4,2]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^5
 * nums.length == n + 1
 * 1 <= nums[i] <= n
 * All the integers in nums appear only once except for precisely one integer
 * which appears two or more times.
 *
 *
 *
 * Follow up:
 *
 *
 * How can we prove that at least one duplicate number must exist in nums?
 * Can you solve the problem in linear runtime complexity?
 *
 *
 */

/*

in: vec<int>
out: int
return the value that we are missing.

- all numbers in the array is a positive integer [1, +inf]
- want o(1) space

? FOLLOW UP # 1
- want o(n) time

? FOLLOW UP #1
Proof that at least one dupe must be in the array:
the length of the array is n + 1, and the range is [1, n] inclusive.
For example,
    -> when the length of the array is 5, then n = 4.
    -> Then the numbers in the range [1, 4].
    -> There are only n unique numbers possible, but we have n + 1 numbers
    -> so at least 1 element must be a dupe

logic:
- all numbers are unique except one number, that number is repeated 1 to n times

we can use two pointers logic:
one slow, one fast

this way, we will eventually find the number that is a duplicate

0 1 2 3 4, len = 5
1 3 4 2 2

0 1 2 3 4, len = 5
3 1 3 4 2

0 1 2 3 4 5 6 7 8 9
2 5 9 6 9 3 8 9 7 1

*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int findDuplicate(vector<int>& nums)
    {
        int L = nums[0];
        int R = nums[nums[0]];

        while (L != R)
        {
            L = nums[L];
            R = nums[nums[R]];
        }

        int L2 = 0;
        while (L2 != L)
        {
            L = nums[L];
            L2 = nums[L2];
        }

        return L;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    /* code */
    Solution obj;

    vector<int> v1 = {1, 3, 4, 2, 2};
    vector<int> v2 = {3, 1, 3, 4, 2};
    vector<int> v3 = {2, 2, 2, 2, 2};
    vector<int> v4 = {1, 1};
    vector<int> v5 = {1, 3, 4, 2, 1};
    vector<int> v6 = {4, 3, 1, 4, 2};
    vector<int> v7 = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1};

    cout << obj.findDuplicate(v1) << "\n";  // 2
    cout << "\n";
    cout << obj.findDuplicate(v2) << "\n";  // 3
    cout << "\n";
    cout << obj.findDuplicate(v3) << "\n";  // 2
    cout << "\n";
    cout << obj.findDuplicate(v4) << "\n";  // 1
    cout << "\n";
    cout << obj.findDuplicate(v5) << "\n";  // 1
    cout << "\n";
    cout << obj.findDuplicate(v6) << "\n";  // 4
    cout << "\n";
    cout << obj.findDuplicate(v7) << "\n";  // 9
    cout << "\n";
    return 0;
}
