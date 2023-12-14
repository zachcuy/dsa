/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 *
 * https://leetcode.com/problems/check-if-n-and-its-double-exist/description/
 *
 * algorithms
 * Easy (36.77%)
 * Likes:    1843
 * Dislikes: 194
 * Total Accepted:    320.6K
 * Total Submissions: 869.8K
 * Testcase Example:  '[10,2,5,3]'
 *
 * Given an array arr of integers, check if there exist two indices i and j
 * such that :
 *
 *
 * i != j
 * 0 <= i, j < arr.length
 * arr[i] == 2 * arr[j]
 *
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [10,2,5,3]
 * Output: true
 * Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [3,1,7,11]
 * Output: false
 * Explanation: There is no i and j that satisfy the conditions.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= arr.length <= 500
 * -10^3 <= arr[i] <= 10^3
 *
 *
 */

/*

*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    bool checkIfExist(vector<int>& arr)
    {
        map<int, int> m;

        for (int i = 0; i < arr.size(); ++i)
        {
            m[arr[i]] = i;
        }

        for (int i = 0; i < arr.size(); ++i)
        {
            if (m.count(arr[i] * 2) and i != m[arr[i] * 2])
            {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{7, 1, 14, 11};

    obj.checkIfExist(v1);
    return 0;
}