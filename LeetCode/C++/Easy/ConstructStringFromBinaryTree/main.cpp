#include "../TreeNode.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
 * Approach: recursively traverse the binary tree in a pre-order fashion and if root node is not null,
 * then add the root value to the result string. Then, if the left child is null, add "()" to the result.
 * If the left child is not null, append an opening parenthesis to the result, call the function recursively,
 * and then append a closing parenthesis to the result. If the right child is not null, then do the same.
 *
 * Time complexity: O(n)
 * Space complexity: O(n) recursive stack space
 */

void preOrderTraversal(TreeNode* root, string & traversal)
{
    if(root==nullptr)
    {
        return;
    }

    traversal+=to_string(root->val);

    if(root->left==nullptr && root->right==nullptr)
    {
        return;
    }

    if(root->left==nullptr)
    {
        traversal+="()";
    }
    else
    {
        traversal+="(";

        preOrderTraversal(root->left, traversal);

        traversal+=")";
    }

    if(root->right!=nullptr)
    {
        traversal+="(";

        preOrderTraversal(root->right, traversal);

        traversal+=")";
    }
}

string tree2str(TreeNode* t)
{
    string result{};

    if(t==nullptr)
    {
        return result;
    }

    preOrderTraversal(t, result);

    return result;
}