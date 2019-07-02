#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void addToEnd(ListNode* & merged, int number)
{
    ListNode* tail=new ListNode(number);

    if(merged==nullptr)
    {
        merged->next=tail;
    }
    else
    {
        ListNode* current=merged;

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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode* merged=new ListNode(-1);

    if(l1==nullptr && l2==nullptr)
    {
        return nullptr;
    }

    if(l1==nullptr)
    {
        return l2;
    }

    if(l2==nullptr)
    {
        return l1;
    }

    ListNode* first=l1;

    ListNode* second=l2;

    while(first!=nullptr && second!=nullptr)
    {
        int x=first->val;

        int y=second->val;

        if(x==y)
        {
            addToEnd(merged, x);

            addToEnd(merged, y);

            first=first->next;

            second=second->next;
        }
        else if(x < y)
        {
            addToEnd(merged, x);

            first=first->next;
        }
        else
        {
            addToEnd(merged, y);

            second=second->next;
        }
    }

    if(first!=nullptr)
    {
        ListNode* current=first;

        while(true)
        {
            addToEnd(merged, current->val);

            if(current->next==nullptr)
            {
                break;
            }

            current=current->next;
        }
    }

    if(second!=nullptr)
    {
        ListNode* current=second;

        while(true)
        {
            addToEnd(merged, current->val);

            if(current->next==nullptr)
            {
                break;
            }

            current=current->next;
        }
    }

    return merged->next;
}