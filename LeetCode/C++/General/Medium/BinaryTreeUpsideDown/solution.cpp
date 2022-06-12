/*
Solution: recursive depth-first search. See comments for more details.

Time complexity: O(n) [where n is the number of nodes in the binary tree]
Space complexity: O(h) [where h is the height of the binary tree]
*/

class Solution
{
    public:
        TreeNode* dfs(TreeNode* root)
        {
            //Base cases: root is nullptr or is a leaf node
            if(root==nullptr || root->left==nullptr && root->right==nullptr)
            {
                return root;
            }

            //Recurse as far left as possible since the left child serves as the new root node at each level
            TreeNode* upsideDownRoot=dfs(root->left);

            //Change the pointers for the children nodes
            root->left->left=root->right;

            root->left->right=root;

            //Clear the pointers for the children nodes
            root->left=nullptr;

            root->right=nullptr;

            return upsideDownRoot;
        }

        TreeNode* upsideDownBinaryTree(TreeNode* root)
        {
            TreeNode* result=nullptr;

            result=dfs(root);

            return result;
        }
};