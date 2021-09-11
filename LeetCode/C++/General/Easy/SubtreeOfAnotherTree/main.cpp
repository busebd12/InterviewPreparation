#include "../TreeNode.h"
#include <iostream>
#include <string>
using namespace std;

/*
 * Approaches:
 *
 * 1) Recursion. Check if the the tree t is a subtree of the tree s starting at the root of s.
 * If it is return false. If it's not, then check to see if t is a subtree of the left-subtree of s
 * or the right subtree of s.
 *
 * Time complexity: O(n * m) [where n is the number of nodes in the tree s and m is the number of nodes in the tree t]
 * Space complexity: O(n * m) recursive stack space
 *
 * 2) Do a pre-order traversal for both s and t and store the results in strings.
 * Then, search to see if the pre-order traversal of t is contained in the pre-order traversal of s.
 *
 * Time complexity: O(n * m) [where n is the number of nodes in the tree s and m is the number of nodes in the tree t]
 * Space complexity: O(n + m)
 */

bool isIdentical(TreeNode* s, TreeNode* t)
{
    if(s==nullptr && t==nullptr)
    {
        return true;
    }

    if(s==nullptr || t==nullptr)
    {
        return false;
    }

    return (s->val==t->val) && isIdentical(s->left, t->left) && isIdentical(s->right, t->right);
}

bool isSubtree(TreeNode* s, TreeNode* t)
{
    if(s==nullptr && t==nullptr)
    {
        return true;
    }

    if(s!=nullptr && t==nullptr)
    {
        return false;
    }

    if(s==nullptr && t!=nullptr)
    {
        return false;
    }

    if(isIdentical(s, t))
    {
        return true;
    }

    return isSubtree(s->left, t) || isSubtree(s->right, t);
}

void preOrderTraversal(TreeNode* root, string & traversal)
{
    if(root==nullptr)
    {
        traversal+="#";

        return;
    }

    traversal+=("(" + to_string(root->val) + ")");

    preOrderTraversal(root->left, traversal);

    preOrderTraversal(root->right, traversal);
}

bool isSubtree(TreeNode* s, TreeNode* t)
{
    string sPreOrderTraversal{};

    string tPreOrderTraversal{};

    preOrderTraversal(s, sPreOrderTraversal);

    preOrderTraversal(t, tPreOrderTraversal);

    return sPreOrderTraversal.find(tPreOrderTraversal)!=string::npos;
}