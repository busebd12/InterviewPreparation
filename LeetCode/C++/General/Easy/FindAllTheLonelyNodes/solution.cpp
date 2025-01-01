#include <deque>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    public:
        vector<int> getLonelyNodes(TreeNode* root)
        {
            vector<int> result;

            deque<TreeNode*> queue;

            queue.push_back(root);

            while(!queue.empty())
            {
                int q_size=queue.size();

                for(int iteration=0;iteration<q_size;iteration+=1)
                {
                    TreeNode* parent=queue.front();

                    queue.pop_front();

                    if(parent->left!=nullptr and parent->right==nullptr)
                    {
                        result.push_back(parent->left->val);

                        queue.push_back(parent->left);
                    }
                    else if(parent->left==nullptr and parent->right!=nullptr)
                    {
                        result.push_back(parent->right->val);

                        queue.push_back(parent->right);
                    }
                    else if(parent->left!=nullptr and parent->right!=nullptr)
                    {
                        queue.push_back(parent->left);

                        queue.push_back(parent->right);
                    }
                }
            }

            return result;
        }
};