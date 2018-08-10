#include <iostream>
using namespace std;

struct TreeLinkNode
{
    int val;

    TreeLinkNode *left, *right, *next;

    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL){}
};

void connect(TreeLinkNode *root)
{
    if(root==nullptr || (!root->right && !root->left))
    {
        return;
    }

    root->left->next=root->right;

    if(root->next)
    {
        root->right->next=root->next->left;
    }

    connect(root->left);

    connect(root->right);
}