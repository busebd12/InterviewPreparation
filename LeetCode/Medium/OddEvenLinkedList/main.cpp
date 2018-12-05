#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void addToEnd(ListNode* & head, int & value)
{
    ListNode* last=head;

    while(last->next!=nullptr)
    {
        last=last->next;
    }

    last->next=new ListNode(value);
}

ListNode* oddEvenList(ListNode* head)
{
    if(head==nullptr)
    {
        return head;
    }

    if(head->next==nullptr)
    {
        return head;
    }

    ListNode* result=new ListNode(0);

    ListNode* current=head;

    int length=0;

    while(true)
    {
        ++length;

        if(current->next==nullptr)
        {
            break;
        }

        current=current->next;
    }

    current=head;

    for(int i=0;i<length;++i)
    {
        if(i%2==0)
        {
            addToEnd(result, current->val);
        }

        current=current->next;
    }

    current=head;

    for(int i=0;i<length;++i)
    {
        if(i%2!=0)
        {
            addToEnd(result, current->val);
        }

        current=current->next;
    }

    return result->next;
}