/*
 * @lc app=leetcode id=868 lang=cpp
 *
 * [868] Binary Gap
 *
 * https://leetcode.com/problems/binary-gap/description/
 *
 * algorithms
 * Easy (62.66%)
 * Likes:    603
 * Dislikes: 648
 * Total Accepted:    76K
 * Total Submissions: 120.9K
 * Testcase Example:  '22'
 *
 * Given a positive integer n, find and return the longest distance between any
 * two adjacent 1's in the binary representation of n. If there are no two
 * adjacent 1's, return 0.
 *
 * Two 1's are adjacent if there are only 0's separating them (possibly no
 * 0's). The distance between two 1's is the absolute difference between their
 * bit positions. For example, the two 1's in "1001" have a distance of 3.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 22
 * Output: 2
 * Explanation: 22 in binary is "10110".
 * The first adjacent pair of 1's is "10110" with a distance of 2.
 * The second adjacent pair of 1's is "10110" with a distance of 1.
 * The answer is the largest of these two distances, which is 2.
 * Note that "10110" is not a valid pair since there is a 1 separating the two
 * 1's underlined.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 8
 * Output: 0
 * Explanation: 8 in binary is "1000".
 * There are not any adjacent pairs of 1's in the binary representation of 8,
 * so we return 0.
 *
 *
 * Example 3:
 *
 *
 * Input: n = 5
 * Output: 2
 * Explanation: 5 in binary is "101".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^9
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int binaryGap(int n)
    {
        const int bitSize = sizeof(n) * 8;
        string bits = bitset<bitSize>(n).to_string();

        int maxDistance = 0;
        int prev = -1;
        for (int i = 0; i < bits.size(); ++i)
        {
            // go until we find the first 1
            if (bits[i] == '1')
            {
                if (prev == -1)
                {
                    prev = i;
                }
                else
                {
                    maxDistance = max(abs(i - prev), maxDistance);
                    prev = i;
                }
            }
        }

        return maxDistance;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution obj;

    cout << obj.binaryGap(22) << "\n";
    cout << obj.binaryGap(8) << "\n";
    cout << obj.binaryGap(5) << "\n";
    return 0;
}
