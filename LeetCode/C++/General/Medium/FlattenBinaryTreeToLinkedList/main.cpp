#include "../TreeNode.h"
#include <iostream>

/*
 * Solution: the idea is to detach the right subtree from the current root node and put the left subtree in its place.
 * Then, we traverse down the right subtree of the new right subtree until we reach a node that has no right subtree.
 * We the old left subtree of the root node we started with the new right subtree of the current root node.
 * Then, we move down the right subtree to the next root node and repeat the process. We do this until the current
 * root node is nullptr.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

void flatten(TreeNode* root)
{
    TreeNode* current=root;

    while(current!=nullptr)
    {
        if(current->left!=nullptr)
        {
            TreeNode* leftSubtree=current->left;

            current->left=nullptr;

            TreeNode* rightSubtree=current->right;

            current->right=leftSubtree;

            TreeNode* iterator=current;

            while(iterator->right!=nullptr)
            {
                iterator=iterator->right;
            }

            iterator->right=rightSubtree;
        }

        current=current->right;
    }
}