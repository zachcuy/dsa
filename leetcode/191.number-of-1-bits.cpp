/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

/*
    convert the number to a bitset and then go through bits, count all ones
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int hammingWeight(uint32_t n)
    {
        bitset<32> bits{n};

        int count = 0;
        for (int i = 0; i < bits.size(); ++i)
        {
            if (bits[i] == 1)
            {
                count++;
            }
        }
        return count;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution obj;
    int n1 = 0b00000000000000000000000000001011;
    int n2 = 0b00000000000000000000000010000000;
    int n3 = 0b11111111111111111111111111111101;

    dump(obj.hammingWeight(n1));  // 3
    dump(obj.hammingWeight(n2));  // 1
    dump(obj.hammingWeight(n3));  // 31
    return 0;
}