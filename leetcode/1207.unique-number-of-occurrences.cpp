/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 *
 * https://leetcode.com/problems/unique-number-of-occurrences/description/
 *
 * algorithms
 * Easy (74.19%)
 * Likes:    4289
 * Dislikes: 101
 * Total Accepted:    369.2K
 * Total Submissions: 496.5K
 * Testcase Example:  '[1,2,2,1,1,3]'
 *
 * Given an array of integers arr, return true if the number of occurrences of
 * each value in the array is unique or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [1,2,2,1,1,3]
 * Output: true
 * Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two
 * values have the same number of occurrences.
 *
 * Example 2:
 *
 *
 * Input: arr = [1,2]
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 1000
 * -1000 <= arr[i] <= 1000
 *
 *
 */
/*

in: vec<int>
out: bool
    true -> frequency of each number are unique
    false -> frequencies are not unique


use map: count elements
*/

#include "includes.h"
// @lc code=start
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        // count frequencies
        std::unordered_map<int, int> map;
        for (auto &num : arr)
        {
            map[num]++;
        }

        // check uniqueness of map values
        std::unordered_set<int> set;
        for (auto &e : map)
        {
            if (set.count(e.second))
            {
                return false;
            }
            set.insert(e.second);
        }

        return true;
    }
};
// @lc code=end

int main()
{
    Solution obj;

    std::vector<int> v1{1, 2, 2, 1, 1, 3};
    std::cout << obj.uniqueOccurrences(v1) << "\n\n";

    std::vector<int> v2{-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    std::cout << obj.uniqueOccurrences(v2) << "\n\n";

    std::vector<int> v3{1, 2};
    std::cout << obj.uniqueOccurrences(v3) << "\n\n";
}