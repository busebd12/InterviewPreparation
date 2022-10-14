#include "../TreeNode.h"
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: inspired by this blog post -> https://www.techiedelight.com/construct-full-binary-tree-from-preorder-postorder-sequence/

Time complexity: O(n) [where n is the length of preorder and postorder]
Space complexity: O(n)
*/

class Solution
{
    public:
        TreeNode* constructFromPrePost(vector<int> & preorder, vector<int> & postorder)
        {
            TreeNode* result=nullptr;
            
            int n=postorder.size();
            
            unordered_map<int, int> hashmap;
            
            for(int i=0;i<n;i++)
            {
                hashmap.emplace(postorder[i], i);
            }
            
            int rootIndex=0;
            
            int start=0;
            
            int end=n - 1;
            
            result=helper(preorder, hashmap, rootIndex, start, end);
            
            return result;
        }
    
        TreeNode* helper(vector<int> & preorder, unordered_map<int, int> & hashmap, int & rootIndex, int start, int end)
        {
            TreeNode* root=nullptr;
            
            if(start > end)
            {
                return root;
            }
            
            root=new TreeNode(preorder[rootIndex]);
            
            rootIndex+=1;
            
            if(start==end)
            {
                return root;
            }
            
            int postOrderIndex=hashmap[preorder[rootIndex]];
            
            root->left=helper(preorder, hashmap, rootIndex, start, postOrderIndex);
            
            root->right=helper(preorder, hashmap, rootIndex, postOrderIndex + 1, end - 1);
            
            return root;
        }
};