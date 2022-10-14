#include <vector>
using namespace std;

/*
Time complexity: O(n^2) [where n is the number of nodes in the resulting binary search tree]
Space complexity: O(n + h) [where n is the number of nodes in the resulting binary search tree and h is the height of the binary search tree]
*/

class Solution
{
    public:
        TreeNode* bstFromPreorder(vector<int> & preorder)
        {
            TreeNode* root=nullptr;

            int n=preorder.size();

            for(int i=0;i<n;i++)
            {
                int value=preorder[i];

                constructTree(root, value);
            }

            return root;
        }

        void constructTree(TreeNode* & root, int value)
        {
            if(root==nullptr)
            {
                root=new TreeNode(value);

                return;
            }

            if(value < root->val and root->left==nullptr)
            {
                root->left=new TreeNode(value);
            }
            else if(value > root->val and root->right==nullptr)
            {
                root->right=new TreeNode(value);
            }
            else
            {
                if(value < root->val)
                {
                    constructTree(root->left, value);
                }
                else
                {
                    constructTree(root->right, value);
                }
            }
        }
};