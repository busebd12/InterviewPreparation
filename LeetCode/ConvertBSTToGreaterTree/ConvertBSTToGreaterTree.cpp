#include <iostream>
#include <unordered_map>
using namespace std;

void inOrderTraversalWithReplacement(TreeNode* root, unordered_map<int, int> & table)
{
    if(root==nullptr)
    {
        return;
    }
    
    inOrderTraversalWithReplacement(root->left, table);
    
    root->val=table[root->val];
    
    inOrderTraversalWithReplacement(root->right, table);
}

void inOrderTraversal(TreeNode* root, unordered_map<int, int> & table)
{
    if(root==nullptr)
    {
        return;
    }
    
    inOrderTraversal(root->left, table);
    
    table.emplace(root->val, 0);
    
    inOrderTraversal(root->right, table);
}

TreeNode* convertBST(TreeNode* root)
{
    if(root==nullptr)
    {
        return root;
    }
    
    unordered_map<int, int> table;
    
    inOrderTraversal(root, table);
    
    for(const auto & node : table)
    {
        int sum=node.first;
        
        for(const auto & element : table)
        {
            if(element > node)
            {
                sum+=element.first;
            }
        }
        
        table[node.first]=sum;
    }
    
    inOrderTraversalWithReplacement(root, table);
    
    return root;
}