#include "../TreeNode.h"
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
 * Solution: inspired from this video --> https://www.youtube.com/watch?v=nPtARJ2cYrg
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n)
 */

void populateHashtable(TreeNode* root, std::unordered_map<TreeNode*, TreeNode*> & nodeToParent)
{
    std::queue<TreeNode*> Q;

    Q.emplace(root);

    while(!Q.empty())
    {
        auto qSize=Q.size();

        for(auto count=0;count<qSize;++count)
        {
            auto node=Q.front();

            Q.pop();

            if(node->left!=nullptr)
            {
                nodeToParent[node->left]=node;

                Q.emplace(node->left);
            }

            if(node->right!=nullptr)
            {
                nodeToParent[node->right]=node;

                Q.emplace(node->right);
            }
        }
    }
}

void bfs(TreeNode* root, std::unordered_map<TreeNode*, TreeNode*> & nodeToParent, std::vector<int> & result, int & K)
{
    std::unordered_set<int> visited;

    std::queue<TreeNode*> Q;

    Q.emplace(root);

    visited.insert(root->val);

    int currentLevel=0;

    while(!Q.empty())
    {
        auto qSize=Q.size();

        for(auto count=0;count<qSize;++count)
        {
            auto node=Q.front();

            Q.pop();

            if(currentLevel==K)
            {
                result.emplace_back(node->val);
            }

            if(currentLevel!=K)
            {
                if(node->left!=nullptr)
                {
                    if(!visited.count(node->left->val))
                    {
                        Q.emplace(node->left);

                        visited.insert(node->left->val);
                    }
                }

                if(node->right!=nullptr)
                {
                    if(!visited.count(node->right->val))
                    {
                        Q.emplace(node->right);

                        visited.insert(node->right->val);
                    }
                }

                if(nodeToParent.count(node))
                {
                    if(!visited.count(nodeToParent[node]->val))
                    {
                        Q.emplace(nodeToParent[node]);

                        visited.insert(nodeToParent[node]->val);
                    }
                }
            }
        }

        if(currentLevel==K)
        {
            break;
        }

        currentLevel++;
    }
}

std::vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
{
    std::vector<int> result;

    if(root==nullptr)
    {
        return result;
    }

    std::unordered_map<TreeNode*, TreeNode*> nodeToParent;

    populateHashtable(root, nodeToParent);

    bfs(target, nodeToParent, result, K);

    return result;
}