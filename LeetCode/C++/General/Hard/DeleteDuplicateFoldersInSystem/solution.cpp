#include <algorithm>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solutions based on these resources:

1) https://www.youtube.com/watch?v=zO9ra1zK3bo
2) https://leetcode.ca/2021-08-10-1948-Delete-Duplicate-Folders-in-System/
*/


/*
Solution 1
*/

class TrieNode
{
    private:
        unordered_map<string, unique_ptr<TrieNode>> children;

        string subdirectories;

    public:
        TrieNode()
        {
            subdirectories="";
        }

        unordered_map<string, unique_ptr<TrieNode>> & getChildren()
        {
            return children;
        }

        string & getSubdirectories()
        {
            return subdirectories;
        }
};

class Solution
{
    public:
        vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> & paths)
        {
            vector<vector<string>> result;

            unique_ptr<TrieNode> root=make_unique<TrieNode>();

            populateTrie(paths, root);

            unordered_map<string, int> frequencies;

            serializeSubdirectories(frequencies, root);

            vector<string> path;

            getRemainingPaths(frequencies, result, path, root);

            return result;
        }

        void populateTrie(vector<vector<string>> & paths, unique_ptr<TrieNode> & root)
        {
            for(vector<string> & path : paths)
            {
                TrieNode* current=root.get();

                for(string & folder : path)
                {
                    if(current->getChildren().find(folder)==current->getChildren().end())
                    {
                        current->getChildren().emplace(folder, make_unique<TrieNode>());
                    }
                    
                    current=current->getChildren()[folder].get();
                }
            }
        }

        void serializeSubdirectories(unordered_map<string, int> & frequencies, unique_ptr<TrieNode> & root)
        {
            if(root->getChildren().empty())
            {
                return;
            }

            vector<string> serializedChildren;

            for(auto & [folder, child] : root->getChildren())
            {
                serializeSubdirectories(frequencies, child);

                serializedChildren.emplace_back(folder + "(" + child->getSubdirectories() + ")");
            }

            sort(serializedChildren.begin(), serializedChildren.end());

            for(string & serializedChild : serializedChildren)
            {
                root->getSubdirectories().append(serializedChild);
            }

            string serializedSubdirectories=root->getSubdirectories();

            frequencies[serializedSubdirectories]+=1;
        }

        void getRemainingPaths(unordered_map<string, int> & frequencies, vector<vector<string>> & result, vector<string> & path, unique_ptr<TrieNode> & root)
        {
            if(frequencies[root->getSubdirectories()] > 1)
            {
                return;
            }

            if(!path.empty())
            {   
                result.push_back(path);
            }

            for(auto & [folder, child] : root->getChildren())
            {
                path.push_back(folder);

                getRemainingPaths(frequencies, result, path, child);

                path.pop_back();
            }
        }
};

/*
Solution 2
*/

class TrieNode
{
    private:
        map<string, unique_ptr<TrieNode>> children;

        string subdirectories;

    public:
        TrieNode()
        {
            subdirectories="";
        }

        map<string, unique_ptr<TrieNode>> & getChildren()
        {
            return children;
        }

        string & getSubdirectories()
        {
            return subdirectories;
        }
};

class Solution
{
    public:
        vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> & paths)
        {
            vector<vector<string>> result;

            unique_ptr<TrieNode> root=make_unique<TrieNode>();

            populateTrie(paths, root);

            unordered_map<string, int> frequencies;

            serializeSubdirectories(frequencies, root);

            vector<string> path;

            getRemainingPaths(frequencies, result, path, root);

            return result;
        }

        void populateTrie(vector<vector<string>> & paths, unique_ptr<TrieNode> & root)
        {
            for(vector<string> & path : paths)
            {
                TrieNode* current=root.get();

                for(string & folder : path)
                {
                    if(current->getChildren().find(folder)==current->getChildren().end())
                    {
                        current->getChildren().emplace(folder, make_unique<TrieNode>());
                    }
                    
                    current=current->getChildren()[folder].get();
                }
            }
        }

        void serializeSubdirectories(unordered_map<string, int> & frequencies, unique_ptr<TrieNode> & root)
        {
            if(root->getChildren().empty())
            {
                return;
            }

            vector<string> serializedChildren;

            for(auto & [folder, child] : root->getChildren())
            {
                serializeSubdirectories(frequencies, child);

                serializedChildren.emplace_back(folder + "(" + child->getSubdirectories() + ")");
            }

            for(string & serializedChild : serializedChildren)
            {
                root->getSubdirectories().append(serializedChild);
            }

            string serializedSubdirectories=root->getSubdirectories();

            frequencies[serializedSubdirectories]+=1;
        }

        void getRemainingPaths(unordered_map<string, int> & frequencies, vector<vector<string>> & result, vector<string> & path, unique_ptr<TrieNode> & root)
        {
            if(frequencies[root->getSubdirectories()] > 1)
            {
                return;
            }

            if(!path.empty())
            {   
                result.push_back(path);
            }

            for(auto & [folder, child] : root->getChildren())
            {
                path.push_back(folder);

                getRemainingPaths(frequencies, result, path, child);

                path.pop_back();
            }
        }
};