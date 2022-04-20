/*
Solution: see comments.

Time complexity: O(n) [where n is the number of nodes in the binary search tree]
Space complexity: O(h) [where h is the height of the tree]
*/

class Solution
{
    public:
        TreeNode* trimBST(TreeNode* root, int low, int high)
        {
            if(root==nullptr)
            {
                return nullptr;
            }

            //If root's value is less than low, then root's entire left subtree will also be less than low since all
            //nodes left of the root node in a binary search tree are less than the root node
            if(root->val < low)
            {
                return trimBST(root->right, low, high);
            }

            //If root's value is greater than high, then root's entire right subtree will also be greater than high since
            //all nodes right of the root node in a binary search tree are less than the root node
            if(root->val > high)
            {
                return trimBST(root->left, low, high);
            }

            //At this point, the root node value is in the range [low, high] and so we recursively trim the left and right subtrees
            root->left=trimBST(root->left, low, high);

            root->right=trimBST(root->right, low, high);

            return root;
        }
};