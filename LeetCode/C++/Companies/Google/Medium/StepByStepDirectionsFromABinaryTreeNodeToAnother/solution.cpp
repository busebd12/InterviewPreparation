#include <algorithm>
#include <string>

/*
Solution: see comments for details

Time complexity: O(n) [where n is the number of nodes in the tree]
Space complexity: O(n)
*/

class Solution
{
    public:
        TreeNode* getLCA(TreeNode* root, int startValue, int destValue)
        {
            if(root==nullptr)
            {
                return nullptr;
            }
            
            if(root->val==startValue || root->val==destValue)
            {
                return root;
            }
            
            TreeNode* left=getLCA(root->left, startValue, destValue);
            
            TreeNode* right=getLCA(root->right, startValue, destValue);
            
            if(left!=nullptr && right!=nullptr)
            {
                return root;
            }
            
            return (left!=nullptr) ? left : right;
        }
    
        bool dfs(TreeNode* root, string & path, int target)
        {
            if(root==nullptr)
            {
                return false;
            }
            
            //If we find our target node, we are done
            if(root->val==target)
            {
                return true;
            }
            
            //Try searching for the target node in the left subtree
            path.push_back('L');
            
            if(dfs(root->left, path, target))
            {
                return true;
            }
            
            //Did not find the target node in the left subtree, so remove the 'L' from the end of the path
            path.pop_back();
            

            //Try searching for the target node in the right subtree
            path.push_back('R');
            
            if(dfs(root->right, path, target))
            {
                return true;
            }
            
            //Did not find the target node in the right subtree, so remove the 'R' from the end of the path
            path.pop_back();
            
            //Did not find the node in either the right or left subtrees
            return false;
        }
    
        string getDirections(TreeNode* root, int startValue, int destValue)
        {
            string result{};
            
            //Find the lowest common ancestor for both the startValue and the destValue nodes
            //The shortest path between these two nodes will pass through the lowest common ancestor
            TreeNode* LCA=getLCA(root, startValue, destValue);
            
            //The path from the lowest common ancestor to the startValue node
            string lcaToStart{};
            
            //Find the path from the lowest common ancestor to the startValue node
            dfs(LCA, lcaToStart, startValue);
            
            //The path from the lowest common ancestor to the destValue node
            string lcaToDest{};
            
            //Find the path from the lowest common ancestor to the destValue node
            dfs(LCA, lcaToDest, destValue);
            
            //Since we have to go from the startValue node to destValue node, we will traverse the lowest common ancestor to startValue node
            //but in reverse. So, we need to make every character in the path from the lowest common ancestor to the startValue node a 'U'
            for_each(begin(lcaToStart), end(lcaToStart), [](char & c){c='U';});
            
            //Shortest path is the startValue node -> lowest common ancestor -> destValue node
            result=lcaToStart + lcaToDest;
            
            return result;
        }
};