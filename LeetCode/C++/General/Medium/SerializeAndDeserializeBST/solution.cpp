#include <deque>
#include <string>
using namespace std;

class Codec
{
    public:

        //Encodes a tree to a single string.
        //Use breadth-first search to convert the binary search tree to a string
        string serialize(TreeNode* root)
        {
            string serialization="";
            
            if(root==nullptr)
            {
                return serialization;
            }
            
            deque<TreeNode*> queue;
            
            queue.push_back(root);
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    TreeNode* node=queue.front();
                    
                    queue.pop_front();
                    
                    serialization.append(to_string(node->val));
                    
                    serialization.push_back('$');
                    
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
            
            while(!serialization.empty() and serialization.back()=='$')
            {
                serialization.pop_back();
            }
            
            return serialization;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data)
        {
            TreeNode* root=nullptr;
            
            stringstream ss(data);
            
            char delimeter='$';
            
            string current="";
            
            while(getline(ss, current, delimeter))
            {
                if(!current.empty())
                {
                    int rootValue=stoi(current);
                    
                    insert(root, rootValue);
                }
            }
            
            return root;
        }
    
        void insert(TreeNode* & root, int rootValue)
        {
            if(root==nullptr)
            {
                root=new TreeNode(rootValue);
                
                return;
            }
            
            if(root->left==nullptr and root->val > rootValue)
            {
                insert(root->left, rootValue);
            }
            else if(root->right==nullptr and root->val < rootValue)
            {
                insert(root->right, rootValue);
            }
            else
            {
                if(root->val > rootValue)
                {
                    insert(root->left, rootValue);
                }
                else
                {
                    insert(root->right, rootValue);
                }
            }
        }
};