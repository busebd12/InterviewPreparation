#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    if(!head)
    {
        return nullptr;
    }

    if(head->next==nullptr)
    {
        return nullptr;
    }

    if(head->next==head)
    {
        return head;
    }

    unordered_map<ListNode*, bool> table;

    ListNode* current=head;

    ListNode* answer=nullptr;

    while(true)
    {
        if(current->next==nullptr)
        {
            break;
        }

        if(table[current]==true)
        {
            answer=current;

            break;
        }
        else
        {
            table[current]=true;
        }

        current=current->next;
    }

    return answer;
}