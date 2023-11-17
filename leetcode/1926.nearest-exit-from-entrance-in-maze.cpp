/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 *
 * https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/
 *
 * algorithms
 * Medium (47.53%)
 * Likes:    2114
 * Dislikes: 80
 * Total Accepted:    108.2K
 * Total Submissions: 228.9K
 * Testcase Example:  '[["+","+",".","+"],[".",".",".","+"],["+","+","+","."]]\n[1,2]'
 *
 * You are given an m x n matrix maze (0-indexed) with empty cells (represented
 * as '.') and walls (represented as '+'). You are also given the entrance of
 * the maze, where entrance = [entrancerow, entrancecol] denotes the row and
 * column of the cell you are initially standing at.
 *
 * In one step, you can move one cell up, down, left, or right. You cannot step
 * into a cell with a wall, and you cannot step outside the maze. Your goal is
 * to find the nearest exit from the entrance. An exit is defined as an empty
 * cell that is at the border of the maze. The entrance does not count as an
 * exit.
 *
 * Return the number of steps in the shortest path from the entrance to the
 * nearest exit, or -1 if no such path exists.
 *
 *
 * Example 1:
 *
 *
 * Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]],
 * entrance = [1,2]
 * Output: 1
 * Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
 * Initially, you are at the entrance cell [1,2].
 * - You can reach [1,0] by moving 2 steps left.
 * - You can reach [0,2] by moving 1 step up.
 * It is impossible to reach [2,3] from the entrance.
 * Thus, the nearest exit is [0,2], which is 1 step away.
 *
 *
 * Example 2:
 *
 *
 * Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
 * Output: 2
 * Explanation: There is 1 exit in this maze at [1,2].
 * [1,0] does not count as an exit since it is the entrance cell.
 * Initially, you are at the entrance cell [1,0].
 * - You can reach [1,2] by moving 2 steps right.
 * Thus, the nearest exit is [1,2], which is 2 steps away.
 *
 *
 * Example 3:
 *
 *
 * Input: maze = [[".","+"]], entrance = [0,0]
 * Output: -1
 * Explanation: There are no exits in this maze.
 *
 *
 *
 * Constraints:
 *
 *
 * maze.length == m
 * maze[i].length == n
 * 1 <= m, n <= 100
 * maze[i][j] is either '.' or '+'.
 * entrance.length == 2
 * 0 <= entrancerow < m
 * 0 <= entrancecol < n
 * entrance will always be an empty cell.
 *
 *
 */

/*

in: 2d vec, 1d vec
out: int (number of steps/levels to get to end)

we want shortest path to exit (signified by an open cell at the edges of the maze)

walls are +
open spots are .

*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
        visited[entrance[0]][entrance[1]] = true;

        std::queue<vector<int>> q;
        q.push(entrance);

        // bounds of maze
        size_t ROWS = maze.size();
        size_t COLS = maze[0].size();
        int level = 0;

        while (q.size())
        {
            int len = q.size();
            for (size_t i = 0; i < len; i++)
            {
                // get cell
                vector<int> cell = q.front();
                q.pop();

                if ((cell[0] == 0 or cell[0] == ROWS - 1 or cell[1] == 0 or cell[1] == COLS - 1) and
                    (cell != entrance))
                {
                    return level;
                }

                // add new cells: up, right, down, left
                vector<vector<int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for (auto& d : moves)
                {
                    int x = cell[0], y = cell[1];
                    int dx = d[0], dy = d[1];
                    if (x + dx >= 0 and x + dx < ROWS and y + dy >= 0 and y + dy < COLS and
                        !visited[x + dx][y + dy] and maze[x + dx][y + dy] == '.')
                    {
                        visited[x + dx][y + dy] = true;
                        q.push({x + dx, y + dy});
                    }
                }
            }
            level++;
        }

        return -1;
    }
};
// @lc code=end

int main()
{
    Solution obj;

    vector<vector<char>> v1{{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
    vector<vector<char>> v2{{'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}};
    vector<vector<char>> v3{{'.', '+'}};

    vector<int> e1{1, 2};
    vector<int> e2{1, 0};
    vector<int> e3{0, 0};
    cout << obj.nearestExit(v1, e1) << "\n\n";
    cout << obj.nearestExit(v2, e2) << "\n\n";
    cout << obj.nearestExit(v3, e3) << "\n\n";
}