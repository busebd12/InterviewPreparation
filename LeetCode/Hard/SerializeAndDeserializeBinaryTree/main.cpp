#include "../TreeNode.h"
#include <deque>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>

/*
 * Solutions:
 *
 * 1. We serialize the binary tree using level-order traversal and put a '#' between all the nodes.
 * We deserialize the serialized string in the following manner
 *
 * a. use a stringstream object to parse the serialized string into its individual nodes.
 * b. as we are parsing the serialized string, put each node into a deque.
 * c. use level-order traversal, again, to rebuild the tree.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n)
 *
 * 2. We serialize in the same manner as the first solution. Where this solution differs is in the deserialization.
 * The deserialization is as follows:
 *
 * a. parse the string without the help of a stringstream object and without placing each parsed-out node into a deque.
 * b. as we are parsing the string, we use a queue to perform another level-order traversal to rebuild the tree.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n)
 */
class Codec
{
    public:

        // Encodes a tree to a single string.
        std::string serialize(TreeNode* root)
        {
            std::string serialized={};

            if(root==nullptr)
            {
                return serialized;
            }

            std::queue<TreeNode*> Q;

            Q.emplace(root);

            while(!Q.empty())
            {
                auto qSize=Q.size();

                for(auto count=0;count<qSize;++count)
                {
                    auto node=Q.front();

                    Q.pop();

                    if(node==nullptr)
                    {
                        serialized+="nullptr";
                    }
                    else
                    {
                        std::string rootString=std::to_string(node->val);

                        serialized+=rootString;
                    }

                    serialized+='#';

                    if(node!=nullptr)
                    {
                        Q.emplace(node->left);

                        Q.emplace(node->right);
                    }
                }
            }

            while(!serialized.empty() && serialized.back()=='#')
            {
                serialized.pop_back();
            }

            return serialized;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(std::string data)
        {
            TreeNode* root=nullptr;

            if(data.empty())
            {
                return root;
            }

            std::deque<std::string> nodes;

            std::stringstream ss(data);

            std::string node;

            char delimeter='#';

            while(std::getline(ss, node, delimeter))
            {
                nodes.emplace_back(node);
            }

            std::queue<TreeNode*> Q;

            root=new TreeNode(std::stoi(nodes.front()));

            nodes.pop_front();

            Q.emplace(root);

            while(!Q.empty())
            {
                auto node=Q.front();

                Q.pop();

                if(!nodes.empty())
                {
                    auto leftChild=nodes.front();

                    nodes.pop_front();

                    if(leftChild!="nullptr")
                    {
                        node->left=new TreeNode(std::stoi(leftChild));

                        Q.emplace(node->left);
                    }
                }

                if(!nodes.empty())
                {
                    auto rightChild=nodes.front();

                    nodes.pop_front();

                    if(rightChild!="nullptr")
                    {
                        node->right=new TreeNode(std::stoi(rightChild));

                        Q.emplace(node->right);
                    }
                }
            }

            return root;
        }
};

class Codec
{
    public:

        // Encodes a tree to a single string.
        std::string serialize(TreeNode* root)
        {
            std::string serialized={};

            if(root==nullptr)
            {
                return serialized;
            }

            std::queue<TreeNode*> Q;

            Q.emplace(root);

            while(!Q.empty())
            {
                auto qSize=Q.size();

                for(auto count=0;count<qSize;++count)
                {
                    auto node=Q.front();

                    Q.pop();

                    if(node==nullptr)
                    {
                        serialized+="nullptr";
                    }
                    else
                    {
                        std::string rootString=std::to_string(node->val);

                        serialized+=rootString;
                    }

                    serialized+='#';

                    if(node!=nullptr)
                    {
                        Q.emplace(node->left);

                        Q.emplace(node->right);
                    }
                }
            }

            while(!serialized.empty() && serialized.back()=='#')
            {
                serialized.pop_back();
            }

            return serialized;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(std::string data)
        {
            TreeNode* root=nullptr;

            if(data.empty())
            {
                return root;
            }

            std::queue<TreeNode*> Q;

            auto n=int(data.size());

            int i=0;

            std::string rootString{};

            while(i < n && data[i]!='#')
            {
                rootString+=data[i];

                i++;
            }

            root=new TreeNode(std::stoi(rootString));

            Q.emplace(root);

            while(!Q.empty())
            {
                auto node=Q.front();

                Q.pop();

                while(i < n && data[i]=='#')
                {
                    i++;
                }

                std::string leftChild{};

                while(i < n && data[i]!='#')
                {
                    leftChild+=data[i];

                    i++;
                }

                if(!leftChild.empty() && leftChild!="nullptr")
                {
                    node->left=new TreeNode(std::stoi(leftChild));

                    Q.emplace(node->left);
                }

                while(i < n && data[i]=='#')
                {
                    i++;
                }

                std::string rightChild{};

                while(i < n && data[i]!='#')
                {
                    rightChild+=data[i];

                    i++;
                }

                if(!rightChild.empty() && rightChild!="nullptr")
                {
                    node->right=new TreeNode(std::stoi(rightChild));

                    Q.emplace(node->right);
                }
            }

            return root;
        }
};

