/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

/*
    binary search since the input vector is sorted in increasing order
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    char nextGreatestLetter(vector<char>& letters, char target)
    {
        for (auto& letter : letters)
        {
            if (letter > target)
            {
                return letter;
            }
        }

        return letters[0];
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<char> v1{'c', 'f', 'j'};
    vector<char> v2{'c', 'f', 'j'};
    vector<char> v3{'x', 'x', 'y', 'y'};

    dump(obj.nextGreatestLetter(v1, 'a'));
    dump(obj.nextGreatestLetter(v2, 'c'));
    dump(obj.nextGreatestLetter(v3, 'z'));
    return 0;
}