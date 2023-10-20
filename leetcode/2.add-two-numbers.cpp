#include "includes.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

/*

go through both lists at the same time using two pointers

at each node, get carry and base digit

assign base digit to both nodes

go to next

Since one of the values may be shorter, we only increment and add to the one that is active

return the list that is longer

*/

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        int carry = 0;
        ListNode *a = l1;
        ListNode *b = l2;
        int lenA = 0;
        int lenB = 0;

        while (carry or a or b)
        {
            // Only get the value if node exists
            int valA = 0;
            if (a)
            {
                valA = a->val;
            }
            int valB = 0;
            if (b)
            {
                valB = b->val;
            }

            // get base and carry
            int sum = valA + valB + carry;
            carry = sum / 10;
            sum %= 10;

            // assign the remainder of sum to both current nodes
            if (a)
            {
                a->val = sum;
                if (!a->next and carry > 0)
                {
                    a->next = new ListNode(carry);
                    a = a->next;
                }

                // go next
                lenA++;
                a = a->next;
            }
            if (b)
            {
                b->val = sum;
                if (!b->next and carry > 0)
                {
                    b->next = new ListNode(carry);
                    b = b->next;
                }

                // go next
                lenB++;
                b = b->next;
            }
        }

        if (lenA > lenB)
        {
            return l1;
        }
        else
        {
            return l2;
        }
    }
};

int main()
{

    return 0;
}