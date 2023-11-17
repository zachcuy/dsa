/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 *
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (47.05%)
 * Likes:    7838
 * Dislikes: 455
 * Total Accepted:    751.8K
 * Total Submissions: 1.6M
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * Given the roots of two binary trees root and subRoot, return true if there
 * is a subtree of root with the same structure and node values of subRoot and
 * false otherwise.
 *
 * A subtree of a binary tree tree is a tree that consists of a node in tree
 * and all of this node's descendants. The tree tree could also be considered
 * as a subtree of itself.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,4,5,1,2], subRoot = [4,1,2]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the root tree is in the range [1, 2000].
 * The number of nodes in the subRoot tree is in the range [1, 1000].
 * -10^4 <= root.val <= 10^4
 * -10^4 <= subRoot.val <= 10^4
 *
 *
 */

/*
do bfs on root and subroot at the same time

if we match each node and complete the subroot, then we can return true

if any node doesn't match, we should reset subRoot and move on to next root node
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
    bool check(TreeNode* root, TreeNode* subRoot)
    {
        queue<TreeNode*> q1;
        q1.push(root);

        queue<TreeNode*> q2;
        q2.push(subRoot);

        while (q1.size() and q2.size())
        {
            size_t len1 = q1.size();
            size_t len2 = q2.size();

            if (len1 != len2)
            {
                return false;
            }

            for (size_t i = 0; i < len1; i++)
            {
                // get next node in current level (main tree)
                TreeNode* cur1 = q1.front();
                q1.pop();
                // get next node in current level (sub tree)
                TreeNode* cur2 = q2.front();
                q2.pop();

                if (cur1->val != cur2->val)
                {
                    return false;
                }

                // add next left level with checks on symmetry
                if (cur1->left and cur2->left)
                {
                    q1.push(cur1->left);
                    q2.push(cur2->left);
                }
                else if ((cur1->left and !cur2->left) or (!cur1->left and cur2->left))
                {
                    return false;
                }

                // add next right level with checks on symmetry
                if (cur1->right and cur2->right)
                {
                    q1.push(cur1->right);
                    q2.push(cur2->right);
                }
                else if ((cur1->right and !cur2->right) or (!cur1->right and cur2->right))
                {
                    return false;
                }
            }
        }

        // default case: return true (since we never mismatched)
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        queue<TreeNode*> q;
        q.push(root);

        while (q.size())
        {
            size_t len = q.size();

            for (size_t i = 0; i < len; i++)
            {
                // get next node in current level (main tree)
                TreeNode* cur = q.front();
                q.pop();

                // check if subtree matches starting from this node
                if (check(cur, subRoot))
                {
                    return true;
                }

                // add next level
                if (cur->left)
                {
                    q.push(cur->left);
                }
                if (cur->right)
                {
                    q.push(cur->right);
                }
            }
        }

        // default case: return false (since we never matched!)
        return false;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    // TreeNode* root = build("[3,4,5,1,2]");
    // TreeNode* subroot = build("[4,1,2]");
    TreeNode* root = build("[3,4,5,1,2,null,null,null,null,0]");
    TreeNode* subroot = build("[4,1,2]");

    boolPrint(obj.isSubtree(root, subroot));

    return 0;
}
