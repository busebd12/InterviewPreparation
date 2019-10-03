#include "../TreeNode.h"
#include <iostream>
using namespace std;

/*
 * Approach: recursive go through the BST and handle the following cases using the strict
 * ordering property of Binary Search Trees --> All nodes with value less or equal to root's value
 * are in root's left subtree. All nodes with value greater than the root value are in root's right subtree.
 *
 * 1) If the root is null, return nullptr
 * 2) Else if the root value is the value we are searching for, then return the root (search complete!)
 * 3) Else if the root value is greater than our target value, then we need to search in root's left-subtree
 * 4) Else if the root value is less than our target value, then we need to search in root's right-subtree
 * 5) Else, return nullptr;
 *
 * Time complexity: O(log n) [where n is the number of nodes in the Binary Search Tree]
 * Space complexity: O(log n) recursive stack space
 */

TreeNode* searchBST(TreeNode* root, int val)
{
    if(root==nullptr)
    {
        return nullptr;
    }
    else if(root->val==val)
    {
        return root;
    }
    else if(root->val > val)
    {
        return searchBST(root->left, val);
    }
    else if(root->val < val)
    {
        return searchBST(root->right, val);
    }
    else
    {
        return nullptr;
    }
}