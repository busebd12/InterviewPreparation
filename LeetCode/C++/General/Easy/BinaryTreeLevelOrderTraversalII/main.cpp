#include"../TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
 * Approach: Breadth-first traversal.
 * Do a level order traversal. As we store each level in a vector, add that vector to our stack.
 * Then, after we have finished the traversal, pop each level off of the stack (the levels will be in reverse order)
 * and add them to our result vector<vector<int>>.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n) [where n is the number of nodes in the binary tree]
 */

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
    vector<vector<int>> result;

    if(root==nullptr)
    {
        return result;
    }

    if(root!=nullptr && root->right==nullptr && root->left==nullptr)
    {
        vector<int> v;

        v.emplace_back(root->val);

        result.push_back(v);

        return result;
    }

    stack<vector<int>> stk;

    queue<TreeNode*> nodes;

    nodes.push(root);

    vector<int> level;

    while(true)
    {
        int qSize=int(nodes.size());

        if(qSize==0)
        {
            break;
        }

        for(int i=0;i<qSize;++i)
        {
            TreeNode* current=nodes.front();

            nodes.pop();

            level.emplace_back(current->val);

            if(current->left!=nullptr)
            {
                nodes.emplace(current->left);
            }

            if(current->right!=nullptr)
            {
                nodes.emplace(current->right);
            }
        }

        stk.push(level);

        level.clear();
    }

    while(!stk.empty())
    {
        vector<int> currentLevel=stk.top();

        stk.pop();

        result.push_back(currentLevel);
    }

    return result;
}