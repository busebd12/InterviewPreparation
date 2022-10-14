#include "../TreeNode.h"
#include <unordered_map>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the number of nodes in the binary tree]
Space complexity: O(h + n + u) [where h is the height of recursive stack used during the tree traversal and u is the number of unique tree node values]
*/

class Solution
{
    public:
        int pseudoPalindromicPaths (TreeNode* root)
        {
            int result=0;
            
            vector<int> path;
            
            unordered_map<int, int> frequencies;
            
            dfs(root, result, frequencies, path);
            
            return result;
        }
    
        bool dfs(TreeNode* root, int & result, unordered_map<int, int> & frequencies, vector<int> & path)
        {
            if(root==nullptr)
            {
                return false;
            }
            
            if(frequencies.find(root->val)==end(frequencies))
            {
                frequencies.emplace(root->val, 0);
            }
            
            frequencies[root->val]+=1;
            
            path.emplace_back(root->val);
            
            if(root->left==nullptr and root->right==nullptr)
            {
                if(isValidPath(frequencies)==true)
                {
                    result+=1;
                }
                
                return true;
            }
            
            bool leftResult=dfs(root->left, result, frequencies, path);
            
            if(leftResult==true)
            {
                frequencies[path.back()]-=1;
                
                if(frequencies[path.back()]==0)
                {
                    frequencies.erase(path.back());
                }
                
                path.pop_back();
            }
            
            bool rightResult=dfs(root->right, result, frequencies, path);
            
            if(rightResult==true)
            {
                frequencies[path.back()]-=1;
                
                if(frequencies[path.back()]==0)
                {
                    frequencies.erase(path.back());
                }
                
                path.pop_back();
            }
            
            return leftResult or rightResult;
        }
    
        bool isValidPath(unordered_map<int, int> & frequencies)
        {
            int oddFrequencies=0;
            
            for(auto & [value, frequency] : frequencies)
            {
                if((frequency % 2)==1)
                {
                    oddFrequencies+=1;
                }
            }
            
            return oddFrequencies <= 1;
        }
};