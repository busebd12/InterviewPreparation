#include <iostream>
#include <string>
using namespace std;

string tree2str(TreeNode* t)
{
    if(t==nullptr)
    {
       return "";
    }

    string str=to_string(t->val);

    if(t->right)
    {
       str+="(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")";
    }   
    else if(t->left)
    {
       str+="(" + tree2str(t->left) + ")"; 
    }

    return str;
}