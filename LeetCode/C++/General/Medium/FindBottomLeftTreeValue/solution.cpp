#include <deque>
using namespace std;

class Solution
{
    public:
        int findBottomLeftValue(TreeNode* root)
        {
            int result=-1;

            int height=get_height(root);

            result=get_leftmost_node_in_bottom_row(root, height);

            return result;
        }

        int get_height(TreeNode* root)
        {
            if(root==nullptr)
            {
                return 0;
            }

            int left_subtree_height=get_height(root->left);

            int right_subtree_height=get_height(root->right);

            return 1 + max(left_subtree_height, right_subtree_height);
        }

        int get_leftmost_node_in_bottom_row(TreeNode* root, int last_level)
        {
            int left_most_node=-1;

            deque<TreeNode*> queue;

            queue.push_back(root);

            int level=1;

            while(!queue.empty())
            {
                int q_size=queue.size();

                for(int iteration=0;iteration<q_size;iteration++)
                {
                    TreeNode* node=queue.front();

                    queue.pop_front();

                    if(iteration==0 and level==last_level)
                    {
                        left_most_node=node->val;

                        break;
                    }

                    if(node->left!=nullptr)
                    {
                        queue.push_back(node->left);
                    }

                    if(node->right!=nullptr)
                    {
                        queue.push_back(node->right);
                    }
                }

                if(!queue.empty())
                {
                    level+=1;
                }
            }

            return left_most_node;
        }
};