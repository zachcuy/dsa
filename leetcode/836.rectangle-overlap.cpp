/*
 * @lc app=leetcode id=836 lang=cpp
 *
 * [836] Rectangle Overlap
 *
 * https://leetcode.com/problems/rectangle-overlap/description/
 *
 * algorithms
 * Easy (44.24%)
 * Likes:    1919
 * Dislikes: 454
 * Total Accepted:    135.1K
 * Total Submissions: 304.4K
 * Testcase Example:  '[0,0,2,2]\n[1,1,3,3]'
 *
 * An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where
 * (x1, y1) is the coordinate of its bottom-left corner, and (x2, y2) is the
 * coordinate of its top-right corner. Its top and bottom edges are parallel to
 * the X-axis, and its left and right edges are parallel to the Y-axis.
 *
 * Two rectangles overlap if the area of their intersection is positive. To be
 * clear, two rectangles that only touch at the corner or edges do not
 * overlap.
 *
 * Given two axis-aligned rectangles rec1 and rec2, return true if they
 * overlap, otherwise return false.
 *
 *
 * Example 1:
 * Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
 * Output: true
 * Example 2:
 * Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
 * Output: false
 * Example 3:
 * Input: rec1 = [0,0,1,1], rec2 = [2,2,3,3]
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * rec1.length == 4
 * rec2.length == 4
 * -10^9 <= rec1[i], rec2[i] <= 10^9
 * rec1 and rec2 represent a valid rectangle with a non-zero area.
 *
 *
 */

/*

rectangle:
    bottom-left: x1, y1
    top-right: x2, y2

    bottom-right: x2, y1
    top-left: x1, y2


rectangles overlap when (both have to be true):
    the x values of one box falls in the range of the other
    the y values of one box falls in the range of the other

checks:

    checks for x axis
    b1 < a1 < b2 or
    b1 < a2 < b2 or
    a1 < b1 < a2 or
    a1 < b2 < a2

    do the same checks for y axis

*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
    {
        pair<int, int> rec1_x = {rec1[0], rec1[2]};
        pair<int, int> rec1_y = {rec1[1], rec1[3]};

        pair<int, int> rec2_x = {rec2[0], rec2[2]};
        pair<int, int> rec2_y = {rec2[1], rec2[3]};

        if (rec1_x.first < rec2_x.second and rec1_x.first > rec2_x.first or
            rec1_x.second < rec2_x.second and rec1_x.second > rec2_x.first or
            rec2_x.first < rec1_x.second and rec2_x.first > rec1_x.first or
            rec2_x.second < rec1_x.second and rec2_x.second > rec1_x.first)
        {
            if (rec1_y.first < rec2_y.second and rec1_y.first > rec2_y.first or
                rec1_y.second < rec2_y.second and rec1_y.second > rec2_y.first or
                rec2_y.first < rec1_y.second and rec2_y.first > rec1_y.first or
                rec2_y.second < rec1_y.second and rec2_y.second > rec1_y.first)
            {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    vector<int> a1{0, 0, 2, 2};
    vector<int> a2{1, 1, 3, 3};

    vector<int> b1{0, 0, 1, 1};
    vector<int> b2{1, 0, 2, 1};

    vector<int> c1{0, 0, 1, 1};
    vector<int> c2{2, 2, 3, 3};

    vector<int> d1{7, 8, 13, 15};
    vector<int> d2{10, 8, 12, 20};

    dump(obj.isRectangleOverlap(a1, a2));
    dump(obj.isRectangleOverlap(b1, b2));
    dump(obj.isRectangleOverlap(c1, c2));
    dump(obj.isRectangleOverlap(d1, d2));
    return 0;
}