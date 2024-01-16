/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int findShortestSubArray(vector<int>& nums)
    {
        unordered_map<int, int> freq;
        int highestFreq = 0;
        for (const auto& num : nums)
        {
            freq[num]++;
            highestFreq = max(highestFreq, freq[num]);
        }

        unordered_map<int, int> first;
        unordered_map<int, int> last;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (freq[nums[i]] == highestFreq)
            {
                if (!first.count(nums[i]))
                {
                    first[nums[i]] = i;
                }
                last[nums[i]] = i;
            }
        }

        int minLength = 50001;
        for (auto [key, firstIdx] : first)
        {
            minLength = min(minLength, last[key] - firstIdx + 1);
        }

        return minLength;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{1, 2, 2, 3, 1};
    vector<int> v2{1, 2, 2, 3, 1, 4, 2};
    vector<int> v3{2, 1};

    dump(obj.findShortestSubArray(v1));
    dump(obj.findShortestSubArray(v2));
    dump(obj.findShortestSubArray(v3));
    return 0;
}