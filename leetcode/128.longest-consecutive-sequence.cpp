/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (47.45%)
 * Likes:    18701
 * Dislikes: 863
 * Total Accepted:    1.4M
 * Total Submissions: 3M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 *
 * You must write an algorithm that runs in O(n) time.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

/*

in: vec<int>
out: count of longest consecutive sequence, order does not have to be preserved

intuition (after initial read): use min heap and then count if the next value is a value greater by
one

the reason why min heap is used is because we want o(n) time. another way of solving this would be
to sort then count.
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int longestConsecutive(vector<int>& nums)
    {
        if (!nums.size())
        {
            return 0;
        }

        // populate min heap
        std::priority_queue<int, vector<int>, std::greater<int>> pq;
        for (auto& num : nums)
        {
            pq.push(num);
        }

        // count
        size_t maxCount = 1;
        size_t count = 1;
        int prev = pq.top();
        pq.pop();

        while (pq.size())
        {
            // get next smallest
            int cur = pq.top();
            pq.pop();

            if (prev + 1 == cur)
            {
                count++;
                // check to update maxCount
                if (count > maxCount)
                {
                    maxCount = count;
                }
            }
            else
            {
                // only reset if the number changes
                if (prev != cur)
                {
                    count = 1;
                }
            }
            prev = cur;
        }

        return maxCount;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<int> v1{100, 4, 200, 1, 3, 2};
    vector<int> v2{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    vector<int> v3{1, 2, 0, 1};

    cout << obj.longestConsecutive(v1) << "\n";  // 1 2 3 4 --> 4
    cout << obj.longestConsecutive(v2) << "\n";  // 0 1 2 3 4 5 6 7 8 --> 9
    cout << obj.longestConsecutive(v3) << "\n";  // 0 1 2 --> 3
    return 0;
}
