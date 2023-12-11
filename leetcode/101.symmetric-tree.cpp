/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (55.34%)
 * Likes:    14653
 * Dislikes: 351
 * Total Accepted:    1.8M
 * Total Submissions: 3.3M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given the root of a binary tree, check whether it is a mirror of itself
 * (i.e., symmetric around its center).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,2,3,4,4,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,2,null,3,null,3]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 1000].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Could you solve it both recursively and iteratively?
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
    // AC: iterative with bfs
    bool isSymmetric(TreeNode* root)
    {
        // tracks left-hand side of bin tree
        queue<TreeNode*> LHS;
        LHS.push(root->left);

        // tracks right-hand side of bin tree
        queue<TreeNode*> RHS;
        RHS.push(root->right);

        while (LHS.size() or RHS.size())
        {
            if ((LHS.size() xor RHS.size()))  // one side has elements and the other does not
            {
                return false;
            }

            // both have nodes left in q
            TreeNode* left = LHS.front();
            TreeNode* right = RHS.front();
            LHS.pop();
            RHS.pop();

            if ((left and !right) or (!left and right) or
                (left and right and left->val != right->val))
            {
                return false;
            }

            // order is opposite so we compare opposites!
            // left of LHS must be the same as right on RHS
            if (left)
            {
                LHS.push(left->left);
                LHS.push(left->right);
            }
            // right of LH must be the same as left on RHS
            if (right)
            {
                RHS.push(right->right);
                RHS.push(right->left);
            }
        }

        return true;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    TreeNode* root1 = build("[1,2,2,3,4,4,3]");
    TreeNode* root2 = build("[1,2,2,null,3,null,3]");
    TreeNode* root3 = build("[1]");
    TreeNode* root4 = build("[1,2,3]");

    dump(obj.isSymmetric(root1));  // T
    dump(obj.isSymmetric(root2));  // F
    dump(obj.isSymmetric(root3));  // T
    dump(obj.isSymmetric(root4));  // F
    return 0;
}