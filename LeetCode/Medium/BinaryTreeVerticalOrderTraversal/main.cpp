#include "../TreeNode.h"
#include <iostream>
#include <map>
#include <queue>
#include <vector>

/*
 * Solution: inspired from this video --> https://www.youtube.com/watch?v=PQKkr036wRc
 *
 * Time complexity: O(n log n + k) [where n is the number of nodes in the Binary Tree and k is the number of keys in the hashtable]
 * Space complexity: O(n + k) [where n is the number of nodes in the Binary Tree and k is the number of keys in the hashtable]
 */

std::vector<std::vector<int>> verticalOrder(TreeNode* root)
{
    std::vector<std::vector<int>> result;

    if(root==nullptr)
    {
        return result;
    }

    std::map<int, std::vector<int>> hashtable;

    std::queue<std::pair<TreeNode*, int>> Q;

    Q.emplace(std::make_pair(root, 0));

    while(!Q.empty())
    {
        auto qSize=Q.size();

        for(auto count=0;count<qSize;++count)
        {
            auto current=Q.front();

            Q.pop();

            hashtable[current.second].emplace_back(current.first->val);

            if(current.first->left!=nullptr)
            {
                Q.emplace(std::make_pair(current.first->left, current.second-1));
            }

            if(current.first->right!=nullptr)
            {
                Q.emplace(std::make_pair(current.first->right, current.second+1));
            }
        }
    }

    for(const auto & [key, value] : hashtable)
    {
        result.emplace_back(value);
    }

    return result;
}