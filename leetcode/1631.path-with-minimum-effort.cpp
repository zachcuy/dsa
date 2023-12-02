/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 *
 * https://leetcode.com/problems/path-with-minimum-effort/description/
 *
 * algorithms
 * Medium (59.36%)
 * Likes:    5526
 * Dislikes: 188
 * Total Accepted:    225.6K
 * Total Submissions: 380.3K
 * Testcase Example:  '[[1,2,2],[3,8,2],[5,3,5]]'
 *
 * You are a hiker preparing for an upcoming hike. You are given heights, a 2D
 * array of size rows x columns, where heights[row][col] represents the height
 * of cell (row, col). You are situated in the top-left cell, (0, 0), and you
 * hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e.,
 * 0-indexed). You can move up, down, left, or right, and you wish to find a
 * route that requires the minimum effort.
 *
 * A route's effort is the maximum absolute difference in heights between two
 * consecutive cells of the route.
 *
 * Return the minimum effort required to travel from the top-left cell to the
 * bottom-right cell.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
 * Output: 2
 * Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2
 * in consecutive cells.
 * This is better than the route of [1,2,2,2,5], where the maximum absolute
 * difference is 3.
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
 * Output: 1
 * Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1
 * in consecutive cells, which is better than route [1,3,5,3,5].
 *
 *
 * Example 3:
 *
 *
 * Input: heights =
 * [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
 * Output: 0
 * Explanation: This route does not require any effort.
 *
 *
 *
 * Constraints:
 *
 *
 * rows == heights.length
 * columns == heights[i].length
 * 1 <= rows, columns <= 100
 * 1 <= heights[i][j] <= 10^6
 *
 */

/*
Dijkstra's with priority queue
*/
#include "includes.h"
// @lc code=start
struct Comparator
{
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b)
    {
        return a.first > b.first;
    }
};

class Solution
{
   public:
    // AC
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Comparator> pq;
        set<pair<int, int>> visited;
        visited.insert({0, 0});
        pq.push({0, {0, 0}});  // we start at [0, 0]
        pair<int, int> goal = {heights.size() - 1, heights[0].size() - 1};

        int globalMin = INT_MAX;
        while (!pq.empty())
        {
            // get next smallest weight
            auto [curCost, coord] = pq.top();
            pq.pop();

            // if we're at the end, we can just return it
            if (coord == goal)
            {
                return curCost;
            }

            // add neighbors
            int row = coord.first;
            int col = coord.second;
            if (row + 1 < heights.size() and !visited.count({row + 1, col}))
            {
                int curHeight = heights[row][col];
                int nextHeight = heights[row + 1][col];
                int nextCost = abs(curHeight - nextHeight);
                pq.push({max(nextCost, curCost), {row + 1, col}});
            }
            if (row - 1 >= 0 and !visited.count({row - 1, col}))
            {
                int curHeight = heights[row][col];
                int nextHeight = heights[row - 1][col];
                int nextCost = abs(curHeight - nextHeight);
                pq.push({max(nextCost, curCost), {row - 1, col}});
            }
            if (col + 1 < heights[0].size() and !visited.count({row, col + 1}))
            {
                int curHeight = heights[row][col];
                int nextHeight = heights[row][col + 1];
                int nextCost = abs(curHeight - nextHeight);
                pq.push({max(nextCost, curCost), {row, col + 1}});
            }
            if (col - 1 >= 0 and !visited.count({row, col - 1}))
            {
                int curHeight = heights[row][col];
                int nextHeight = heights[row][col - 1];
                int nextCost = abs(curHeight - nextHeight);
                pq.push({max(nextCost, curCost), {row, col - 1}});
            }
            visited.insert({row, col});
        }

        return -1;  // default return case (this should never be reached since we can always reach
                    // the end)
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<vector<int>> v1{{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    vector<vector<int>> v2{{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
    vector<vector<int>> v3{
        {1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}};
    vector<vector<int>> v4{{3}};
    vector<vector<int>> v5{{1, 10, 6, 7, 9, 10, 4, 9}};

    cout << obj.minimumEffortPath(v1) << "\n";  // 2
    cout << obj.minimumEffortPath(v2) << "\n";  // 1
    cout << obj.minimumEffortPath(v3) << "\n";  // 0
    cout << obj.minimumEffortPath(v4) << "\n";  // 0
    cout << obj.minimumEffortPath(v5) << "\n";  // 9
    return 0;
}
