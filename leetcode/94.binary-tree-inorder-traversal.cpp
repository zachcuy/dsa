/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Easy (74.80%)
 * Likes:    12905
 * Dislikes: 705
 * Total Accepted:    2.3M
 * Total Submissions: 3.1M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    void dfs(vector<int>& res, TreeNode* root)
    {
        if (!root)
        {
            return;
        }

        dfs(res, root->left);
        res.push_back(root->val);
        dfs(res, root->right);
    }
    // AC
    vector<int> inorderTraversal(TreeNode* root)
    {
        /*
        left -> node -> right
        bottom -> up
        */

        vector<int> res;
        dfs(res, root);
        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    TreeNode* root1 = build("[1,null,2,3]");
    TreeNode* root2 = build("[]");
    TreeNode* root3 = build("[1]");

    dump(obj.inorderTraversal(root1));
    dump(obj.inorderTraversal(root2));
    dump(obj.inorderTraversal(root3));
    return 0;
}