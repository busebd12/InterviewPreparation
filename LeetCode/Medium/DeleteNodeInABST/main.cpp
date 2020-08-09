#include "../TreeNode.h"
#include <iostream>

/*
 * Solution: several cases to consider
 *
 * 1. If the root is nullptr, just return the root.
 *
 * 2. If the root value is less than the key we want to delete, then we recursively delete from the left subtree.
 *
 * 3. If the root value is greater than the key we want to delete, then we recursively delete from the right subtree.
 *
 * 4. If the root value is equal to the key we want to delete, then there are four scenarios to handle:
 *
 *      a. if the root is a leaf node, then just delete it and return nullptr.
 *
 *      b. If the root node only has a right child, then delete the root and return the right subtree.
 *
 *      c. If the root node only has a left child, then delete the root and return the left subtree.
 *
 *      d. If the root has two children, then find the smallest value on the root's right subtree, replace the
 *      root's value with the value of the node we just found, and then recursively delete the duplicated node
 *      from root's right subtree.
 *
 * Time complexity: O(h) [where h is the height of the tree]
 * Space complexity: O(h)
 */

class Solution
{
    public:
        TreeNode* getSmallestInRightSubtree(TreeNode* root)
        {
            while(root && root->left)
            {
                root=root->left;
            }

            return root;
        }

        TreeNode* deleteNode(TreeNode* root, int key)
        {
            if(root==nullptr)
            {
                return root;
            }

            if(key < root->val)
            {
                root->left=deleteNode(root->left, key);
            }
            else if(key > root->val)
            {
                root->right=deleteNode(root->right, key);
            }
            else
            {
                if(root->left==nullptr && root->right==nullptr)
                {
                    delete root;

                    return nullptr;
                }
                else if(root->left==nullptr && root->right!=nullptr)
                {
                    TreeNode* temp=root->right;

                    delete root;

                    return temp;
                }
                else if(root->left!=nullptr && root->right==nullptr)
                {
                    TreeNode* temp=root->left;

                    delete root;

                    return temp;
                }
                else
                {
                    TreeNode* replacement=getSmallestInRightSubtree(root->right);

                    root->val=replacement->val;

                    root->right=deleteNode(root->right, replacement->val);
                }
            }

            return root;
        }
};