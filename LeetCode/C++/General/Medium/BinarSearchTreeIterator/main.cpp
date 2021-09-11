#include "../TreeNode.h"
#include <iostream>
#include <stack>
#include <vector>

/*
 * Solutions:
 *
 * 1. Perform an in-order traversal to populate a std::vector with the nodes of the Binary Search Tree.
 * Then, loop through the vector and return each node value at each index.
 *
 * Time complexities: next() --> O(1); hasNext() --> O(1); inOrderTraversal() --> O(n) [where n is the number of nodes in the Binary Search Tree]
 * Space complexity: O(n)
 *
 * 2. Iterative version of the first solution.
 *
 * Time complexities: next() --> O(1); hasNext() --> O(1); inOrderTraversal() --> O(n) [where n is the number of nodes in the Binary Search Tree]
 * Space complexity: O(n)
 *
 * 3. In the constructor, we pre-populate the stack with all the left subtree nodes. Then, in the next function, we
 * finish the in-order traversal to get the next node in the Binary Search Tree.
 *
 * Time complexity: next() --> O(h) [where h is the height of the Binary Search Tree] hasNext() --> O(1)
 * Space complexity: O(n) [where n is the number of nodes in the Binary Search Tree]
 */

class BSTIterator
{
    public:
        std::vector<int> numbers;

        size_t index;

        BSTIterator(TreeNode* root)
        {
            inOrderTraversal(root);

            index=0;
        }

        int next()
        {
            return numbers[index++];
        }

        bool hasNext()
        {
            return index < numbers.size();
        }

        void inOrderTraversal(TreeNode* root)
        {
            if(root==nullptr)
            {
                return;
            }

            inOrderTraversal(root->left);

            numbers.emplace_back(root->val);

            inOrderTraversal(root->right);
        }
};


class BSTIterator
{
    public:
        std::vector<int> numbers;

        size_t index;

        BSTIterator(TreeNode* root)
        {
            inOrderTraversal(root);

            index=0;
        }

        int next()
        {
            return numbers[index++];
        }

        bool hasNext()
        {
            return index < numbers.size();
        }

        void inOrderTraversal(TreeNode* root)
        {
            if(root==nullptr)
            {
                return;
            }

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

                numbers.emplace_back(current->val);

                current=current->right;
            }
        }
};

class BSTIterator
{
    public:
        std::stack<TreeNode*> stk;

        TreeNode* current;

        BSTIterator(TreeNode* root)
        {
            current=root;

            while(current!=nullptr)
            {
                stk.push(current);

                current=current->left;
            }
        }

        int next()
        {
            current=stk.top();

            stk.pop();

            int value=current->val;

            if(current->right!=nullptr)
            {
                current=current->right;

                while(current!=nullptr)
                {
                    stk.push(current);

                    current=current->left;
                }
            }

            return value;
        }

        bool hasNext()
        {
            return stk.empty() ? false : true;
        }
};

int main()
{
    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}