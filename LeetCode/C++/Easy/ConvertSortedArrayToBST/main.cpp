#include "../TreeNode.h"
#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach:
 * Similar to binary search. The root node of the tree (and subtrees) will be the middle of the vector
 * (or middle of part of the vector). Then, we just create the left and right subtrees recursively,
 * cutting the search space in half each time. Since the nodes in the left-subtree can be equal to the
 * parent/root node, we have middle instead of middle-1.
 *
 * Time complexity: O(log n)
 * Space complexity: O(n)
 */

TreeNode* helper(vector<int> & nums, int low, int high)
{
    if(low >= high)
    {
        return nullptr;
    }

    int middle=low + ((high-low)/2);

    TreeNode* root=new TreeNode(nums[middle]);

    root->right=helper(nums, middle+1, high);

    root->left=helper(nums, low, middle);

    return root;
}


TreeNode* sortedArrayToBST(vector<int>& nums)
{
    if(nums.empty())
    {
        return nullptr;
    }

    int low=0;

    int high=int(nums.size());

    return helper(nums, low, high);
}