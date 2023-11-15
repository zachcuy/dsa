/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
 *
 * https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (67.39%)
 * Likes:    3335
 * Dislikes: 97
 * Total Accepted:    229.7K
 * Total Submissions: 341.3K
 * Testcase Example:  '[1,7,0,7,-8,null,null]'
 *
 * Given the root of a binary tree, the level of its root is 1, the level of
 * its children is 2, and so on.
 *
 * Return the smallest level x such that the sum of all the values of nodes at
 * level x is maximal.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,7,0,7,-8,null,null]
 * Output: 2
 * Explanation:
 * Level 1 sum = 1.
 * Level 2 sum = 7 + 0 = 7.
 * Level 3 sum = 7 + -8 = -1.
 * So we return the level with the maximum sum which is level 2.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^5 <= Node.val <= 10^5
 *
 *
 */

/*

in: binary tree
out: tree level that has largest sum

since we want the sums of each level, we should do BFS

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
    int maxLevelSum(TreeNode* root)
    {
        std::queue<TreeNode*> q;
        q.push(root);
        size_t maxLevel = 0, level = 0;
        long long maxSum = -INT_MAX;

        while (q.size())
        {
            // increment level
            level++;

            // loop through the level
            long long curSum = 0;
            size_t len = q.size();
            for (size_t i = 0; i < len; i++)
            {
                // get next node in level
                TreeNode* cur = q.front();
                q.pop();

                // add nodes
                if (cur->left)
                {
                    q.push(cur->left);
                }
                if (cur->right)
                {
                    q.push(cur->right);
                }

                // calculate sum
                curSum += cur->val;
            }

            // update maxSum and maxLevel
            if (curSum > maxSum)
            {
                maxLevel = level;
                maxSum = curSum;
            }
        }

        return maxLevel;
    }
};
// @lc code=end

int main()
{
    Solution obj;

    TreeNode* root1 = build("[1,7,0,7,-8,null,null]");
    TreeNode* root2 = build("[989,null,10250,98693,-89388,null,null,null,-32127]");
    TreeNode* root3 = build("[-100,-200,-300,-20,-5,-10,null]");

    cout << obj.maxLevelSum(root1) << "\n\n";  // 2
    cout << obj.maxLevelSum(root2) << "\n\n";  // 2
    cout << obj.maxLevelSum(root3) << "\n\n";  // 3

    return 0;
}