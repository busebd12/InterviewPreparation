#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution
{
    public:
        Node* findRoot(vector<Node*> tree)
        {
            Node* root=nullptr;

            unordered_set<Node*> children;

            for(Node* node : tree)
            {
                if(!node->children.empty())
                {
                    for(Node* child : node->children)
                    {
                        auto [iterator, success]=children.insert(child);
                    }
                }
            }

            for(Node* node : tree)
            {
                if(children.find(node)==children.end())
                {
                    root=node;

                    break;
                }
            }

            return root;
        }
};

class Solution
{
    public:
        Node* findRoot(vector<Node*> tree)
        {
            Node* root=nullptr;

            unordered_map<Node*, vector<Node*>> graph;

            unordered_map<Node*, int> outdegree;

            for(Node* node : tree)
            {
                outdegree[node]=node->children.size();

                if(!node->children.empty())
                {
                    for(Node* child : node->children)
                    {
                        graph[child].push_back(node);
                    }
                }
            }

            deque<Node*> queue;

            for(auto & [node, degree] : outdegree)
            {
                if(degree==0)
                {
                    queue.push_back(node);
                }
            }

            while(!queue.empty())
            {
                Node* node=queue.front();

                queue.pop_front();

                root=node;

                for(Node* parent : graph[node])
                {
                    outdegree[parent]-=1;

                    if(outdegree[parent]==0)
                    {
                        queue.push_back(parent);
                    }
                }
            }

            return root;
        }
};