/*
 * @lc app=leetcode id=2487 lang=cpp
 *
 * [2487] Remove Nodes From Linked List
 *
 * https://leetcode.com/problems/remove-nodes-from-linked-list/description/
 *
 * algorithms
 * Medium (66.10%)
 * Likes:    1229
 * Dislikes: 32
 * Total Accepted:    47.4K
 * Total Submissions: 72K
 * Testcase Example:  '[5,2,13,3,8]'
 *
 * You are given the head of a linked list.
 *
 * Remove every node which has a node with a greater value anywhere to the
 * right side of it.
 *
 * Return the head of the modified linked list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [5,2,13,3,8]
 * Output: [13,8]
 * Explanation: The nodes that should be removed are 5, 2 and 3.
 * - Node 13 is to the right of node 5.
 * - Node 13 is to the right of node 2.
 * - Node 8 is to the right of node 3.
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,1,1,1]
 * Output: [1,1,1,1]
 * Explanation: Every node has value 1, so no nodes are removed.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of the nodes in the given list is in the range [1, 10^5].
 * 1 <= Node.val <= 10^5
 *
 *
 */

#include "includes.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
   public:
    ListNode* removeNodes(ListNode* head)
    {
        ListNode* cur = head;
        // use decreasing mono stack
        deque<ListNode*> s;

        while (cur)
        {
            // decreasing mono stack, so values (from bottom to top) is in decreasing order
            // pop until either stack is empty OR top of stack is bigger than current value
            while (s.size() and s.back()->val < cur->val)
            {
                s.pop_back();
            }
            s.push_back(cur);

            cur = cur->next;
        }

        // grab the remaining values and we will have the nodes we care about
        if (!s.size())
        {
            return nullptr;
        }
        else
        {
            head = s.front();
            s.pop_front();

            cur = head;
            while (s.size())
            {
                cur->next = s.front();
                s.pop_front();
                cur->next->next = nullptr;
                cur = cur->next;
            }
        }

        return head;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    // test cases
    ListNode* head1 = populate("[5,2,13,3,8]");
    ListNode* head2 = populate("[1,1,1,1]");

    obj.removeNodes(head1);

    return 0;
}
