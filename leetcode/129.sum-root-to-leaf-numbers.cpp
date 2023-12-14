/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 *
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 *
 * algorithms
 * Medium (62.08%)
 * Likes:    7327
 * Dislikes: 118
 * Total Accepted:    683.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * You are given the root of a binary tree containing digits from 0 to 9 only.
 *
 * Each root-to-leaf path in the tree represents a number.
 *
 *
 * For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
 *
 *
 * Return the total sum of all root-to-leaf numbers. Test cases are generated
 * so that the answer will fit in a 32-bit integer.
 *
 * A leaf node is a node with no children.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3]
 * Output: 25
 * Explanation:
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Therefore, sum = 12 + 13 = 25.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [4,9,0,5,1]
 * Output: 1026
 * Explanation:
 * The root-to-leaf path 4->9->5 represents the number 495.
 * The root-to-leaf path 4->9->1 represents the number 491.
 * The root-to-leaf path 4->0 represents the number 40.
 * Therefore, sum = 495 + 491 + 40 = 1026.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 1000].
 * 0 <= Node.val <= 9
 * The depth of the tree will not exceed 10.
 *
 *
 */

/*

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
    void dfs(TreeNode* root, vector<int>& vals, string sum)
    {
        if (!root)
        {
            return;
        }

        sum += to_string(root->val);
        if (!root->left and !root->right)
        {
            // convert sum to value and push to vals
            vals.push_back(stoi(sum));
        }

        dfs(root->left, vals, sum);
        dfs(root->right, vals, sum);
    }
    int sumNumbers(TreeNode* root)
    {
        vector<int> vals;
        dfs(root, vals, "");

        return accumulate(vals.begin(), vals.end(), 0);
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    TreeNode* root1 = build("[1,2,3]");
    TreeNode* root2 = build("[4,9,0,5,1]");
    obj.sumNumbers(root1);
    obj.sumNumbers(root2);
    return 0;
}
