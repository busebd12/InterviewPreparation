#include <iostream>
using namespace std;

ListNode* swapPairs(ListNode* head)
{
    if(head==nullptr || head->next==nullptr)
    {
        return head;
    }

    bool lostHeadPointer=true;

    int count=0;

    ListNode* first=head;

    ListNode* second;

    ListNode* temp;

    ListNode* previous;

    while(true)
    {
        second=first->next;

        if(count > 0)
        {
            previous->next=second;
        }

        temp=second->next;

        second->next=first;

        first->next=temp;

        if(lostHeadPointer)
        {
            head=second;

            lostHeadPointer=false;
        }

        if(temp==nullptr || temp->next==nullptr)
        {
            break;
        }

        previous=first;

        first=temp;

        ++count;
    }

    return head;
}