/*
 * @lc app=leetcode id=1496 lang=cpp
 *
 * [1496] Path Crossing
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    bool isPathCrossing(string path)
    {
        set<pair<int, int>> points;
        points.insert({0, 0});

        int x = 0, y = 0;
        for (auto& move : path)
        {
            switch (move)
            {
                case 'N':
                    y++;
                    break;
                case 'E':
                    x++;
                    break;
                case 'S':
                    y--;
                    break;
                case 'W':
                    x--;
                    break;
                default:
                    break;
            }

            if (points.count({x, y}))
            {
                return true;
            }
            points.insert({x, y});
        }

        return false;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    string s1{"NES"};
    string s2{"NESWW"};

    dump(obj.isPathCrossing(s1));  // F
    dump(obj.isPathCrossing(s2));  // T

    return 0;
}