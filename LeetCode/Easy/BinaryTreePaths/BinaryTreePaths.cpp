#include <iostream>
#include <vector>
#include <string>
using namespace std;

void binaryTreePaths(vector<string>& paths, TreeNode* root, string path)
{
    if(!root->left && !root->right)
    {
        paths.push_back(path);
        
        return;
    }

    if(root->left!=nullptr)
    {
        binaryTreePaths(paths, root->left, path + "->" + to_string(root->left->val));
    }
    
    if(root->right!=nullptr)
    {
        binaryTreePaths(paths, root->right, path + "->" + to_string(root->right->val));
    }
}

vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> paths;
    
    if(root==nullptr)
    {
        return paths;
    }

    binaryTreePaths(paths, root, to_string(root->val));
    
    return paths;
}