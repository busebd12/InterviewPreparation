#include "../TreeNode.h"
#include <deque>
using namespace std;

/*
Time complexity: O(n) [where n is the number of nodes in the binary tree]
Space complexity: O(n)
*/

class Solution
{
    public:
        TreeNode* addOneRow(TreeNode* root, int val, int depth)
        {
            TreeNode* current=nullptr;

            if(depth==1)
            {
                current=new TreeNode(val);

                current->left=root;

                return current;
            }

            current=root;

            deque<TreeNode*> queue;

            queue.push_back(current);

            int level=1;

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    TreeNode* node=queue.front();

                    queue.pop_front();
                    
                    if(level==depth - 1)
                    {
                        TreeNode* originalLeft=node->left;

                        TreeNode* originalRight=node->right;

                        node->left=nullptr;

                        node->left=new TreeNode(val);

                        node->left->left=originalLeft;

                        node->right=nullptr;

                        node->right=new TreeNode(val);

                        node->right->right=originalRight;
                    }

                    if(node->left!=nullptr)
                    {
                        queue.emplace_back(node->left);
                    }

                    if(node->right!=nullptr)
                    {
                        queue.emplace_back(node->right);
                    }
                }

                level+=1;
            }

            return root;
        }
};