#include "../TreeNode.h"
#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

/*
 * Approach: top-down depth-first search. For each node, we calculate the sum of both its subtrees
 * and the tilt and store both values in a pair. We also add the current tilt value to our result integer.
 * We then return the pair.
 *
 * Time complexity: O(n) [where is the number of nodes in the binary tree]
 * Space complexity: O(log n)
 */

pair<int, int> dfs(TreeNode* root, int & result)
{
    if(root==nullptr)
    {
        return make_pair(0, 0);
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        return make_pair(root->val, 0);
    }

    pair<int, int> left=dfs(root->left, result);

    pair<int, int> right=dfs(root->right, result);

    int tilt=abs(left.first - right.first);

    int sum=root->val + left.first + right.first;

    result+=tilt;

    return make_pair(sum, tilt);
}

int findTilt(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        return 0;
    }

    int result=0;

    pair<int, int> sumTiltPair=dfs(root, result);

    return result;
}