#include <deque>
using namespace std;

/*
Solution 1: iterative in-order traversal.

Time complexity: O(n) [where n is the number of nodes in the binary tree]
Space complexity: O(n)
*/

class Solution
{
    public:
        int countNodes(TreeNode* root)
        {
            int result=0;

            deque<TreeNode*> stack;

            TreeNode* current=root;

            while(!stack.empty() or current!=nullptr)
            {
                while(current!=nullptr)
                {
                    stack.push_back(current);

                    current=current->left;
                }

                current=stack.back();

                stack.pop_back();

                result+=1;

                current=current->right;
            }

            return result;
        }
};

/*
Solution 2: iterative level-order traversal.

Time complexity: O(n) [where n is the number of nodes in the binary tree]
Space complexity: O(n)
*/

class Solution
{
    public:
        int countNodes(TreeNode* root)
        {
            int result=0;

            if(root==nullptr)
            {
                return 0;
            }

            deque<TreeNode*> queue;

            queue.push_back(root);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    TreeNode* current=queue.front();

                    queue.pop_front();

                    result+=1;

                    if(current->left!=nullptr)
                    {
                        queue.emplace_back(current->left);
                    }

                    if(current->right!=nullptr)
                    {
                        queue.emplace_back(current->right);
                    }
                }
            }

            return result;
        }
};

/*
Solution 3: recursive based on properties of complete binary tree.

Time complexity: O(log(n)^2) [where n is the number of nodes in the binary tree]
Space complexity: O(log(n)^2)
*/

class Solution
{
    public:
        int countNodes(TreeNode* root)
        {
            int result=0;

            if(root==nullptr)
            {
                return 0;
            }

            int leftSubtreeHeight=getLeftSubtreeHeight(root);

            int rightSubtreeHeight=getRightSubtreeHeight(root);

            if(leftSubtreeHeight==rightSubtreeHeight)
            {
                result=((2 << leftSubtreeHeight) - 1);

                return result;
            }

            result=countNodes(root->left) + countNodes(root->right) + 1;

            return result;
        }

        int getLeftSubtreeHeight(TreeNode* root)
        {
            int height=0;

            while(root->left!=nullptr)
            {
                height+=1;

                root=root->left;
            }

            return height;
        }

        int getRightSubtreeHeight(TreeNode* root)
        {
            int height=0;

            while(root->right!=nullptr)
            {
                height+=1;

                root=root->right;
            }

            return height;
        }
};