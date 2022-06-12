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
        string inOrderTraversal(TreeNode* root, unordered_map<string, int> & subtreeFrequency, vector<TreeNode*> & result)
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
            
            inOrderTraversal(root, subtreeFrequency, result);
            
            return result;
        }
};