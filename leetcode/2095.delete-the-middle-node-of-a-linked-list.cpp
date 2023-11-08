/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
 *
 * https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
 *
 * algorithms
 * Medium (58.73%)
 * Likes:    3715
 * Dislikes: 65
 * Total Accepted:    276.4K
 * Total Submissions: 470.8K
 * Testcase Example:  '[1,3,4,7,1,2,6]'
 *
 * You are given the head of a linked list. Delete the middle node, and return
 * the head of the modified linked list.
 *
 * The middle node of a linked list of size n is the ⌊n / 2⌋^th node from the
 * start using 0-based indexing, where ⌊x⌋ denotes the largest integer less
 * than or equal to x.
 *
 *
 * For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2,
 * respectively.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,3,4,7,1,2,6]
 * Output: [1,3,4,1,2,6]
 * Explanation:
 * The above figure represents the given linked list. The indices of the nodes
 * are written below.
 * Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
 * We return the new list after removing this node.
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2,3,4]
 * Output: [1,2,4]
 * Explanation:
 * The above figure represents the given linked list.
 * For n = 4, node 2 with value 3 is the middle node, which is marked in red.
 *
 *
 * Example 3:
 *
 *
 * Input: head = [2,1]
 * Output: [2]
 * Explanation:
 * The above figure represents the given linked list.
 * For n = 2, node 1 with value 1 is the middle node, which is marked in red.
 * Node 0 with value 2 is the only node remaining after removing node 1.
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [1, 10^5].
 * 1 <= Node.val <= 10^5
 *
 *
 */
/*

consider two cases:

odd: len 7, remove 7
1 3 4 7 1 2 6

even: len 6, remove 7
1 3 4 7 1 2

we can use two approaches...

1) go through the entire list, count the number of elements, and then get the midpoint
2) use a slow and fast pointer, where the fast pointer moves twice as fast as the slow pointer

for odd numbers, slow is the node we want to remove
for even numbers, slow is the previous node that we want to remove

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
    ListNode *deleteMiddle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        // get middle node
        while (fast and fast->next and fast->next->next)
        {
            fast = fast->next->next;
            if (fast->next)
            {
                slow = slow->next;
            }
        }

        // even case, we can just delete the next
        if (slow->next)
        {
            slow->next = slow->next->next;
        }
        else
        {
            return nullptr;
        }

        return head;
    }
};
// @lc code=end

int main()
{
    Solution obj;
    ListNode *root = populate("[1, 3, 4, 7, 1, 2]");
    ListNode *root2 = populate("[1,2,3,4]");
    ListNode *root3 = populate("[2,1]");
    ListNode *root3 = populate("[1]");

    obj.deleteMiddle(root);
    obj.deleteMiddle(root2);
    obj.deleteMiddle(root3);
}