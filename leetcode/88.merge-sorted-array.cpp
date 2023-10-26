/*

the vectors are already sorted in ascending order. return in ascending order

we do not return a vector of sorted values, we want to do it in nums1

nums1 already has enough space to accommodate both nums1 and nums2

inputs:
[1, 2, 3, 0, 0, 0]
[2, 5, 6]

result:[1, 2, 2, 3, 5, 6]

if n1 is already smaller, increment n1
if n2 is smaller, then insert n2 into n1 shift n1 to the end

 0 1 2 3 4 5
[2 2 3 0 0 0]

 0 1 2
[1 5 6]

ptr = 3 + 3 - (3) = 3
[2 2 3 1 0 0]

[2 2 1 3 0 0]
ptr = 2

[2 1 2 3 0 0]
ptr = 1

[1 2 2 3 0 0]
ptr = 0


*/
#include "includes.h"

class Solution
{
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {

        if (n == 1 and m == 0)
        {
            nums1 = nums2;
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                int n1_ptr = m + i;
                nums1[n1_ptr] = nums2[i];

                while (n1_ptr > 0 and nums1[n1_ptr] < nums1[n1_ptr - 1])
                {
                    // swap
                    int tmp = nums1[n1_ptr - 1];
                    nums1[n1_ptr - 1] = nums1[n1_ptr];
                    nums1[n1_ptr] = tmp;

                    n1_ptr--;
                }
            }
        }
    }
};

int main()
{
    Solution obj = Solution();

    std::vector<int> nums1{1, 2, 3, 0, 0, 0};
    // std::vector<int> nums1{0, 0, 0, 0, 0};
    int m = 3;
    std::vector<int> nums2{2, 5, 6};
    // std::vector<int> nums2{1, 2, 3, 4, 5};
    int n = 3;

    obj.merge(nums1, m, nums2, n);

    return 0;
}