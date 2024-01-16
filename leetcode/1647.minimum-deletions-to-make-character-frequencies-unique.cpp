/*
 * @lc app=leetcode id=1647 lang=cpp
 *
 * [1647] Minimum Deletions to Make Character Frequencies Unique
 */

/*
    ceabaacb

    a: 3
    b: 2
    c: 2
    e: 1

    delete 1 e -> delete 1 c or delete 1 b
    out: 2
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int minDeletions(string s)
    {
        unordered_map<char, int> freq;
        for (auto& c : s)
        {
            freq[c]++;
        }

        unordered_set<int> freqUsed;
        int count = 0;
        for (const auto& [key, val] : freq)
        {
            if (!freqUsed.count(val))
            {
                // add to used
                freqUsed.insert(val);
            }
            else
            {
                // find the first empty frequency
                int tmp = val;
                while (tmp > 0 and freqUsed.count(tmp))
                {
                    tmp--;
                }

                // add to freqUsed and keep count
                freqUsed.insert(tmp);
                count += (val - tmp);
            }
        }

        return count;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    string s1{"aab"};
    string s2{"aaabbbcc"};
    string s3{"ceabaacb"};

    dump(obj.minDeletions(s1));  // 0
    dump(obj.minDeletions(s2));  // 2
    dump(obj.minDeletions(s3));  // 2
    return 0;
}