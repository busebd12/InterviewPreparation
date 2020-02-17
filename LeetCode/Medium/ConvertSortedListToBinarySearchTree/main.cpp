#include "../ListNode.h"
#include "../TreeNode.h"
#include <iostream>
#include <vector>

/*
 * Solutions:
 *
 * 1. Place the linked-list nodes into a std::vector<int> and then build a the Binary Search Tree from the vector by
 * finding the mid-point of the vector, making that number the root, and then creating the left and right subtrees
 * recursively.
 *
 * Time complexity: O(log n) [where n is the number of nodes in the linked-list]
 * Space complexity: O(n)
 *
 * 2. Find the middle of the linekd-list using two-pointers. This node becomes the root of the tree.
 * Then, build the left and right subtrees recursively.
 *
 * Time complexity: O(n log n)
 * Space complexity: O(log n)
 */

TreeNode* helper(std::vector<int> & nums, int low, int high)
{
    if(low >= high)
    {
        return nullptr;
    }

    int middle=low + ((high-low)/2);

    TreeNode* root=new TreeNode(nums[middle]);

    root->right=helper(nums, middle+1, high);

    root->left=helper(nums, low, middle);

    return root;
}

TreeNode* sortedListToBST(ListNode* head)
{
    TreeNode* root=nullptr;

    if(head==nullptr)
    {
        return root;
    }

    int n=0;

    std::vector<int> nums;

    ListNode* current=head;

    while(current!=nullptr)
    {
        n++;

        nums.emplace_back(current->val);

        current=current->next;
    }

    int left=0;

    int right=n;

    root=helper(nums, left, right);

    return root;
}

TreeNode* sortedListToBST(ListNode* head)
{
    TreeNode* root=nullptr;

    if(head==nullptr)
    {
        return root;
    }

    if(head->next==nullptr)
    {
        root=new TreeNode(head->val);

        return root;
    }

    auto slow=head;

    auto fast=head;

    auto previous=slow;

    while(fast!=nullptr && fast->next!=nullptr)
    {
        previous=slow;

        slow=slow->next;

        fast=fast->next->next;
    }

    previous->next=nullptr;

    root=new TreeNode(slow->val);

    root->left=sortedListToBST(head);

    root->right=sortedListToBST(slow->next);

    return root;
}