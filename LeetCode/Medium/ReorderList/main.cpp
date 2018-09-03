#include <iostream>
#include <vector>
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

void reorderList(ListNode* head)
{
    if(head==nullptr)
    {
        return;
    }

    if(head->next==nullptr)
    {
        return;
    }

    vector<pair<int, bool>> elements;

    ListNode* detached=head->next;

    ListNode* current=detached;

    while(true)
    {
        elements.push_back(make_pair(current->val, false));

        if(current->next==nullptr)
        {
            break;
        }

        current=current->next;
    }

    head->next=nullptr;

    int elementsSize=int(elements.size());

    int front=0;

    int back=elementsSize-1;

    bool alreadyAddedFront=false;

    bool alreadyAddedBack=false;

    while(true)
    {
        if(back < 0 || front >= elementsSize)
        {
            break;
        }

        if(alreadyAddedFront && alreadyAddedBack)
        {
            break;
        }

        if(elements[back].second==false)
        {
            addToEnd(head, elements[back].first);

            elements[back].second=true;
        }
        else
        {
            alreadyAddedFront=true;
        }

        if(elements[front].second==false)
        {
            addToEnd(head, elements[front].first);

            elements[front].second=true;
        }
        else
        {
            alreadyAddedBack=true;
        }

        ++front;

        --back;
    }
}