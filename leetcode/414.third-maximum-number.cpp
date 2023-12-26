/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int thirdMax(vector<int>& nums)
    {
        priority_queue<int> pq;
        unordered_set<int> s;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!s.count(nums[i]))
            {
                pq.push(nums[i]);
                s.insert(nums[i]);
            }
        }

        if (pq.size() >= 3)
        {
            pq.pop();
            pq.pop();
            return pq.top();
        }
        else
        {
            return pq.top();
        }
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> v1{3, 2, 1};
    vector<int> v2{1, 2};
    vector<int> v3{2, 2, 3, 1};

    dump(obj.thirdMax(v1));
    dump(obj.thirdMax(v2));
    dump(obj.thirdMax(v3));
    return 0;
}