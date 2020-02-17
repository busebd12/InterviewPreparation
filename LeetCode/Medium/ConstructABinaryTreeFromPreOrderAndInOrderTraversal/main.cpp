#include "../TreeNode.h"
#include <iostream>
#include <vector>
#include <unordered_map>

/*
 * Solutions:
 *
 * 1. Inspired from this video: https://www.youtube.com/watch?v=PoBGyrIWisE.
 *
 * Time complexity: O(n^2) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n)
 *
 * 2. Similar to the first solution except we use a hashtable (an std::unordered_map<int, int>) in order to facilitate
 * constant time look-up for the root index in the in-order traversal vector.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 */

TreeNode* helper(std::vector<int> & preorder, std::vector<int> & inorder, int rootIndex, int inOrderStart, int inOrderEnd)
{
    if(inOrderStart > inOrderEnd || rootIndex > preorder.size()-1)
    {
        return nullptr;
    }

    TreeNode* root=new TreeNode(preorder[rootIndex]);

    if(inOrderStart==inOrderEnd)
    {
        return root;
    }

    int inOrderIndex=0;

    for(int i=inOrderStart;i<=inOrderEnd;++i)
    {
        if(inorder[i]==root->val)
        {
            inOrderIndex=i;

            break;
        }
    }

    int leftSubtreeRootIndex=rootIndex + 1;

    int nodesInLeftSubtree=inOrderIndex - inOrderStart;

    int rightSubtreeRootIndex=rootIndex + nodesInLeftSubtree + 1;

    root->left=helper(preorder, inorder, leftSubtreeRootIndex, inOrderStart, inOrderIndex-1);

    root->right=helper(preorder, inorder, rightSubtreeRootIndex, inOrderIndex+1, inOrderEnd);

    return root;
}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
{
    TreeNode* root=nullptr;

    if(preorder.empty() || inorder.empty())
    {
        return root;
    }

    int rootIndex=0;

    int inOrderStart=0;

    int inOrderEnd=int(inorder.size()-1);

    root=helper(preorder, inorder, rootIndex, inOrderStart, inOrderEnd);

    return root;
}

TreeNode* helper(std::vector<int> & preorder, std::vector<int> & inorder, std::unordered_map<int, int> & hashtable, int rootIndex, int inOrderStart, int inOrderEnd)
{
    if(inOrderStart > inOrderEnd || rootIndex > preorder.size()-1)
    {
        return nullptr;
    }

    TreeNode* root=new TreeNode(preorder[rootIndex]);

    if(inOrderStart==inOrderEnd)
    {
        return root;
    }

    int inOrderIndex=hashtable[root->val];

    int leftSubtreeRootIndex=rootIndex + 1;

    int nodesInLeftSubtree=inOrderIndex - inOrderStart;

    int rightSubtreeRootIndex=rootIndex + nodesInLeftSubtree + 1;

    root->left=helper(preorder, inorder, hashtable, leftSubtreeRootIndex, inOrderStart, inOrderIndex-1);

    root->right=helper(preorder, inorder, hashtable, rightSubtreeRootIndex, inOrderIndex+1, inOrderEnd);

    return root;
}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
{
    TreeNode* root=nullptr;

    if(preorder.empty() || inorder.empty())
    {
        return root;
    }

    std::unordered_map<int, int> hashtable;

    int n=int(preorder.size());

    for(auto i=0;i<n;++i)
    {
        hashtable[inorder[i]]=i;
    }

    int rootIndex=0;

    int inOrderStart=0;

    int inOrderEnd=int(inorder.size()-1);

    root=helper(preorder, inorder, hashtable, rootIndex, inOrderStart, inOrderEnd);

    return root;
}