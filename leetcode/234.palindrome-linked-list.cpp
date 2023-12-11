/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (51.06%)
 * Likes:    15550
 * Dislikes: 837
 * Total Accepted:    1.7M
 * Total Submissions: 3.2M
 * Testcase Example:  '[1,2,2,1]'
 *
 * Given the head of a singly linked list, return true if it is a palindrome or
 * false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,2,1]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [1, 10^5].
 * 0 <= Node.val <= 9
 *
 *
 *
 * Follow up: Could you do it in O(n) time and O(1) space?
 */

/*
get length of linked list
reverse second half until mid point
check if linked list is palindrome or not
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
    // AC: o(n) time, o(1) space
    bool isPalindrome(ListNode* head)
    {
        int length = 0;
        ListNode* left = head;
        ListNode* right = head;

        // get mid point of the linked list
        while (right->next and right->next->next)
        {
            right = right->next->next;
            left = left->next;
        }

        // reverse 2nd half of linked list
        ListNode* prev = nullptr;
        while (left)
        {
            ListNode* tmp = left->next;
            left->next = prev;
            prev = left;
            left = tmp;
        }

        // check for palindrome
        right = prev;
        left = head;
        while (left and right)
        {
            if (left->val != right->val)
            {
                return false;
            }
            left = left->next;
            right = right->next;
        }

        return true;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;
    ListNode* head1 = populate("[1,2,2,1]");
    ListNode* head2 = populate("[1,2]");
    ListNode* head3 = populate("[1,2,3,2,1]");
    ListNode* head4 = populate("[1,2,9,3,1]");

    dump(obj.isPalindrome(head1));  // T
    dump(obj.isPalindrome(head2));  // F
    dump(obj.isPalindrome(head3));  // T
    dump(obj.isPalindrome(head4));  // F
    return 0;
}