#include "../TreeNode.h"
#include <algorithm>
#include <limits>
using namespace std;

/*
Time complexity: O(n) [where n is the number of nodes in the binary tree]
Space complexity: O(h) [where h is the height of the binary tree]
*/

class Solution
{
    public:
        int goodNodes(TreeNode* root)
        {
            int result=0;
            
            int maxValue=numeric_limits<int>::min();
            
            dfs(root, result, maxValue);
            
            return result;
        }
    
        void dfs(TreeNode* root, int & result, int maxValue)
        {
            if(root==nullptr)
            {
                return;
            }
            
            if(maxValue==numeric_limits<int>::min() or maxValue <= root->val)
            {
                result+=1;
            }
            
            maxValue=max(maxValue, root->val);
            
            dfs(root->left, result, maxValue);
            
            dfs(root->right, result, maxValue);
        }
};