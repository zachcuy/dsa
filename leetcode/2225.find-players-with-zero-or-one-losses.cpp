/*
 * @lc app=leetcode id=2225 lang=cpp
 *
 * [2225] Find Players With Zero or One Losses
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        std::unordered_map<int, int> freq_losers;

        for (const auto& match : matches)
        {
            int loser = match[1];
            freq_losers[loser]++;
        }

        std::unordered_set<int> winners;
        vector<int> W;
        for (const auto& match : matches)
        {
            int winner = match[0];
            if (!freq_losers[winner] and winners.insert(winner).second)
            {
                W.push_back(winner);
            }
        }
        std::sort(W.begin(), W.end());

        vector<int> L;
        for (const auto& [loser, losses] : freq_losers)
        {
            if (losses == 1)
            {
                L.push_back(loser);
            }
        }
        std::sort(L.begin(), L.end());

        return {W, L};
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<vector<int>> v1{{1, 3}, {2, 3}, {3, 6}, {5, 6},  {5, 7},
                           {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};

    dump(obj.findWinners(v1));
    return 0;
}