#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n) [where n is the number of nodes in the binary tree]
Space complexity: O(n)
*/

class Solution
{
    public:
        string postOrderTraversal(TreeNode* root, unordered_map<string, int> & subtreeFrequency, vector<TreeNode*> & result)
        {
            if(root==nullptr)
            {
                return "";
            }
            
            //String representation of the subtree starting at the current root node
            string subtree{};
            
            //Add the root node
            subtree.append(to_string(root->val));
            
            //Add special character to ensure uniqueness
            subtree.push_back('$');
            
            //Add the left subtree
            subtree.append(inOrderTraversal(root->left, subtreeFrequency, result));
            
            //Add special character to ensure uniqueness
            subtree.push_back('$');
            
            //Add right subtree
            subtree.append(inOrderTraversal(root->right, subtreeFrequency, result));
            
            //If we've seen this subtree before, add the root to the result vector
            if(subtreeFrequency[subtree]==1)
            {
                result.push_back(root);
            }
            
            //Increment the frequency of the subtree
            subtreeFrequency[subtree]+=1;
            
            return subtree;
        }
    
        vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
        {
            vector<TreeNode*> result;
            
            unordered_map<string, int> subtreeFrequency;
            
            postOrderTraversal(root, subtreeFrequency, result);
            
            return result;
        }
};

/*
2/27/2023 solution

Submission result: accepted.

Time complexity: O(n) [where n=number of nodes in the tree]
Space complexity: O(h + n) [where h=height of tree]
*/

class Solution
{
    private:
        unordered_map<string, pair<int, TreeNode*>> subtreeFrequencies;

    public:
        vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
        {
            vector<TreeNode*> result;
            
            helper(root);

            for(pair<string, pair<int, TreeNode*>> element : subtreeFrequencies)
            {
                if(element.second.first > 1)
                {
                    result.push_back(element.second.second);
                }
            }

            return result;
        }

        string helper(TreeNode* root)
        {
            if(root==nullptr)
            {
                return "#";
            }

            string leftSubtree=helper(root->left);

            string rightSubtree=helper(root->right);

            string rootString=to_string(root->val) + "$" + leftSubtree + "$" + rightSubtree;

            if(subtreeFrequencies.find(rootString)==subtreeFrequencies.end())
            {
                subtreeFrequencies.emplace(rootString, make_pair(1, nullptr));
            }
            else
            {
                subtreeFrequencies[rootString].first+=1;

                if(subtreeFrequencies[rootString].second==nullptr)
                {
                    subtreeFrequencies[rootString].second=root;
                }
            }

            return rootString;
        }
};