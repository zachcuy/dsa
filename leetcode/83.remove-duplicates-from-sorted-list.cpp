#include "includes.h"

void deleteNode(ListNode *prev)
{
    // given a node that is previous to the one we want to delete
    prev->next = prev->next->next;
}

void deleteDuplicates(ListNode *head)
{
    /*

        keep track of seen values using a set
        call a delete function when we encounter a duplicate node

        add current node to set
        check the value ahead
            delete if in set
            move on if not in set
    */
    std::unordered_set<int> s;

    while (head)
    {
        // insert value into set
        s.insert(head->val);

        // only check if the next is valid
        while (head->next and s.count(head->next->val))
        {
            deleteNode(head);
        }

        // go next
        head = head->next;
    }
}

int main()
{
    ListNode *myList = new ListNode(0);
    std::vector<int> v{1, 1, 2, 3, 3, 4, 4, 4, 5, 6, 6, 6, 7, 8, 9, 10, 10};

    addList(v, myList);
    printList(myList);

    myList = myList->next;
    deleteDuplicates(myList);
    printList(myList);

    return 0;
}
