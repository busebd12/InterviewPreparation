#include <deque>
#include <utility>
using namespace std;

class Solution
{
    public:
        bool isEvenOddTree(TreeNode* root)
        {
            deque<pair<TreeNode*, int>> queue;

            queue.emplace_back(make_pair(root, 0));

            while(!queue.empty())
            {
                int q_size=queue.size();

                int previous=-1;

                for(int iteration=0;iteration<q_size;iteration+=1)
                {
                    auto [node, level]=queue.front();

                    queue.pop_front();

                    bool is_valid=is_valid_node(node->val, level, previous);

                    if(!is_valid)
                    {
                        return false;
                    }

                    if(node->left!=nullptr)
                    {
                        queue.emplace_back(make_pair(node->left, level + 1));
                    }

                    if(node->right!=nullptr)
                    {
                        queue.emplace_back(make_pair(node->right, level + 1));
                    }
                }
            }

            return true;
        }

        bool is_valid_node(int node_val, int level, int & previous)
        {
            if(level % 2 == 0)
            {
                if(node_val % 2 == 0)
                {
                    previous=-1;

                    return false;
                }
            
                if(previous==-1)
                {
                    previous=node_val;
                }
                else
                {
                    if(node_val <= previous)
                    {
                        previous-=1;

                        return false;
                    }
                    
                    previous=node_val;
                }
            }
            else
            {
                if(node_val % 2 == 1)
                {
                    previous=-1;

                    return false;
                }

                if(previous==-1)
                {
                    previous=node_val;
                }
                else
                {
                    if(node_val >= previous)
                    {
                        previous=-1;

                        return false;
                    }

                    previous=node_val;
                }
            }
            
            return true;
        }
};