#include "includes.h"
/*

keep track of the number of values that are NOT the value of val

count how many times we find val in the vector, and subtract that from the vector size

move the values to the end

since we don't have to worry about order, we can just swap each time we find val with the value at the end

the 'end' is the size of vector - number of times we've encountered val - 1

*/

class Solution
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        int left = 0;
        int right = nums.size() - 1;
        int count = 0; // tracks number of times we encounter 'val'

        // move right while counting
        while (right >= 0 and nums[right] == val)
        {
            right--;
            count++;
        }

        while (left < nums.size() - 1 and right >= 0 and left != right)
        {
            if (nums[left] == val)
            {
                // swap
                int tmp = nums[right];
                nums[right] = nums[left];
                nums[left] = tmp;

                // increment pointers
                right--;
                count++;
            }
            left++;
        }

        return nums.size() - count;
    }
};

int main()
{

    Solution obj = Solution();

    std::vector<int> nums{4, 5};
    int val = 4;

    int count = obj.removeElement(nums, val);
    for (int i = 0; i < count; ++i)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << "\n";

    return 0;
}