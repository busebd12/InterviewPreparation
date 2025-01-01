#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

/*
 * Solution: we use breadth-first search to serialize the N-ary tree as a string where each each character is
 * the value of each node and the number of children each node has, separated by a space. To deserialize, we use
 * breadth-first search along with a std::stringstream object to parse out the necessary information from the string.
 *
 * Time complexity: O(n) [where n is the number of nodes in the N-ary tree]
 * Space complexity: O(h) [where h is the height of the N-ary tree]
 */

class Node
{
    public:
        int val;
        std::vector<Node*> children;

        Node() {}

        Node(int _val)
        {
            val = _val;
        }

        Node(int _val, std::vector<Node*> _children)
        {
            val = _val;
            children = _children;
        }
};


class Codec
{
    public:
        // Encodes a tree to a single string.
        std::string serialize(Node* root)
        {
            std::string serialization{};

            if(root==nullptr)
            {
                return serialization;
            }

            std::queue<Node*> Q;

            Q.emplace(root);

            while(!Q.empty())
            {
                auto node=Q.front();

                Q.pop();

                serialization+=std::to_string(node->val) + " " + std::to_string(node->children.size()) + " ";

                for(const auto & child : node->children)
                {
                    Q.emplace(child);
                }
            }

            return serialization;
        }

        // Decodes your encoded data to tree.
        Node* deserialize(std::string data)
        {
            Node* root=nullptr;

            if(data.empty())
            {
                return root;
            }

            std::queue<std::pair<Node*, int>> Q;

            std::stringstream ss(data);

            std::string nodeValue{};

            std::string count{};

            ss >> nodeValue;

            ss >> count;

            root=new Node(std::stoi(nodeValue));

            int childCount=std::stoi(count);

            Q.emplace(std::make_pair(root, childCount));

            while(!Q.empty())
            {
                auto parent=Q.front();

                Q.pop();

                int children=parent.second;

                for(int i=0;i<children;i++)
                {
                    ss >> nodeValue;

                    ss >> count;

                    Node* child=new Node(std::stoi(nodeValue));

                    parent.first->children.emplace_back(child);

                    Q.emplace(std::make_pair(child, std::stoi(count)));
                }
            }

            return root;
        }
};

class Codec
{
    public:
        // Encodes a tree to a single string.
        string serialize(Node* root)
        {
            string serialized="";

            if(root==nullptr)
            {
                return serialized;
            }

            deque<Node*> queue;

            serialized.append(to_string(root->val));

            serialized.push_back('$');

            queue.push_back(root);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    Node* parent=queue.front();

                    queue.pop_front();

                    if(parent->children.empty())
                    {
                        serialized.append("nullptr");
                    }
                    else
                    {
                        for(Node* child : parent->children)
                        {
                            serialized.append(to_string(child->val));

                            serialized.push_back(',');

                            queue.push_back(child);
                        }
                    }

                    serialized.push_back('$');
                }
            }

            return serialized;
        }
        
        // Decodes your encoded data to tree.
        Node* deserialize(string data)
        {
            Node* root=nullptr;

            if(data.empty())
            {
                return root;
            }

            stringstream ss(data);

            const char parentDelimeter='$';

            const char childDelimeter=',';

            string token="";

            vector<string> children;

            while(getline(ss, token, parentDelimeter))
            {
                if(!token.empty())
                {
                    children.push_back(token);
                }
            }

            root=new Node(stoi(children[0]), vector<Node*>());

            deque<Node*> queue;

            queue.push_back(root);

            for(int i=1;i<children.size();i++)
            {
                Node* parent=queue.front();

                queue.pop_front();
                
                if(children[i]!="nullptr")
                {
                    stringstream childrenSS(children[i]);

                    string child="";

                    while(getline(childrenSS, child, childDelimeter))
                    {
                        Node* c=new Node(stoi(child), vector<Node*>());

                        parent->children.push_back(c);

                        queue.push_back(c);
                    }
                }
            }

            return root;
        }
};