/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int maxProduct(vector<int>& nums)
    {
        int maxProduct = nums[0];
        int curProd = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (curProd == 0)
            {
                curProd = nums[i];
            }
            else
            {
                curProd *= nums[i];
            }
            maxProduct = max(maxProduct, curProd);
        }

        curProd = nums[nums.size() - 1];
        maxProduct = max(maxProduct, curProd);
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            if (curProd == 0)
            {
                curProd = nums[i];
            }
            else
            {
                curProd *= nums[i];
            }
            maxProduct = max(maxProduct, curProd);
        }

        return maxProduct;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<int> v1{2, 3, -2, 4};
    vector<int> v2{-2, 0, -1};
    vector<int> v3{2, 3, -2, 4, -1, -2, 8, -3};
    vector<int> v4{2, 3, -2, 4, 1, -2, 8, -3};
    vector<int> v5{0, 2};
    vector<int> v6{2, 0, -2, 4, 1, -2, 8, -3};

    dump(obj.maxProduct(v1));  // 6
    dump(obj.maxProduct(v2));  // 0
    dump(obj.maxProduct(v3));  // 2304
    dump(obj.maxProduct(v4));  // 768
    dump(obj.maxProduct(v5));  // 2
    dump(obj.maxProduct(v6));  // 192

    return 0;
}