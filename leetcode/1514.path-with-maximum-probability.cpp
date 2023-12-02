/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 *
 * https://leetcode.com/problems/path-with-maximum-probability/description/
 *
 * algorithms
 * Medium (54.62%)
 * Likes:    3003
 * Dislikes: 67
 * Total Accepted:    125.8K
 * Total Submissions: 230.7K
 * Testcase Example:  '3\n[[0,1],[1,2],[0,2]]\n[0.5,0.5,0.2]\n0\n2'
 *
 * You are given an undirected weighted graph of n nodes (0-indexed),
 * represented by an edge list where edges[i] = [a, b] is an undirected edge
 * connecting the nodes a and b with a probability of success of traversing
 * that edge succProb[i].
 *
 * Given two nodes start and end, find the path with the maximum probability of
 * success to go from start to end and return its success probability.
 *
 * If there is no path from start to end, return 0. Your answer will be
 * accepted if it differs from the correct answer by at most 1e-5.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start =
 * 0, end = 2
 * Output: 0.25000
 * Explanation: There are two paths from start to end, one having a probability
 * of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start =
 * 0, end = 2
 * Output: 0.30000
 *
 *
 * Example 3:
 *
 *
 *
 *
 * Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
 * Output: 0.00000
 * Explanation: There is no path between 0 and 2.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= n <= 10^4
 * 0 <= start, end < n
 * start != end
 * 0 <= a, b < n
 * a != b
 * 0 <= succProb.length == edges.length <= 2*10^4
 * 0 <= succProb[i] <= 1
 * There is at most one edge between every two nodes.
 *
 *
 */

/*
do dijkstra but we want to follow the maximum instead of the minimum edge

first we convert the nodes to an adjacency list

starting from start node:

mark current node as visited

visit each of its neighbors and update the maximum probability for that node,
add neighbors to q if we haven't visited that neighbor yet

*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb,
                          int start_node, int end_node)
    {
        // create adjacency list
        unordered_map<int, unordered_map<int, double>> adjacencyList;
        for (int i = 0; i < edges.size(); ++i)
        {
            int start = edges[i][0];
            int end = edges[i][1];

            // we want to do both ways since we have an undirected graph
            adjacencyList[start][end] = succProb[i];
            adjacencyList[end][start] = succProb[i];
        }

        // dijkstra using priority q
        unordered_map<int, double> prob;
        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
        pq.push({1.0, start_node});
        prob[start_node] = 1.0;

        while (!pq.empty())
        {
            // get prob : node ID
            auto [curProb, node] = pq.top();
            pq.pop();

            if (node == end_node)
            {
                return curProb;
            }

            for (auto& [neighborNode, neighborProb] : adjacencyList[node])
            {
                double newProb = curProb * neighborProb;

                // update maximum probabilities
                if (newProb > prob[neighborNode])
                {
                    prob[neighborNode] = newProb;
                    pq.push({newProb, neighborNode});
                }
            }
        }

        return 0.0;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<vector<int>> a1{{0, 1}, {1, 2}, {0, 2}};
    vector<double> a2{0.5, 0.5, 0.2};

    vector<vector<int>> b1{{0, 1}, {1, 2}, {0, 2}};
    vector<double> b2{0.5, 0.5, 0.3};

    vector<vector<int>> c1{{0, 1}};
    vector<double> c2{0.5};

    vector<vector<int>> d1{{2, 3}, {1, 2}, {3, 4}, {1, 3}, {1, 4}, {0, 1}, {2, 4}, {0, 4}, {0, 2}};
    vector<double> d2{0.06, 0.26, 0.49, 0.25, 0.2, 0.64, 0.23, 0.21, 0.77};

    obj.maxProbability(3, a1, a2, 0, 2);  // 0.25
    obj.maxProbability(3, b1, b2, 0, 2);  // 0.3
    obj.maxProbability(3, c1, c2, 0, 2);  // 0.0
    obj.maxProbability(5, d1, d2, 0, 3);  //
    return 0;
}
