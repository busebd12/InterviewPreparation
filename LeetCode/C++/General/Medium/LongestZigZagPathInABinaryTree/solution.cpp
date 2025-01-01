#include <algorithm>
using namespace std;

class Solution
{
    public:
        int longestZigZag(TreeNode* root)
        {
            int result=0;

            int pathLength=0;

            int direction=0;

            dfs(root, result, direction, pathLength);

            return result;
        }

        void dfs(TreeNode* root, int & result, int direction, int pathLength)
        {
            if(root==nullptr)
            {
                return;
            }

            result=max(result, pathLength);

            if(direction==0)
            {
                dfs(root->left, result, direction=-1, pathLength + 1);

                dfs(root->right, result, direction=1, pathLength + 1);
            }
            else if(direction==-1)
            {
                if(root->right!=nullptr)
                {
                    dfs(root->right, result, direction=1, pathLength + 1);
                }

                if(root->left!=nullptr)
                {
                    dfs(root->left, result, direction=-1, pathLength=1);
                }
            }
            else if(direction==1)
            {
                if(root->left!=nullptr)
                {
                    dfs(root->left, result, direction=-1, pathLength + 1);
                }

                if(root->right!=nullptr)
                {
                    dfs(root->right, result, direction=1, pathLength=1);
                }
            }
        }
};