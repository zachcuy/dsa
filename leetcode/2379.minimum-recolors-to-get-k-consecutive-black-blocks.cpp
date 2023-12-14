/*
 * @lc app=leetcode id=2379 lang=cpp
 *
 * [2379] Minimum Recolors to Get K Consecutive Black Blocks
 *
 * https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/
 *
 * algorithms
 * Easy (58.19%)
 * Likes:    679
 * Dislikes: 19
 * Total Accepted:    44.7K
 * Total Submissions: 76.6K
 * Testcase Example:  '"WBBWWBBWBW"\n7'
 *
 * You are given a 0-indexed string blocks of length n, where blocks[i] is
 * either 'W' or 'B', representing the color of the i^th block. The characters
 * 'W' and 'B' denote the colors white and black, respectively.
 *
 * You are also given an integer k, which is the desired number of consecutive
 * black blocks.
 *
 * In one operation, you can recolor a white block such that it becomes a black
 * block.
 *
 * Return the minimum number of operations needed such that there is at least
 * one occurrence of k consecutive black blocks.
 *
 *
 * Example 1:
 *
 *
 * Input: blocks = "WBBWWBBWBW", k = 7
 * Output: 3
 * Explanation:
 * One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd,
 * and 4th blocks
 * so that blocks = "BBBBBBBWBW".
 * It can be shown that there is no way to achieve 7 consecutive black blocks
 * in less than 3 operations.
 * Therefore, we return 3.
 *
 *
 * Example 2:
 *
 *
 * Input: blocks = "WBWBBBW", k = 2
 * Output: 0
 * Explanation:
 * No changes need to be made, since 2 consecutive black blocks already exist.
 * Therefore, we return 0.
 *
 *
 *
 * Constraints:
 *
 *
 * n == blocks.length
 * 1 <= n <= 100
 * blocks[i] is either 'W' or 'B'.
 * 1 <= k <= n
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
    int minimumRecolors(string blocks, int k)
    {
        // get initial window
        int countWhite = 0;
        for (int i = 0; i < k; ++i)
        {
            if (blocks[i] == 'W')
            {
                countWhite++;
            }
        }

        int minSwaps = countWhite;
        int ptr = k;
        while (ptr < blocks.size())
        {
            int t1 = ptr - k;
            int t2 = ptr;
            if (blocks[ptr - k] == 'W')  // exiting window
            {
                countWhite--;
            }

            if (blocks[ptr] == 'W')  // entering window
            {
                countWhite++;
            }

            minSwaps = min(minSwaps, countWhite);
            ptr++;
        }

        return max(minSwaps, 0);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution obj;
    string s1 = "WBBWWBBWBW";
    string s2 = "WBWBBBW";
    string s3 = "WBBWWWWBBWWBBBBWWBBWWBBBWWBBBWWWBWBWW";

    // dump(obj.minimumRecolors(s1, 7));
    // dump(obj.minimumRecolors(s2, 2));
    dump(obj.minimumRecolors(s3, 15));  // 6
    return 0;
}