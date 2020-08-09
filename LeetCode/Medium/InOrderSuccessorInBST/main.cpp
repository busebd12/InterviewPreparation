#include "../TreeNode.h"
#include <iostream>

/*
 * Solutions:
 *
 * 1. Recursive in-order traversal. We perform in-order traversal of the binary search tree and the first node
 * which has value greater than the target node is the answer.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Search Tree]
 * Space complexity: O(h) [where h is the height of the Binary Search Tree]
 *
 * 2. Iterative version of the first solution, using a std::stack<TreeNode*> to mimic the recursive stack
 * from the first solution.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Search Tree]
 * Space complexity: O(h) [where h is the height of the Binary Search Tree]
 */
class Solution
{
    public:
        void inOrderTraversal(TreeNode* root, TreeNode* p, TreeNode* & result)
        {
            if(root==nullptr)
            {
                return;
            }

            inOrderTraversal(root->left, p, result);

            if(result==nullptr && root->val > p->val)
            {
                result=root;
            }

            inOrderTraversal(root->right, p, result);
        }

        TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
        {
            TreeNode* result=nullptr;

            if(root==nullptr)
            {
                return result;
            }

            inOrderTraversal(root, p, result);

            return result;
        }
};

class Solution
{
    public:
        void inOrderTraversal(TreeNode* root, TreeNode* p, TreeNode* & result)
        {
            std::stack<TreeNode*> stk;

            TreeNode* current=root;

            while(!stk.empty() || current!=nullptr)
            {
                while(current!=nullptr)
                {
                    stk.push(current);

                    current=current->left;
                }

                current=stk.top();

                stk.pop();

                if(result==nullptr && current->val > p->val)
                {
                    result=current;
                }

                current=current->right;
            }
        }

        TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
        {
            TreeNode* result=nullptr;

            if(root==nullptr)
            {
                return result;
            }

            inOrderTraversal(root, p, result);

            return result;
        }
};