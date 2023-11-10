/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 *
 * https://leetcode.com/problems/number-of-provinces/description/
 *
 * algorithms
 * Medium (65.53%)
 * Likes:    9123
 * Dislikes: 328
 * Total Accepted:    773K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * There are n cities. Some of them are connected, while some are not. If city
 * a is connected directly with city b, and city b is connected directly with
 * city c, then city a is connected indirectly with city c.
 *
 * A province is a group of directly or indirectly connected cities and no
 * other cities outside of the group.
 *
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
 * i^th city and the j^th city are directly connected, and isConnected[i][j] =
 * 0 otherwise.
 *
 * Return the total number of provinces.
 *
 *
 * Example 1:
 *
 *
 * Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 200
 * n == isConnected.length
 * n == isConnected[i].length
 * isConnected[i][j] is 1 or 0.
 * isConnected[i][i] == 1
 * isConnected[i][j] == isConnected[j][i]
 *
 *
 */

#include "includes.h"
// @lc code=start
class DisjointSet
{
public:
    std::vector<int> nodes;
    std::vector<int> size;

    DisjointSet(int n)
    {
        nodes.resize(n);
        size.resize(n);
        for (int i = 0; i < n; ++i)
        {
            nodes[i] = i;
            size[i] = 1;
        }
    }

    int find(int id)
    {
        // using PATH COMPRESSION
        // get parent node, the parent is the one that points to itself
        if (nodes[id] == id)
        {
            return id;
        }
        return nodes[id] = find(nodes[id]);
    }

    void uni(int a, int b)
    {
        // combine two nodes by getting the parents of both nodes
        // then pointing one node to the other

        // get parents of both nodes
        a = find(a);
        b = find(b);

        // only combine if they aren't the same set already
        // using UNION BY SIZE
        if (a != b)
        {
            if (size[a] < size[b])
            {
                swap(a, b);
            }
            nodes[b] = a;
            size[a] += size[b];
        }
    }
};

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        DisjointSet S(n);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (isConnected[i][j] == 1)
                {
                    S.uni(i, j);
                }
            }
        }

        std::unordered_set<int> provinces;
        for (int i = 0; i < n; ++i)
        {
            // update the connections before we check
            S.find(i);
            provinces.insert(S.nodes[i]);
        }
        std::cout << "\n";

        return provinces.size();
    }
};
// @lc code=end

int main()
{
    Solution obj;

    std::vector<std::vector<int>> v1{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    std::vector<std::vector<int>> v2{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::vector<std::vector<int>> v3{{1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                                     {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                     {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                     {0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                     {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
                                     {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                                     {0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
                                     {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                                     {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0},
                                     {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
                                     {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                     {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
                                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}};

    // std::cout << obj.findCircleNum(v1) << "\n";
    // std::cout << obj.findCircleNum(v2) << "\n";
    std::cout << obj.findCircleNum(v3) << "\n";
}