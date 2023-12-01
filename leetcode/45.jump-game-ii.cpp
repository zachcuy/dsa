/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (40.17%)
 * Likes:    13604
 * Dislikes: 484
 * Total Accepted:    1M
 * Total Submissions: 2.6M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * You are given a 0-indexed array of integers nums of length n. You are
 * initially positioned at nums[0].
 *
 * Each element nums[i] represents the maximum length of a forward jump from
 * index i. In other words, if you are at nums[i], you can jump to any nums[i +
 * j] where:
 *
 *
 * 0 <= j <= nums[i] and
 * i + j < n
 *
 *
 * Return the minimum number of jumps to reach nums[n - 1]. The test cases are
 * generated such that you can reach nums[n - 1].
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2. Jump
 * 1 step from index 0 to 1, then 3 steps to the last index.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,3,0,1,4]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 1000
 * It's guaranteed that you can reach nums[n - 1].
 *
 *
 */

/*

DP problem, since we're trying to minimize something

we can always reach the end

0 1 2 3 4
2 3 1 1 4

base case: reached nums.size() - 1



*/

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int jump(vector<int>& nums)
    {
        unordered_set<int> s;
        s.insert(0);
        queue<int> q;
        q.push(0);

        int count = 0;
        while (q.size())
        {
            int len = q.size();

            for (size_t i = 0; i < len; i++)
            {
                int cur = q.front();
                q.pop();

                if (cur >= nums.size() - 1)
                {
                    return count;
                }

                for (size_t j = 1; j <= nums[cur]; j++)
                {
                    if (!s.count(cur + j))
                    {
                        s.insert(cur + j);
                        q.push(cur + j);
                    }
                }
            }
            count++;
        }

        return -1;
    }
};
// @lc code=end

int main()
{
    Solution obj;

    vector<int> v1{2, 3, 1, 1, 4};
    vector<int> v2{2, 3, 0, 1, 4};

    cout << obj.jump(v1) << "\n";
    cout << obj.jump(v2) << "\n";

    return 0;
}