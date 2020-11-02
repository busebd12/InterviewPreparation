#include "../ListNode.h"
#include <iostream>
#include <vector>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) Copy the linked-list to a vector, sort the vector,
 * and then copy the contents of the vector to another linked-list.
 *
 * Time complexity: O(n) [where n is the size of the input linked-list]
 * Space complexity: O(n)
 *
 * 2) Create a linked-list, result, equal to nullptr.
 * Then, loop over the input linked-list and add elements
 * to the front of result.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 * 3) Using three pointers, reverse the linked-ist as we are looping through it.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

void addToEnd(ListNode* & result, int number)
{
    ListNode* current=result;

    while(current->next!=nullptr)
    {
        current=current->next;
    }

    current->next=new ListNode(number);
}

ListNode* reverseList(ListNode* head)
{
    if(head==nullptr)
    {
        return head;
    }

    if(head->next==nullptr)
    {
        return head;
    }

    vector<int> numbers;

    ListNode* current=head;

    while(current!=nullptr)
    {
        numbers.push_back(current->val);

        current=current->next;
    }

    reverse(numbers.begin(), numbers.end());

    ListNode* result=new ListNode(-1);

    for(int number : numbers)
    {
        addToEnd(result, number);
    }

    return result->next;
}

void addToFront(ListNode* & result, int number)
{
    ListNode* newHead=new ListNode(number);

    newHead->next=result;

    result=newHead;
}

ListNode* reverseList(ListNode* head)
{
    if(head==nullptr)
    {
        return head;
    }

    if(head->next==nullptr)
    {
        return head;
    }

    ListNode* result=nullptr;

    ListNode* current=head;

    while(current!=nullptr)
    {
        addToFront(result, current->val);

        current=current->next;
    }

    return result;
}

ListNode* reverseList(ListNode* head)
{
    if(head==nullptr)
    {
        return head;
    }

    if(head->next==nullptr)
    {
        return head;
    }

    ListNode* previous=nullptr;

    ListNode* current=head;

    ListNode* after=nullptr;

    while(current!=nullptr)
    {
        after=current->next;

        current->next=previous;

        previous=current;

        current=after;
    }

    return previous;
}