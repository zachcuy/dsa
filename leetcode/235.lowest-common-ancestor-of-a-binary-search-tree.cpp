/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (63.16%)
 * Likes:    10478
 * Dislikes: 293
 * Total Accepted:    1.3M
 * Total Submissions: 2.1M
 * Testcase Example:  '[6,2,8,0,4,7,9,null,null,3,5]\n2\n8'
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) node
 * of two given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of
 * itself).”
 *
 *
 * Example 1:
 *
 *
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * Output: 6
 * Explanation: The LCA of nodes 2 and 8 is 6.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * Output: 2
 * Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant
 * of itself according to the LCA definition.
 *
 *
 * Example 3:
 *
 *
 * Input: root = [2,1], p = 2, q = 1
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [2, 10^5].
 * -10^9 <= Node.val <= 10^9
 * All Node.val are unique.
 * p != q
 * p and q will exist in the BST.
 *
 *
 */

/*

binary search tree:
values left must be less than current node
values right must be greater than current node

finding the LCA means we find the node that can contain p in the left-hand side and q in the
right-hand side, although a node can be a descendant of itself

so if we have a value p that is itself, then q must be in the right-hand side and we return p
and vice-versa

there is no guarantee that p->val > q->val

*/
#include "includes.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        int a = min(p->val, q->val);
        int b = max(p->val, q->val);

        // bfs
        queue<TreeNode*> que;
        que.push(root);

        while (que.size())
        {
            size_t len = que.size();

            for (size_t i = 0; i < len; i++)
            {
                TreeNode* cur = que.front();
                que.pop();

                // check if both are smaller than current node
                if (a < cur->val and b < cur->val)
                {
                    // node is in the left hand side
                    // add child
                    if (cur->left)
                    {
                        que.push(cur->left);
                    }
                }
                // check if both are larger than current node
                else if (a > cur->val and b > cur->val)
                {
                    // node is in the right hand side
                    // add child
                    if (cur->right)
                    {
                        que.push(cur->right);
                    }
                }
                else if ((a < cur->val and b > cur->val) or a == cur->val or b == cur->val)
                {
                    return cur;
                }
            }
        }

        return nullptr;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    // placeholder
    Solution obj;

    // TreeNode* root = build("[6,2,8,0,4,7,9,null,null,3,5]");
    // TreeNode* p = new TreeNode(2);
    // TreeNode* q = new TreeNode(4);
    TreeNode* root = build("[2,1]");
    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(1);

    cout << obj.lowestCommonAncestor(root, p, q)->val << "\n";

    return 0;
}
