/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 *
 * https://leetcode.com/problems/keys-and-rooms/description/
 *
 * algorithms
 * Medium (72.27%)
 * Likes:    5785
 * Dislikes: 254
 * Total Accepted:    373.3K
 * Total Submissions: 516.6K
 * Testcase Example:  '[[1],[2],[3],[]]'
 *
 * There are n rooms labeled from 0 to n - 1 and all the rooms are locked
 * except for room 0. Your goal is to visit all the rooms. However, you cannot
 * enter a locked room without having its key.
 *
 * When you visit a room, you may find a set of distinct keys in it. Each key
 * has a number on it, denoting which room it unlocks, and you can take all of
 * them with you to unlock the other rooms.
 *
 * Given an array rooms where rooms[i] is the set of keys that you can obtain
 * if you visited room i, return true if you can visit all the rooms, or false
 * otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: rooms = [[1],[2],[3],[]]
 * Output: true
 * Explanation:
 * We visit room 0 and pick up key 1.
 * We then visit room 1 and pick up key 2.
 * We then visit room 2 and pick up key 3.
 * We then visit room 3.
 * Since we were able to visit every room, we return true.
 *
 *
 * Example 2:
 *
 *
 * Input: rooms = [[1,3],[3,0,1],[2],[0]]
 * Output: false
 * Explanation: We can not enter room number 2 since the only key that unlocks
 * it is in that room.
 *
 *
 *
 * Constraints:
 *
 *
 * n == rooms.length
 * 2 <= n <= 1000
 * 0 <= rooms[i].length <= 1000
 * 1 <= sum(rooms[i].length) <= 3000
 * 0 <= rooms[i][j] < n
 * All the values of rooms[i] are unique.
 *
 *
 */
/*

in: vector<vector<int>>
out: bool

constraints: all rooms have a key that maps to a valid room

in each cell, we have a list of cells that we can not visit
we want to figure out if we can visit all the rooms

use a set to keep track of all the cells we can visit (starting with room 1)
use another set to keep track of the cells we have already visited (so we don't need to visit it multiple times)

[1 3] [3 0 1] [2] [0]



*/
#include "includes.h"
// @lc code=start
class Solution
{
public:
    void dfs(std::vector<std::vector<int>> &rooms, int i, int &count, std::unordered_set<int> &visited)
    {
        if (visited.count(i))
        {
            return;
        }

        visited.insert(i);
        count++;

        for (int key = 0; key < rooms[i].size(); ++key)
        {
            dfs(rooms, rooms[i][key], count, visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        std::unordered_set<int> visited;
        int count = 0;
        dfs(rooms, 0, count, visited);
        return count == rooms.size();
    }
};
// @lc code=end

int main()
{
    Solution obj;

    std::vector<std::vector<int>> v{{1, 3}, {3, 0, 1}, {2}, {0}};
    obj.canVisitAllRooms(v);
}