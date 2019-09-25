#include "../TreeNode.h"
#include <iostream>
#include <queue>
using namespace std;

/*
 * Approach: Do a level order traversal and calculate the average of each level as we go.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n)
 */

vector<double> averageOfLevels(TreeNode* root)
{
    vector<double> result;

    if(root==nullptr)
    {
        return result;
    }

    queue<TreeNode*> Q;

    Q.push(root);

    while(!Q.empty())
    {
        int qSize=int(Q.size());

        double total=0;

        for(int count=0;count<qSize;++count)
        {
            TreeNode* current=Q.front();

            Q.pop();

            total+=current->val;

            if(current->left!=nullptr)
            {
                Q.emplace(current->left);
            }

            if(current->right!=nullptr)
            {
                Q.emplace(current->right);
            }
        }

        double average=double(total/qSize);

        result.push_back(average);
    }

    return result;
}