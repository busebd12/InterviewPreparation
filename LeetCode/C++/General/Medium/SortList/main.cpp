#include "../ListNode.h"
#include <iostream>

/*
 * Solution: Sort the linked-list using the merge sort algorithm.
 *
 * Time complexity: O(n * log(n)) [where n is the number of nodes in the linked-list]
 * Space complexity: O(n * log(n)) recursive stack space
 */

ListNode* getMiddleNode(ListNode* head)
{
    if(head==nullptr)
    {
        return head;
    }

    ListNode* slow=head;

    ListNode* fast=head->next;

    while(fast!=nullptr && fast->next!=nullptr && fast->next->next!=nullptr)
    {
        slow=slow->next;

        fast=fast->next->next;
    }

    return slow;
}

ListNode* mergeHelper(ListNode* left, ListNode* right)
{
    ListNode* merged=new ListNode(-1);

    ListNode* mergedWalker=merged;

    ListNode* leftWalker=left;

    ListNode* rightWalker=right;

    while(leftWalker!=nullptr && rightWalker!=nullptr)
    {
        if(leftWalker->val <= rightWalker->val)
        {
            mergedWalker->next=new ListNode(leftWalker->val);

            leftWalker=leftWalker->next;
        }
        else
        {
            mergedWalker->next=new ListNode(rightWalker->val);

            rightWalker=rightWalker->next;
        }

        mergedWalker=mergedWalker->next;
    }

    while(leftWalker!=nullptr)
    {
        mergedWalker->next=new ListNode(leftWalker->val);

        leftWalker=leftWalker->next;

        mergedWalker=mergedWalker->next;
    }

    while(rightWalker!=nullptr)
    {
        mergedWalker->next=new ListNode(rightWalker->val);

        rightWalker=rightWalker->next;

        mergedWalker=mergedWalker->next;
    }

    return merged->next;
}

ListNode* mergeSort(ListNode* head)
{
    if(head->next==nullptr)
    {
        return head;
    }

    ListNode* middle=getMiddleNode(head);

    ListNode* secondHalf=middle->next;

    middle->next=nullptr;

    ListNode* left=mergeSort(head);

    ListNode* right=mergeSort(secondHalf);

    return mergeHelper(left, right);
}

ListNode* sortList(ListNode* head)
{
    if(head==nullptr || head->next==nullptr)
    {
        return head;
    }

    ListNode* sorted=mergeSort(head);

    return sorted;
}