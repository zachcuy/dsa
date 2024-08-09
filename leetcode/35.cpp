#include <vector>

#include "includes.h"

class Solution
{
public:
    int searchInsert(const std::vector<int>& nums, int target)
    {
        int r = nums.size() - 1;
        int l = 0;

        while (l <= r)
        {
            int m   = (l + r) / 2;
            int num = nums[m];

            if (num == target)
            {
                return m;
            }
            else if (num > target)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        return l;
    }
};

int main()
{
    Solution obj;

    std::vector<int> v1 {1, 3, 5, 6};
    dump(obj.searchInsert(v1, 5));  // 2
    dump(obj.searchInsert(v1, 2));  // 1
    dump(obj.searchInsert(v1, 7));  // 4
    dump(obj.searchInsert(v1, 0));  // 0
}
