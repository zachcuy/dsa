/*
 * @lc app=leetcode id=1637 lang=cpp
 *
 * [1637] Widest Vertical Area Between Two Points Containing No Points
 */

/*
    given intervals, we find the largest difference that does not have another point that is in
   that...

   we can sort and find the one with the biggest difference...
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    int maxWidthOfVerticalArea(vector<vector<int>>& points)
    {
        vector<int> p;
        for (int i = 0; i < points.size(); ++i)
        {
            p.push_back(points[i][0]);
        }

        sort(p.begin(), p.end());

        int maxWidth = 0;
        for (int i = 1; i < p.size(); ++i)
        {
            maxWidth = max(p[i] - p[i - 1], maxWidth);
        }

        return maxWidth;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<vector<int>> v1{{8, 7}, {9, 9}, {7, 4}, {9, 7}};
    vector<vector<int>> v2{{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}};

    dump(obj.maxWidthOfVerticalArea(v1));
    dump(obj.maxWidthOfVerticalArea(v2));
    return 0;
}
