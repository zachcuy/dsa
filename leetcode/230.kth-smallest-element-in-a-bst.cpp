/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (71.33%)
 * Likes:    10838
 * Dislikes: 207
 * Total Accepted:    1.3M
 * Total Submissions: 1.8M
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * Given the root of a binary search tree, and an integer k, return the k^th
 * smallest value (1-indexed) of all the values of the nodes in the tree.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,1,4,null,2], k = 1
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is n.
 * 1 <= k <= n <= 10^4
 * 0 <= Node.val <= 10^4
 *
 *
 *
 * Follow up: If the BST is modified often (i.e., we can do insert and delete
 * operations) and you need to find the kth smallest frequently, how would you
 * optimize?
 *
 */

/*

use min heap as we traverse the tree
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
    void dfs(TreeNode* root, priority_queue<int, vector<int>, greater<int>>& pq)
    {
        if (!root)
        {
            return;
        }

        pq.push(root->val);

        dfs(root->left, pq);
        dfs(root->right, pq);
    }
    int kthSmallest(TreeNode* root, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        dfs(root, pq);

        for (int i = 1; i < k; ++i)
        {
            pq.pop();
        }

        return pq.top();
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    TreeNode* root1 = build("[3,1,4,null,2]");
    TreeNode* root2 = build("[5,3,6,2,4,null,null,1]");

    cout << obj.kthSmallest(root1, 1) << "\n";
    cout << obj.kthSmallest(root2, 3) << "\n";
    return 0;
}
