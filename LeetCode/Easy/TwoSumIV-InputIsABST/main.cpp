#include "../TreeNode.h"
#include <iostream>
#include <unordered_map>
using namespace std;

/*
 * Approaches:
 *
 * 1) Using a hashtable (unordered_map<int, bool>), map each element in the Binary Search Tree to false.
 * Then, for each element in the hashtable, search for k-that value in the hashtable. If we find the difference, and
 * that number has not been used before, then return true. After checking all numbers, return false.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Search Tree]
 * Space complexity: O(n)
 *
 * 2) Instead of subtract the every node in the tree from k and looking for the difference in the tree,
 * For each node in the Binary Search Tree, we add it with every other node in the Binary Search Tree and see
 * if we get k. If the sum is greater than k, we recursively search in the left subtree. If the sum is less than k,
 * we recursively search in the right subtree.
 *
 * Time complexity: O(n log n) [where n is the number of nodes in the Binary Search Tree]
 * Space complexity: O(n)
 */

void populateMap(TreeNode* root, int k, unordered_map<int, bool> & differences)
{
    if(root==nullptr)
    {
        return;
    }

    differences[root->val]=false;

    populateMap(root->left, k, differences);

    populateMap(root->right, k, differences);
}

bool findTarget(TreeNode* root, int k)
{
    if(root==nullptr)
    {
        return false;
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        return false;
    }

    unordered_map<int, bool> differences;

    populateMap(root, k, differences);

    for(auto & element : differences)
    {
        int target=k-element.first;

        element.second=true;

        if(differences.count(target))
        {
            if(differences[target]==false)
            {
                return true;
            }
        }
    }

    return false;
}

bool search(TreeNode* root, int k, int value)
{
    if(root==nullptr)
    {
        return false;
    }

    int sum=root->val + value;

    if(sum==k)
    {
        if(root->val!=value)
        {
            return true;
        }
    }
    else if(sum > k)
    {
        return search(root->left, k, value);
    }
    else
    {
        return search(root->right, k, value);
    }

    return false;
}

void dfs(TreeNode* root, TreeNode* copy, int k, bool & result)
{
    if(root==nullptr)
    {
        return;
    }

    int value=root->val;

    if(search(copy, k, value))
    {
        result=true;
    }

    dfs(root->left, copy, k, result);

    dfs(root->right, copy, k, result);
}

bool findTarget(TreeNode* root, int k)
{
    if(root==nullptr)
    {
        return false;
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        return false;
    }

    TreeNode* copy=root;

    bool result=false;

    dfs(root, copy, k, result);

    return result;
}