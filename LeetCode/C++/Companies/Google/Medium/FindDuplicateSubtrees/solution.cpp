#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: the idea is that every duplicate subtree will have the same string serialization, and we can use an unordered_map (hashtable)
to map each serization to the list of duplicate subtrees. We make use of the pre-order traversal algorithm in order to traverse the tree
and populate the map with the serializations.

Time complexity: O(n) [where n is the number of nodes in the binary tree]
Space complexity: O(h + u)) [where h is the height of the binary tree (recursive stack space) and u is the number of unique string serializations]
*/

class Solution
{
    public:
        string preOrderTraversal(unordered_map<string, vector<TreeNode*>> & hashtable, TreeNode* root)
        {
            if(root==nullptr)
            {
                return "";
            }
            
            //Create the string serialization
            string serialization="(" + preOrderTraversal(hashtable, root->left) + to_string(root->val) + preOrderTraversal(hashtable, root->right) + ")";

            //Map the serialization to the root of the tree/subtree
            hashtable[serialization].emplace_back(root);
            
            return serialization;
        }
        
    
        vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
        {
            unordered_map<string, vector<TreeNode*>> hashtable;
            
            vector<TreeNode*> roots;
            
            preOrderTraversal(hashtable, root);
            
            //Iterate throough the hashtable
            for(auto element : hashtable)
            {
                //If a key in the hashtable (serialization) is associated with more than one root node, add the first root node (all the others will be duplicates)
                //to the set of root nodes to be returned   
                if(element.second.size() > 1)
                {
                    roots.emplace_back(element.second[0]);
                }
            }
            
            return roots;
        }
};