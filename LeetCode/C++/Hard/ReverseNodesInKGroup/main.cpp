#include "../ListNode.h"
#include <deque>
#include <iostream>

/*
 * Solutions:
 *
 * 1. We put all the nodes into a deque. Then, while the deque is not empty, we remove k nodes at a time and
 * add those k nodes to another deque, kNodes, so that we can remove the nodes in the reverse order from the
 * end of the kNodes deque and add them to our new result linked list. Once there are less than k nodes left,
 * we simply put the rest of the nodes in their original order into the result linked list.
 *
 * Time complexity: O(n^2) [where n is the length of the input linked list]
 * Space complexity: O(n)
 *
 *
 * 2. We break the linked-list into k chunks, reverse each chunk, and re-attach each chunk together to form the result
 * linked-list. If the amount of nodes is not evenly divisible by k, then once we run out of chunks we can make, we
 * just add the rest of the linked-list to the result linked-list.
 *
 * Time complexity: O(n) [where n is the length of the input linked list]
 * Space complexity: O(n)
 */

void addToEnd(ListNode* & head, const int & value)
{
    if(head==nullptr)
    {
        head=new ListNode(value);
    }
    else
    {
        ListNode* current=head;

        while(current->next!=nullptr)
        {
            current=current->next;
        }

        current->next=new ListNode(value);
    }
}

ListNode* reverseKGroup(ListNode* head, int k)
{
    if(head==nullptr)
    {
        return head;
    }

    ListNode* result=nullptr;

    std::deque<ListNode*> dq;

    ListNode* current=head;

    while(current!=nullptr)
    {
        dq.emplace_back(current);

        current=current->next;
    }

    while(!dq.empty())
    {
        if(dq.size() >= k)
        {
            std::deque<ListNode*> kNodes;

            for(auto count=0;count<k;++count)
            {
                kNodes.emplace_back(dq.front());

                dq.pop_front();
            }

            while(!kNodes.empty())
            {
                addToEnd(result, kNodes.back()->val);

                kNodes.pop_back();
            }
        }
        else
        {
            addToEnd(result, dq.front()->val);

            dq.pop_front();
        }
    }

    return result;
}

ListNode* reverseChunk(ListNode* chunk)
{
    ListNode* newHead=nullptr;

    ListNode* current=chunk;

    while(current!=nullptr)
    {
        ListNode* after=current->next;

        current->next=newHead;

        newHead=current;

        current=after;
    }

    return newHead;
}

ListNode* reverseKGroup(ListNode* head, int k)
{
    if(head==nullptr || k <= 1)
    {
        return head;
    }

    int length=0;

    ListNode* walker=head;

    while(walker!=nullptr)
    {
        length++;

        walker=walker->next;
    }

    if(length < k)
    {
        return head;
    }

    int i=0;

    ListNode* result=new ListNode(-1);

    walker=result;

    ListNode* chunk=nullptr;

    ListNode* remaining=nullptr;

    ListNode* previous=nullptr;

    int reversals=0;

    int chunks=length/k;

    for(;reversals<chunks;++reversals)
    {
        if(reversals==0)
        {
            chunk=head;
        }
        else
        {
            chunk=previous;
        }

        remaining=chunk->next;

        for(auto count=0;count<k-1;++count)
        {
            chunk=chunk->next;

            remaining=remaining->next;

            i++;
        }

        chunk->next=nullptr;

        if(reversals==0)
        {
            chunk=head;
        }
        else
        {
            chunk=previous;
        }

        ListNode* reversedChunk=reverseChunk(chunk);

        while(walker->next!=nullptr)
        {
            walker=walker->next;
        }

        walker->next=reversedChunk;

        previous=remaining;
    }

    if(remaining!=nullptr)
    {
        while(walker->next!=nullptr)
        {
            walker=walker->next;
        }

        walker->next=remaining;
    }

    return result->next;
}