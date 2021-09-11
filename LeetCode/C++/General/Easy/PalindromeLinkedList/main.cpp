#include "../ListNode.h"
#include <iostream>
#include <stack>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) Loop through the list and push each element onto a stack. The elements are now reversed.
 * Loop through the list again and compare each element with the current element popped off the stack.
 * If we find two elements that don't match, the linked list is not a palindrome.
 *
 * Time complexity: O(n) [where n is the number of elements in the linked list]
 * Space complexity: O(n)
 *
 * 2) Use two pointers to divide the linked-list in half. Then, reverse the second half of the linked-list in-place.
 * Finally, loop over the two halves and check for elements that are not equal.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

bool isPalindrome(ListNode* head)
{
    if(head==nullptr)
    {
        return true;
    }

    if(head->next==nullptr)
    {
        return true;
    }

    stack<int> stk;

    ListNode* current=head;

    while(current!=nullptr)
    {
        stk.push(current->val);

        current=current->next;
    }

    while(head!=nullptr)
    {
        int reversed=stk.top();

        stk.pop();

        if(head->val!=reversed)
        {
            return false;
        }

        head=head->next;
    }

    return true;
}

void reverse(ListNode* head)
{
    ListNode* node1;

    ListNode* node2;

    ListNode* node3;

    node1=head;

    node2=node1->next;

    node1->next=nullptr;

    while(node2)
    {
        node3=node2->next;

        node2->next=node1;

        node1=node2;

        node2=node3;
    }
}

bool isPalindrome(ListNode* head)
{
    //lengths 0, 1 are palindrome
    if(head==nullptr || head->next==nullptr)
    {
        return true;
    }

    //length 2 goes simple judging
    if(head->next->next==nullptr)
    {
        return head->val==head->next->val;
    }

    //step 1: find middle and tail nodes
    ListNode* middle=head;

    ListNode* rbegin=head;

    while(rbegin->next!=nullptr)
    {
        if(rbegin->next->next!=nullptr)
        {
            middle=middle->next;

            rbegin=rbegin->next->next;
        }
        else
        {
            rbegin=rbegin->next;
        }
    }

    //step 2: reverse the latter half
    reverse(middle->next);

    //step 3: check for palindrome
    bool result=true;

    ListNode* node1=head;

    ListNode* node2=rbegin;

    while(node2!=nullptr)
    {
        if(node1->val!=node2->val)
        {
            result=false;

            break;
        }

        node1=node1->next;

        node2=node2->next;
    }

    //step 4: restore the reversed latter half
    reverse(rbegin);

    return result;
}