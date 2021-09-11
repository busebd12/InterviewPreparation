#include "../TreeNode.h"
#include <iostream>
#include <limits>
#include <numeric>
using namespace std;

/*
 * Approach: Find the first minimum node and then find the second minimum node based on the first minimum node.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Tree]
 * Space complexity: O(n) recursive stack space
 */
void findSecondMin(TreeNode* root, int firstMin, int & secondMin, bool & found)
{
    if(root==nullptr)
    {
        return;
    }

    if(root->val > firstMin)
    {
        if(!found)
        {
            secondMin=root->val;

            found=true;
        }
        else
        {
            if(root->val < secondMin)
            {
                secondMin=root->val;
            }
        }
    }

    findSecondMin(root->left, firstMin, secondMin, found);

    findSecondMin(root->right, firstMin, secondMin, found);
}

void findFirstMin(TreeNode* root, int & firstMin)
{
    if(root==nullptr)
    {
        return;
    }

    firstMin=min(firstMin, root->val);

    findFirstMin(root->left, firstMin);

    findFirstMin(root->right, firstMin);
}

int findSecondMinimumValue(TreeNode* root)
{
    if(root==nullptr)
    {
        return -1;
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        return -1;
    }

    int firstMin=numeric_limits<int>::max();

    findFirstMin(root, firstMin);

    int secondMin=-1;

    bool found=false;

    findSecondMin(root, firstMin, secondMin, found);

    return secondMin;
}