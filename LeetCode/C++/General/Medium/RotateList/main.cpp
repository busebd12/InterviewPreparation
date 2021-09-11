#include "../ListNode.h"
#include <algorithm>
#include <iostream>
#include <vector>

/*
 * Solutions:
 *
 * 1. Copy the list into a vector, use the STL rotate algorithm to do the rotation, and then
 * copy the rotated elements of the vector back into the original list.
 *
 * Time complexity: O(n-squared)
 * Space complexity: O(n)
 *
 * 2. Find the start point of the elements in the original list that will be at the beginning of the new list.
 * Then, attach those numbers to the end of our result linked-list. Then, simply attach the rest of the original
 * linked-list numbers to the end of our result linked-list.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

void addToEnd(ListNode* & head, const int value)
{
    ListNode* newTail=new ListNode(value);

    if(head==nullptr)
    {
        head=newTail;
    }
    else
    {
        ListNode* current=head;

        while(current->next!=nullptr)
        {
            current=current->next;
        }

        current->next=newTail;
    }
}

ListNode* rotateRight(ListNode* head, int k)
{
    if(head==nullptr || k==0)
    {
        return head;
    }

    std::vector<int> numbers;

    ListNode* current=head;

    while(current!=nullptr)
    {
        numbers.emplace_back(current->val);

        current=current->next;
    }

    std::rotate(numbers.rbegin(), numbers.rbegin() + (k % numbers.size()), numbers.rend());

    head=nullptr;

    for(const auto & number : numbers)
    {
        addToEnd(head, number);
    }

    return head;
}

ListNode* rotateRight(ListNode* head, int k)
{
    if(head==nullptr || k==0)
    {
        return head;
    }

    ListNode* current=head;

    int length=0;

    while(current!=nullptr)
    {
        length++;

        current=current->next;
    }

    if(k==length)
    {
        return head;
    }

    if(k > length)
    {
        k=k % length;
    }

    int target=length-k;

    current=head;

    for(int i=0;i<target;++i)
    {
        current=current->next;
    }

    ListNode* result=nullptr;

    while(current!=nullptr)
    {
        addToEnd(result, current->val);

        current=current->next;
    }

    current=head;

    for(int count=0;count<target;++count)
    {
        addToEnd(result, current->val);

        current=current->next;
    }

    return result;
}