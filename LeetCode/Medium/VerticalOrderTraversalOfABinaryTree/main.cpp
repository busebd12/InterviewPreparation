#include "../TreeNode.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

/*
 * Solution: level-order traversal + hashtable. We do our normal level-order traversal but instead of storing only
 * TreeNode* in the queue, we store a pair of TreeNode* and pair of integers. The pair of integers represents the
 * coordinate pair (x, y) for each node. The root node has a coordinate of (0, 0) and each right child node has a
 * coordinate value of (x+1, y-1) and each left child node has a coordinate value of (x-1, y-1). As we remove each
 * pair from the queue, each node's x-value gets mapped to a vector of pair of integers. The first number in the pair
 * is themTreeNode's value and the second number is the y-value. Then, for each x-value in the map, we using a custom sort
 * function to sort the vector of pairs in the following manner: if the node values are not equal, sort them in descending
 * order. If the node values are equal, then sort them by their y-coordinate value in ascending order. Finally, for
 * each key in the hashtable, add each vector it maps to to our std::vector<std::vector<int>> result.
 *
 * Time complexity: O((n * log(n)) + O(k * log(m))) [where n is the number of nodes in the Binary Tree, k is the number
 * of keys in the hashtable, and m is number of values that are associated with each key]
 *
 * Space complexity: O(n + k)
 */

std::vector<std::vector<int>> verticalTraversal(TreeNode* root)
{
    std::vector<std::vector<int>> result;

    if(root==nullptr)
    {
        return result;
    }

    std::map<int, std::vector<std::pair<int, int>>> hashtable;

    std::queue<std::pair<TreeNode*, std::pair<int, int>>> Q;

    std::pair<int, int> coordinate(0, 0);

    Q.emplace(std::make_pair(root, coordinate));

    while(!Q.empty())
    {
        auto qSize=Q.size();

        for(auto count=0;count<qSize;count++)
        {
            auto current=Q.front();

            Q.pop();

            hashtable[current.second.first].emplace_back(std::make_pair(current.first->val, current.second.second));

            if(current.first->left!=nullptr)
            {
                std::pair<int, int> leftCoordinate(current.second.first-1, current.second.second-1);

                Q.emplace(std::make_pair(current.first->left, leftCoordinate));
            }

            if(current.first->right!=nullptr)
            {
                std::pair<int, int> rightCoordinate(current.second.first+1, current.second.second-1);

                Q.emplace(std::make_pair(current.first->right, rightCoordinate));
            }
        }
    }

    auto comparator=[] (auto & p1, auto & p2)
    {
        if(p1.second!=p2.second)
        {
            return p1.second > p2.second;
        }

        return p1.first < p2.first;
    };

    for(auto & [key, value] : hashtable)
    {
        std::sort(value.begin(), value.end(), comparator);
    }

    for(const auto & [key, value] : hashtable)
    {
        std::vector<int> vertical;

        for(const auto & element : value)
        {
            vertical.emplace_back(element.first);
        }

        result.emplace_back(vertical);
    }

    return result;
}