/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (57.88%)
 * Likes:    21565
 * Dislikes: 470
 * Total Accepted:    2.4M
 * Total Submissions: 4.1M
 * Testcase Example:
 * '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands.
 *
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are
 * all surrounded by water.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
 *
 *
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    void countIsland(vector<vector<char>>& grid, int i, int j, int N, int M)
    {
        if (i < 0 or i >= N or j < 0 or j >= M)
        {
            return;
        }
        else if (grid[i][j] == '0')
        {
            return;
        }

        grid[i][j] = '0';
        countIsland(grid, i + 1, j, N, M);
        countIsland(grid, i - 1, j, N, M);
        countIsland(grid, i, j + 1, N, M);
        countIsland(grid, i, j - 1, N, M);
    }
    int numIslands(vector<vector<char>>& grid)
    {
        int count = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();

        for (int i = 0; i < grid.size(); ++i)
        {
            for (size_t j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    countIsland(grid, i, j, ROWS, COLS);
                }
            }
        }

        cout << count << "\n";
        return count;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<vector<char>> v1{{'1', '1', '1', '1', '0'},
                            {'1', '1', '0', '1', '0'},
                            {'1', '1', '0', '0', '0'},
                            {'0', '0', '0', '0', '0'}};

    obj.numIslands(v1);
    return 0;
}
