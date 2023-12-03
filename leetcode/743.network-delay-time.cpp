/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 *
 * https://leetcode.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (52.82%)
 * Likes:    7073
 * Dislikes: 347
 * Total Accepted:    438.3K
 * Total Submissions: 826.5K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * You are given a network of n nodes, labeled from 1 to n. You are also given
 * times, a list of travel times as directed edges times[i] = (ui, vi, wi),
 * where ui is the source node, vi is the target node, and wi is the time it
 * takes for a signal to travel from source to target.
 *
 * We will send a signal from a given node k. Return the minimum time it takes
 * for all the n nodes to receive the signal. If it is impossible for all the n
 * nodes to receive the signal, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: times = [[1,2,1]], n = 2, k = 1
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: times = [[1,2,1]], n = 2, k = 2
 * Output: -1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= n <= 100
 * 1 <= times.length <= 6000
 * times[i].length == 3
 * 1 <= ui, vi <= n
 * ui != vi
 * 0 <= wi <= 100
 * All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
 *
 *
 */

/*

k is the start node
n is the number of nodes

we need to check if all nodes are reachable
if all nodes are reachable, then we can use dijkstra

input has format: {source, sink, weight}
graph is weighted and uni-directional

*/
#include "includes.h"
// @lc code=start
struct Comparator
{
   public:
    bool operator()(const tuple<int, int>& a, const tuple<int, int>& b)
    {
        return std::get<1>(a) > std::get<1>(b);
    }
};
class Solution
{
   public:
    // AC
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        // construct adjacency list
        vector<vector<tuple<int, int>>> adjList(n + 1, vector<tuple<int, int>>());
        for (int i = 0; i < times.size(); ++i)
        {
            adjList[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        // dijkstra
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, Comparator> pq;  // node, weight
        pq.push({k, 0});
        int minTime = -INT_MAX;
        unordered_set<int> visited;
        set<tuple<int, int, int>> routesTaken;
        while (!pq.empty())
        {
            // get next node to process
            auto [curNode, weight] = pq.top();
            pq.pop();

            // update min time
            minTime = max(minTime, weight);
            if (!visited.count(curNode))
            {
                visited.insert(curNode);
            }

            if (visited.size() == n)
            {
                return minTime;
            }

            // add neighbors to Q
            for (auto [neighbor, neighborWeight] : adjList[curNode])
            {
                if (!routesTaken.count({curNode, neighbor, neighborWeight}))
                {
                    routesTaken.insert({curNode, neighbor, neighborWeight});
                    pq.push({neighbor, neighborWeight + weight});
                }
            }
        }

        return -1;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<vector<int>> v1{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    vector<vector<int>> v2{{1, 2, 1}};
    vector<vector<int>> v3{{1, 2, 1}};
    vector<vector<int>> v4{{1, 2, 1}, {2, 1, 3}};
    vector<vector<int>> v5{{1, 2, 1}, {2, 3, 7}, {1, 3, 4}, {2, 1, 2}};

    cout << obj.networkDelayTime(v1, 4, 2) << "\n";  // 2
    cout << obj.networkDelayTime(v2, 2, 1) << "\n";  // 1
    cout << obj.networkDelayTime(v3, 2, 2) << "\n";  // -1
    cout << obj.networkDelayTime(v4, 2, 2) << "\n";  // 3
    cout << obj.networkDelayTime(v5, 4, 1) << "\n";  // -1

    return 0;
}
