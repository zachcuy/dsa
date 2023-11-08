/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (74.65%)
 * Likes:    12064
 * Dislikes: 198
 * Total Accepted:    2.7M
 * Total Submissions: 3.6M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return its maximum depth.
 *
 * A binary tree's maximum depth is the number of nodes along the longest path
 * from the root node down to the farthest leaf node.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 3
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,null,2]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -100 <= Node.val <= 100
 *
 *
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
    int dfs(TreeNode *root, int count = 0)
    {
        if (!root)
        {
            return count;
        }

        return std::max(dfs(root->left, count + 1), dfs(root->right, count + 1));
    }
    int maxDepth(TreeNode *root)
    {
        return dfs(root);
    }
};
// @lc code=end

int main()
{
    Solution obj;

    TreeNode *root = build("[3,9,20,null,null,15,7]");
    TreeNode *root2 = build("[1,null,2]");

    std::cout << obj.maxDepth(root) << "\n";
    std::cout << obj.maxDepth(root2) << "\n";
}