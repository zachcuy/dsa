/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 *
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (61.36%)
 * Likes:    9280
 * Dislikes: 492
 * Total Accepted:    809.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, group all the nodes with odd indices
 * together followed by the nodes with even indices, and return the reordered
 * list.
 *
 * The first node is considered odd, and the second node is even, and so on.
 *
 * Note that the relative order inside both the even and odd groups should
 * remain as it was in the input.
 *
 * You must solve the problem in O(1) extra space complexity and O(n) time
 * complexity.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5]
 * Output: [1,3,5,2,4]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [2,1,3,5,6,4,7]
 * Output: [2,3,6,7,1,5,4]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the linked list is in the range [0, 10^4].
 * -10^6 <= Node.val <= 10^6
 *
 *
 */
/*

move all odd indices to the start of the list
move all even indices to the end of the list
the nodes should keep their relative order
odds -> evens

constraints:
o(1) space
o(n) time

in:
1 2 3 4 5
1 3 2 4 5

res:
1 3 5 2 4

track of where the last odd was
swap all odds backwards until we hit the node after the last odd was placed

odd length:
last value is odd and it points to first even

even length:
last value is even and last odd points to first even


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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }

        ListNode *cur = head;
        ListNode *evens = head->next;
        ListNode *odds = cur;

        int i = 1;
        while (cur and cur->next)
        {
            if (i % 2)
            {
                odds = cur;
            }
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            cur = tmp;
            i++;
        }

        if (i % 2)
        {
            cur->next = evens;
        }
        else
        {
            odds->next = evens;
        }

        return head;
    }
};
// @lc code=end

int main()
{
    Solution obj;

    ListNode *head = populate("[1,2,3,4,5]");
    ListNode *head2 = populate("[2,1,3,5,6,4,7]");
    ListNode *head3 = populate("[1,2,3,4]");
    ListNode *head4 = populate("[1,2]");
    ListNode *head5 = populate("[1]");

    obj.oddEvenList(head);
    obj.oddEvenList(head2);
    obj.oddEvenList(head3);
    obj.oddEvenList(head4);
    obj.oddEvenList(head5);
}