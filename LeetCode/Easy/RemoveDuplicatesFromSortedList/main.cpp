#include <iostream>
using namespace std;

/*
 * Approach:
 * While looping over the linked list, if we see two elements that are the same,
 * set current's next pointer equal to current->next's next pointer (effectively, removing it from the list).
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
    if(head==nullptr)
    {
        return head;
    }

    if(head->next==nullptr)
    {
        return head;
    }

    ListNode* current=head;

    while(current->next!=nullptr)
    {
        if(current->val==current->next->val)
        {
            current->next=current->next->next;
        }
        else
        {
            current=current->next;
        }
    }

    return head;
}