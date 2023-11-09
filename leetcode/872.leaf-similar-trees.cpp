/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
 *
 * https://leetcode.com/problems/leaf-similar-trees/description/
 *
 * algorithms
 * Easy (67.83%)
 * Likes:    3341
 * Dislikes: 71
 * Total Accepted:    302.6K
 * Total Submissions: 445.7K
 * Testcase Example:  '[3,5,1,6,2,9,8,null,null,7,4]\n' +
  '[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]'
 *
 * Consider all the leaves of a binary tree, from left to right order, the
 * values of those leaves form a leaf value sequence.
 *
 *
 *
 * For example, in the given tree above, the leaf value sequence is (6, 7, 4,
 * 9, 8).
 *
 * Two binary trees are considered leaf-similar if their leaf value sequence is
 * the same.
 *
 * Return true if and only if the two given trees with head nodes root1 and
 * root2 are leaf-similar.
 *
 *
 * Example 1:
 *
 *
 * Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 =
 * [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root1 = [1,2,3], root2 = [1,3,2]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in each tree will be in the range [1, 200].
 * Both of the given trees will have values in the range [0, 200].
 *
 *
 */
/*

dfs approach

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
    void dfs(TreeNode *root, std::vector<int> &v)
    {
        if (!root)
        {
            return;
        }

        if (!root->left and !root->right)
        {
            v.push_back(root->val);
            return;
        }

        dfs(root->left, v);
        dfs(root->right, v);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        std::vector<int> v1;
        std::vector<int> v2;

        dfs(root1, v1);
        dfs(root2, v2);

        if (v1.size() != v2.size())
        {
            return false;
        }

        for (int i = 0; i < v1.size(); ++i)
        {
            if (v1[i] != v2[i])
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

int main()
{
    Solution obj;
    TreeNode *root1 = build("[3,5,1,6,2,9,8,null,null,7,4]");
    TreeNode *root2 = build("[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]");

    bool out = obj.leafSimilar(root1, root2);
}