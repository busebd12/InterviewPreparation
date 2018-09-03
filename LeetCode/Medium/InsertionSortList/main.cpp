#include <iostream>
#include <deque>
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

ListNode* insertionSortList(ListNode* head)
{
    if(head==nullptr || head->next==nullptr)
    {
        return head;
    }

    deque<int> elements;

    ListNode* current=head;

    while(true)
    {
        if(elements.empty())
        {
            elements.emplace_back(current->val);
        }
        else
        {
            int elementsSize=int(elements.size());

            int insertionPoint=-1;

            if(current->val <= elements[0])
            {
                elements.emplace_front(current->val);
            }
            else if(current->val >= elements[elementsSize-1])
            {
                elements.emplace_back(current->val);
            }
            else
            {
                for(int i=1;i<elementsSize;++i)
                {
                    if(current->val <= elements[i] && current->val >= elements[i-1])
                    {
                        insertionPoint=i;

                        break;
                    }
                }

                elements.insert(elements.begin()+insertionPoint, current->val);
            }
        }

        if(current->next==nullptr)
        {
            break;
        }

        current=current->next;
    }

    ListNode* sorted=new ListNode(-1);

    int elementsSize=int(elements.size());

    for(int i=0;i<elementsSize;++i)
    {
        addToEnd(sorted, elements[i]);
    }

    return sorted->next;
}