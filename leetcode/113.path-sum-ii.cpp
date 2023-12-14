/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (57.70%)
 * Likes:    7649
 * Dislikes: 149
 * Total Accepted:    804K
 * Total Submissions: 1.4M
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given the root of a binary tree and an integer targetSum, return all
 * root-to-leaf paths where the sum of the node values in the path equals
 * targetSum. Each path should be returned as a list of the node values, not
 * node references.
 *
 * A root-to-leaf path is a path starting from the root and ending at any leaf
 * node. A leaf is a node with no children.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: [[5,4,11,2],[5,8,4,5]]
 * Explanation: There are two paths whose sum equals targetSum:
 * 5 + 4 + 11 + 2 = 22
 * 5 + 8 + 4 + 5 = 22
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,3], targetSum = 5
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1,2], targetSum = 0
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 5000].
 * -1000 <= Node.val <= 1000
 * -1000 <= targetSum <= 1000
 *
 *
 */

/*
    dfs to the leaf and check sum, if it is, add the current stack
*/
#include "includes.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
   public:
    void dfs(TreeNode* root, vector<vector<int>>& ans, vector<int> tmp, int target)
    {
        if (!root)
        {
            return;
        }

        target -= root->val;
        tmp.push_back(root->val);
        if (!root->left and !root->right)  // leaf node
        {
            if (target == 0)
            {
                ans.push_back(tmp);
            }
            return;
        }

        dfs(root->left, ans, tmp, target);
        dfs(root->right, ans, tmp, target);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<vector<int>> paths;
        vector<int> tmp;

        dfs(root, paths, tmp, targetSum);
        return paths;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    TreeNode* root = build("[5,4,8,11,null,13,4,7,2,null,null,5,1]");
    obj.pathSum(root, 22);
    return 0;
}