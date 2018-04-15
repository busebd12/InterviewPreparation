#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;

    ListNode* next;

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

ListNode* partition(ListNode* head, int x)
{
    if(head==nullptr)
    {
        return head;
    }

    vector<int> left;

    vector<int> right;

    ListNode* current=head;

    while(true)
    {
        if(current->val < x)
        {
            left.emplace_back(current->val);
        }
        else
        {
            right.emplace_back(current->val);
        }

        if(current->next==nullptr)
        {
            break;
        }

        current=current->next;
    }

    for(const auto & number : right)
    {
        left.emplace_back(number);
    }

    ListNode* result=new ListNode(-1);

    for(const auto & number : left)
    {
        addToEnd(result, number);
    }

    return result->next;
}