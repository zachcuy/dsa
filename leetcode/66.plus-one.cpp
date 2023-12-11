/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (44.27%)
 * Likes:    8653
 * Dislikes: 5272
 * Total Accepted:    2M
 * Total Submissions: 4.5M
 * Testcase Example:  '[1,2,3]'
 *
 * You are given a large integer represented as an integer array digits, where
 * each digits[i] is the i^th digit of the integer. The digits are ordered from
 * most significant to least significant in left-to-right order. The large
 * integer does not contain any leading 0's.
 *
 * Increment the large integer by one and return the resulting array of
 * digits.
 *
 *
 * Example 1:
 *
 *
 * Input: digits = [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * Incrementing by one gives 123 + 1 = 124.
 * Thus, the result should be [1,2,4].
 *
 *
 * Example 2:
 *
 *
 * Input: digits = [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * Incrementing by one gives 4321 + 1 = 4322.
 * Thus, the result should be [4,3,2,2].
 *
 *
 * Example 3:
 *
 *
 * Input: digits = [9]
 * Output: [1,0]
 * Explanation: The array represents the integer 9.
 * Incrementing by one gives 9 + 1 = 10.
 * Thus, the result should be [1,0].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= digits.length <= 100
 * 0 <= digits[i] <= 9
 * digits does not contain any leading 0's.
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    vector<int> plusOne(vector<int>& digits)
    {
        /*
        go through vector in reverse order, add one
        if equal to 10, then we have a carry of 1
        add to next until carry is 0
        */

        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            int newDigit = digits[i] + carry;
            if (newDigit == 10)
            {
                carry = 1;
                digits[i] = 0;
            }
            else
            {
                carry = 0;
                digits[i] = newDigit;
            }
        }

        if (carry == 1)
        {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{1, 2, 3};
    vector<int> v2{4, 3, 2, 1};
    vector<int> v3{9};
    vector<int> v4{9, 9, 9, 9};
    vector<int> v5{9, 8, 9, 9};

    dump(obj.plusOne(v1));
    dump(obj.plusOne(v2));
    dump(obj.plusOne(v3));
    dump(obj.plusOne(v4));
    dump(obj.plusOne(v5));

    return 0;
}