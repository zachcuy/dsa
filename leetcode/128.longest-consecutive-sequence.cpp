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

intuition: minheap then count (reset when cur != prev + 1)

intuition #2: union find



*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int longestConsecutive(vector<int>& nums)
    {
        if (nums.size() <= 1)
        {
            return nums.size();
        }

        // min heap
        std::priority_queue<int, vector<int>, std::greater<int>> pq;
        for (auto& el : nums)
        {
            pq.push(el);
        }

        int prev = pq.top();
        pq.pop();
        int maxCount = 1;
        int count = 1;
        while (!pq.empty())
        {
            int cur = pq.top();
            pq.pop();

            if (cur == prev + 1)
            {
                // increment count and update prev
                count++;

                // update max
                if (count > maxCount)
                {
                    maxCount = count;
                }
            }
            else
            {
                // reset count
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

    cout << obj.longestConsecutive(v1) << "\n";
    cout << obj.longestConsecutive(v2) << "\n";

    return 0;
}
