#include "../ListNode.h"
#include <iostream>
#include <unordered_set>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) Loop over the first linked list and add its elements to the unordered_set.
 * Then, loop over the second list and if an element is already in the set,
 * we know we have found our intersection node
 *
 * Time complexity: O(m+n) [where m is the size of the first list and n is the size of the second list]
 * Space complexity: O(m) or O(n)
 *
 * 2) Using two-pointers, loop over the two arrays and calculate the sizes.
 * Then, loop over both arrays the difference between the two sizes number of times.
 * Then, loop over both arrays to find the intersection node.
 *
 * Time complexity: O(m+n) [where m and n are the sizes of the input linked lists]
 * Space complexity: O(1)
 */

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode* intersectionNode=nullptr;

    if(headA==nullptr || headB==nullptr)
    {
        return intersectionNode;
    }

    unordered_set<ListNode*> table;

    ListNode* currentA=headA;

    while(true)
    {
        table.insert(currentA);

        if(currentA->next==nullptr)
        {
            break;
        }

        currentA=currentA->next;
    }

    ListNode* currentB=headB;

    while(true)
    {
        if(table.count(currentB))
        {
            intersectionNode=currentB;

            break;
        }

        if(currentB->next==nullptr)
        {
            break;
        }

        currentB=currentB->next;
    }

    return intersectionNode;
}

int getLength(ListNode* head)
{
    ListNode* current=head;

    int length=0;

    while(true)
    {
        length++;

        if(current->next==nullptr)
        {
            break;
        }

        current=current->next;
    }

    return length;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
    ListNode* intersectionNode=nullptr;

    if(headA==nullptr || headB==nullptr)
    {
        return intersectionNode;
    }

    int n=getLength(headA);

    int m=getLength(headB);

    ListNode* currentA=headA;

    ListNode* currentB=headB;

    int difference=(n > m) ? n-m : m-n;

    while(difference > 0)
    {
        if(n > m)
        {
            currentA=currentA->next;
        }
        else
        {
            currentB=currentB->next;
        }

        difference--;
    }

    while(true)
    {
        if(currentA==currentB)
        {
            intersectionNode=currentA;

            break;
        }

        if(currentA->next==nullptr || currentB->next==nullptr)
        {
            break;
        }

        currentA=currentA->next;

        currentB=currentB->next;
    }

    return intersectionNode;
}