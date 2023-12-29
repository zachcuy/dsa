/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int> tmp, int node)
    {
        tmp.push_back(node);

        // check if we're at the end
        if (node == graph.size() - 1)
        {
            ans.push_back(tmp);
            return;
        }

        for (int i = 0; i < graph[node].size(); ++i)
        {
            dfs(graph, ans, tmp, graph[node][i]);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        vector<vector<int>> ans;
        vector<int> tmp;

        dfs(graph, ans, tmp, 0);

        return ans;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<vector<int>> graph1{{1, 2}, {3}, {3}, {}};
    vector<vector<int>> graph2{{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};

    dump(obj.allPathsSourceTarget(graph1));
    dump(obj.allPathsSourceTarget(graph2));
    return 0;
}