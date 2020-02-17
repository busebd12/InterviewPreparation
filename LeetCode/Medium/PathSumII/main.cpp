#include "../TreeNode.h"
#include <iostream>
#include <stack>
#include <tuple>
#include <vector>

/*
 * Solutions:
 *
 * 1. Recursive. As we iterate from the root node to the leaf nodes, we subtract each root value
 * from the sum. When we reach a leaf node and the sum is zero, then we know we have a valid path,
 * and we add the path to our list of paths.
 *
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 *
 * 2. Iterative version of the first solution, using a std::stack to mimic the recursive stack.
 *
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 */

void dfs(TreeNode* root, std::vector<std::vector<int>> & paths, std::vector<int> path, int sum)
{
    if(root==nullptr)
    {
        return;
    }

    sum-=root->val;

    path.emplace_back(root->val);

    if(root->left==nullptr && root->right==nullptr)
    {
        if(sum==0)
        {
            paths.push_back(path);
        }
    }

    dfs(root->left, paths, path, sum);

    dfs(root->right, paths, path, sum);
}

std::vector<std::vector<int>> pathSum(TreeNode* root, int sum)
{
    std::vector<std::vector<int>> paths;

    if(root==nullptr)
    {
        return paths;
    }

    std::vector<int> path;

    dfs(root, paths, path, sum);

    return paths;
}

std::vector<std::vector<int>> pathSum(TreeNode* root, int sum)
{
    std::vector<std::vector<int>> paths;

    if(root==nullptr)
    {
        return paths;
    }

    std::vector<int> path;

    std::stack<std::tuple<TreeNode*, std::vector<int>, int>> stk;

    stk.push(std::make_tuple(root, path, sum));

    while(!stk.empty())
    {
        auto current=stk.top();

        stk.pop();

        TreeNode* node=std::get<0>(current);

        std::get<2>(current)-=node->val;

        std::get<1>(current).push_back(node->val);

        if(node->left==nullptr && node->right==nullptr && std::get<2>(current)==0)
        {
            paths.push_back(std::get<1>(current));
        }

        if(node->right!=nullptr)
        {
            stk.push(make_tuple(node->right, std::get<1>(current), std::get<2>(current)));
        }

        if(node->left!=nullptr)
        {
            stk.push(make_tuple(node->left, std::get<1>(current), std::get<2>(current)));
        }
    }

    return paths;
}

int main()
{
    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}