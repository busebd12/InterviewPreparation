#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;

    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode
{
    int val;

    TreeNode *left;

    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *sortedListToBST(ListNode *head)
{
    if(!head)
    {
        return nullptr;
    }

    if(!head->next)
    {
        return new TreeNode(head->val);
    }

    auto slow=head;

    auto fast=head;

    auto pre=head;

    while(fast && fast->next)
    {
        pre=slow;

        slow=slow->next;

        fast=fast->next->next;
    }

    pre->next=0;

    TreeNode* root=new TreeNode(slow->val);

    root->left=sortedListToBST(head);

    root->right=sortedListToBST(slow->next);

    return root;
}