/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Medium (47.10%)
 * Likes:    10390
 * Dislikes: 486
 * Total Accepted:    504.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * Given the root of a binary tree and an integer targetSum, return the number
 * of paths where the sum of the values along the path equals targetSum.
 *
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards (i.e., traveling only from parent nodes to child nodes).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
 * Output: 3
 * Explanation: The paths that sum to 8 are shown.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 1000].
 * -10^9 <= Node.val <= 10^9
 * -1000 <= targetSum <= 1000
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
    int dfs(TreeNode* root, long long targetSum, int count = 0)
    {
        // check if root is valid or not
        if (!root)
        {
            return 0;
        }

        targetSum -= root->val;
        if (targetSum == 0)
        {
            count++;
        }

        count += dfs(root->left, targetSum);
        count += dfs(root->right, targetSum);

        return count;
    }
    int pathSum(TreeNode* root, long long targetSum)
    {
        int count = 0;
        if (!root)
        {
            return 0;
        }

        count += dfs(root, targetSum);
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    TreeNode* root1 = build("[10,5,-3,3,2,null,11,3,-2,null,1]");
    TreeNode* root2 = build("[5,4,8,11,null,13,4,7,2,null,null,5,1]");
    TreeNode* root3 = build("[1,-2,-3,1,3,-2,null,-1]");

    std::cout << obj.pathSum(root1, 8) << "\n\n";   // 3
    std::cout << obj.pathSum(root2, 22) << "\n\n";  // 3
    std::cout << obj.pathSum(root3, 3) << "\n\n";   // 1
    std::cout << obj.pathSum(root3, -1) << "\n\n";  // 4
    return 0;
}
