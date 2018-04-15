#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;

    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

void addToEnd(ListNode* & head, const int value)
{
    ListNode* tail=new ListNode(value);

    if(head->next==nullptr)
    {
        head->next=tail;
    }
    else
    {
        ListNode* current=head;

        while(true)
        {
            if(current->next==nullptr)
            {
                current->next=tail;

                break;
            }

            current=current->next;
        }
    }
}

ListNode* deleteDuplicates(ListNode* head)
{
    if(head==nullptr || head->next==nullptr)
    {
        return head;
    }

    ListNode* current=head;

    unordered_set<int> valuesToDelete;

    while(current)
    {
        while(current->next && current->val==current->next->val)
        {
            if(valuesToDelete.find(current->val)==end(valuesToDelete))
            {
                valuesToDelete.insert(current->val);
            }

            current->next=current->next->next;
        }

        current=current->next;
    }

    current=head;

    ListNode* result=new ListNode(-1);

    while(true)
    {
        if(valuesToDelete.find(current->val)==end(valuesToDelete))
        {
            addToEnd(result, current->val);
        }

        if(current->next==nullptr)
        {
            break;
        }

        current=current->next;
    }

    return result->next;
}