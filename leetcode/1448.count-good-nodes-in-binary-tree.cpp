/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
 *
 * https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
 *
 * algorithms
 * Medium (73.46%)
 * Likes:    5453
 * Dislikes: 143
 * Total Accepted:    399.1K
 * Total Submissions: 544.1K
 * Testcase Example:  '[3,1,4,3,null,1,5]'
 *
 * Given a binary tree root, a node X in the tree is named good if in the path
 * from root to X there are no nodes with a value greater than X.
 *
 * Return the number of good nodes in the binary tree.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: root = [3,1,4,3,null,1,5]
 * Output: 4
 * Explanation: Nodes in blue are good.
 * Root Node (3) is always a good node.
 * Node 4 -> (3,4) is the maximum value in the path starting from the root.
 * Node 5 -> (3,4,5) is the maximum value in the path
 * Node 3 -> (3,1,3) is the maximum value in the path.
 *
 * Example 2:
 *
 *
 *
 *
 * Input: root = [3,3,null,4,2]
 * Output: 3
 * Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than
 * it.
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: 1
 * Explanation: Root is considered as good.
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the binary tree is in the range [1, 10^5].
 * Each node's value is between [-10^4, 10^4].
 *
 */
/*

dfs approach

keep track of maximum value so far and pass that to the next iteration

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
    void dfs(TreeNode *root, int &count, int max)
    {
        if (!root)
        {
            return;
        }

        if (root->val >= max)
        {
            count++;
            max = root->val;
        }

        dfs(root->left, count, max);
        dfs(root->right, count, max);
    }
    int goodNodes(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int count = 0;
        dfs(root, count, INT_MIN);

        return count;
    }
};
// @lc code=end

int main()
{
    Solution obj;
    TreeNode *root = build("[3,1,4,3,null,1,5]");
    TreeNode *root2 = build("[-1,5,-2,4,4,2,-2,null,null,-4,null,-2,3,null,-2,0,null,-1,null,-3,null,-4,-3,3,null,null,null,null,null,null,null,5,-3]");

    // std::cout << obj.goodNodes(root) << "\n";
    std::cout << obj.goodNodes(root2) << "\n";
}