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