#include <algorithm>
#include <deque>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n log n) [where n is the number of nodes in the binary tree]
Space complexity: O(n)
*/

class Solution
{
    public:
        int inOrderTraversal(TreeNode* node)
        {
            int size=0;

            deque<TreeNode*> stack;

            TreeNode* current=node;

            bool seenFirstNode=false;

            int previous=0;

            while(!stack.empty() || current!=nullptr)
            {
                while(current!=nullptr)
                {
                    stack.push_back(current);

                    current=current->left;
                }

                current=stack.back();

                stack.pop_back();

                if(seenFirstNode==false)
                {
                    previous=current->val;

                    seenFirstNode=true;

                    size+=1;
                }
                else
                {
                    if(current->val <= previous)
                    {
                        size=0;

                        break;
                    }

                    previous=current->val;

                    size+=1;
                }

                current=current->right;
            }

            return size;
        }

        int largestBSTSubtree(TreeNode* root)
        {
            int result=0;

            if(root==nullptr)
            {
                return result;
            }

            deque<TreeNode*> queue;

            queue.emplace_back(root);

            //Breadth-first traversal of the tree
            while(!queue.empty())
            {
                size_t qSize=queue.size();

                for(size_t count=0;count<qSize;count++)
                {
                    TreeNode* node=queue.front();

                    queue.pop_front();

                    //For each node, perform an in-order traversal of the subtree rooted at this node and return the size of the subtree if it is a valid binary search tree
                    int size=inOrderTraversal(node);

                    //Update the result
                    result=max(result, size);

                    if(node->left!=nullptr)
                    {
                        queue.emplace_back(node->left);
                    }

                    if(node->right!=nullptr)
                    {
                        queue.emplace_back(node->right);
                    }
                }
            }

            return result;
        }
};