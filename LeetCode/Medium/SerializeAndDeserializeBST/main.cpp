#include <iostream>
#include <string>
#include <queue>
using namespace std;


struct TreeNode
{
    int val;

    TreeNode *left;

    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insert(TreeNode* & root, const int value)
{
    TreeNode* node=new TreeNode(value);

    if(root==nullptr)
    {
        root=node;

        return;
    }
    else if(value < root->val)
    {
        insert(root->left, value);
    }
    else
    {
        insert(root->right, value);
    }
}

//Encodes a tree to a single string using level-order traversal
string serialize(TreeNode* root)
{
    string serialization{};

    if(root==nullptr)
    {
        return serialization;
    }

    if(root!=nullptr && root->right==nullptr && root->left==nullptr)
    {
        serialization+=to_string(root->val);

        return serialization;
    }

    queue<TreeNode*> nodes;

    nodes.emplace(root);

    while(true)
    {
        int nodesInCurrentLevel=int(nodes.size());

        if(nodesInCurrentLevel==0)
        {
            break;
        }

        while(nodesInCurrentLevel > 0)
        {
            TreeNode* current=nodes.front();

            nodes.pop();

            serialization+=to_string(current->val);

            serialization+='#';

            if(current->left!=nullptr)
            {
                nodes.emplace(current->left);
            }

            if(current->right!=nullptr)
            {
                nodes.emplace(current->right);
            }

            --nodesInCurrentLevel;
        }

        serialization+='$';
    }

    return serialization;
}

//Decodes your encoded string to a tree.
TreeNode* deserialize(string data)
{
    int n=int(data.size());

    int i=0;

    TreeNode* bst=nullptr;

    while(i < n)
    {
        string str{};

        if(data[i]!='$' || data[i]!='#')
        {
            while(data[i]!='$' && data[i]!='#')
            {
                str+=data[i];

                ++i;
            }

            if(!str.empty())
            {
                int value=stoi(str);

                insert(bst, value);
            }
        }

        ++i;
    }

    return bst;
}