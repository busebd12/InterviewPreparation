#include <iostream>
using namespace std;

struct TreeLinkNode
{
    int val;

    TreeLinkNode *left, *right, *next;

    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root)
{
    if(root==nullptr || (!root->right && !root->left))
    {
        return;
    }

    //point left subtree next pointer to right subtree
    if(root->left)
    {
        root->left->next=root->right;
    }

    TreeLinkNode* current=root->right ? root->right : root->left;

    if(current)
    {
        TreeLinkNode* temp=root->next;

        //point either root->right->next or root->left->next (depending on which is not null)
        //to either root->next->right or root->next->left
        while(temp)
        {
            if(temp->left || temp->right)
            {
                current->next=temp->left ? temp->left : temp->right;

                break;
            }

            temp=temp->next;
        }
    }

    connect(root->right);

    connect(root->left);
}