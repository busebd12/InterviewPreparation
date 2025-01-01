#include <deque>
#include <unordered_map>
using namespace std;

/*
Time complexity: O(n) [where n=number of noes in the binary tree]
Space complexity: O(n)
*/

class Solution
{
    public:
        NodeCopy* copyRandomBinaryTree(Node* root)
        {
            unordered_map<Node*, NodeCopy*> hashmap;

            NodeCopy* copy=nullptr;

            if(root==nullptr)
            {
                return copy;
            }

            populateTreeWithoutChildren(hashmap, root);

            populateTreeWithChildren(hashmap, root);

            populateTreeWithRandom(hashmap, root);

            return hashmap[root];
        }

        void populateTreeWithoutChildren(unordered_map<Node*, NodeCopy*> & hashmap, Node* root)
        {
            deque<Node*> queue;

            queue.push_back(root);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    Node* node=queue.front();

                    queue.pop_front();

                    hashmap[node]=new NodeCopy(node->val);

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
        }

        void populateTreeWithChildren(unordered_map<Node*, NodeCopy*> & hashmap, Node* root)
        {
            deque<Node*> queue;

            queue.push_back(root);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    Node* node=queue.front();

                    queue.pop_front();

                    if(node->left!=nullptr)
                    {
                        hashmap[node]->left=hashmap[node->left];
                        
                        queue.emplace_back(node->left);
                    }

                    if(node->right!=nullptr)
                    {
                        hashmap[node]->right=hashmap[node->right];
                        
                        queue.emplace_back(node->right);
                    }
                }
            }
        }

        void populateTreeWithRandom(unordered_map<Node*, NodeCopy*> & hashmap, Node* root)
        {
            deque<Node*> queue;

            queue.push_back(root);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    Node* node=queue.front();

                    queue.pop_front();

                    hashmap[node]->random=hashmap[node->random];

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
        }
};