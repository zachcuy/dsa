/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

/*
    2: 1 0

    2 ^ 2 = 10 ^ 10 = (1 xor 1) (0 xor 0) = 0 0 = 0
    2 ^ 1 = 10 ^ 01 = (1 xor 0) (0 xor 1) = 1 1 = 3
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int singleNumber(vector<int>& nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            res = (res xor nums[i]);
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<int> v1{2, 2, 1};
    vector<int> v2{4, 1, 2, 1, 2};
    vector<int> v3{1};

    dump(obj.singleNumber(v1));
    dump(obj.singleNumber(v2));
    dump(obj.singleNumber(v3));

    return 0;
}