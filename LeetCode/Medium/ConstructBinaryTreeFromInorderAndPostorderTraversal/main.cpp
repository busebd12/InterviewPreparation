#include "../TreeNode.h"
#include <iostream>
#include <unordered_map>
#include <vector>

/*
 * Solutions:
 *
 * 1. Inspired by this video --> https://www.youtube.com/watch?v=s5XRtcud35E
 *
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 *
 * 2. Similar to the first solution except that we use a hashtable (an std::unordered_set<int, int>) to store the elements
 * of the in order traversal as to achieve constant time look-up for the root value.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

TreeNode* helper(std::vector<int> & inorder, std::vector<int> & postorder, int rootIndex, int inOrderStart, int inOrderEnd)
{
    if(rootIndex < 0 || inOrderStart > inOrderEnd)
    {
        return nullptr;
    }

    TreeNode* root=new TreeNode(postorder[rootIndex]);

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

    int rightSubtreeRootIndex=rootIndex - 1;

    int nodesInRightSubtree=inOrderEnd - inOrderIndex;

    int leftSubtreeRootIndex=rootIndex - nodesInRightSubtree - 1;

    root->left=helper(inorder, postorder, leftSubtreeRootIndex, inOrderStart, inOrderIndex-1);

    root->right=helper(inorder, postorder, rightSubtreeRootIndex, inOrderIndex+1, inOrderEnd);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    TreeNode* root=nullptr;

    if(inorder.empty() || postorder.empty())
    {
        return root;
    }

    int n=int(postorder.size());

    int rootIndex=n-1;

    int inOrderStart=0;

    int inOrderEnd=n-1;

    root=helper(inorder, postorder, rootIndex, inOrderStart, inOrderEnd);

    return root;
}

TreeNode* helper(std::vector<int> & inorder, std::vector<int> & postorder, std::unordered_map<int, int> & hashtable, int rootIndex, int inOrderStart, int inOrderEnd)
{
    if(rootIndex < 0 || inOrderStart > inOrderEnd)
    {
        return nullptr;
    }

    TreeNode* root=new TreeNode(postorder[rootIndex]);

    if(inOrderStart==inOrderEnd)
    {
        return root;
    }

    int inOrderIndex=hashtable[root->val];

    int rightSubtreeRootIndex=rootIndex - 1;

    int nodesInRightSubtree=inOrderEnd - inOrderIndex;

    int leftSubtreeRootIndex=rootIndex - nodesInRightSubtree - 1;

    root->left=helper(inorder, postorder, hashtable, leftSubtreeRootIndex, inOrderStart, inOrderIndex-1);

    root->right=helper(inorder, postorder, hashtable, rightSubtreeRootIndex, inOrderIndex+1, inOrderEnd);

    return root;
}

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder)
{
    TreeNode* root=nullptr;

    if(inorder.empty() || postorder.empty())
    {
        return root;
    }

    int n=int(postorder.size());

    std::unordered_map<int, int> hashtable;

    for(int i=0;i<n;++i)
    {
        hashtable[inorder[i]]=i;
    }

    int rootIndex=n-1;

    int inOrderStart=0;

    int inOrderEnd=n-1;

    root=helper(inorder, postorder, hashtable, rootIndex, inOrderStart, inOrderEnd);

    return root;
}