#include "../TreeNode.h"
#include <iostream>
#include <queue>

/*
 * Solution: we use a queue to perform breadth-first search, traversing the binary tree level-by-level and
 * place each level in a std::vector<int> and then add the vector to the std::vector<std::vector<int>> traversal.
 * Return the traversal.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n)
 */

std::vector<std::vector<int>> levelOrder(TreeNode* root)
{
    std::vector<std::vector<int>> traversal;

    if(root==nullptr)
    {
        return traversal;
    }

    std::queue<TreeNode*> Q;

    Q.push(root);

    while(!Q.empty())
    {
        int qSize=int(Q.size());

        std::vector<int> level;

        for(int count=0;count<qSize;++count)
        {
            TreeNode* current=Q.front();

            Q.pop();

            level.emplace_back(current->val);

            if(current->left!=nullptr)
            {
                Q.emplace(current->left);
            }

            if(current->right!=nullptr)
            {
                Q.emplace(current->right);
            }
        }

        traversal.push_back(level);
    }

    return traversal;
}