#include <algorithm>
using namespace std;

/*
Time complexity: O(n) [where n is the number of nodes in the binary tree]
Space complexity: O(h) [where h is the height of the binary tree]
*/

class Solution
{
    public:
        int longestUnivaluePath(TreeNode* root)
        {
            int result=0;

            if(root==nullptr)
            {
                return result;
            }

            helper(root, result);

            return result;
        }

        int helper(TreeNode* root, int & result)
        {
            if(root==nullptr)
            {
                return 0;
            }

            int leftSubtreePathLength=helper(root->left, result);

            int rightSubtreePathLength=helper(root->right, result);

            if(root->left!=nullptr and root->left->val==root->val)
            {
                leftSubtreePathLength+=1;
            }
            else
            {
                leftSubtreePathLength=0;
            }

            if(root->right!=nullptr and root->right->val==root->val)
            {
                rightSubtreePathLength+=1;
            }
            else
            {
                rightSubtreePathLength=0;
            }

            int totalPathLength=leftSubtreePathLength + rightSubtreePathLength;

            result=max(result, totalPathLength);

            return max(leftSubtreePathLength, rightSubtreePathLength);
        }        
};