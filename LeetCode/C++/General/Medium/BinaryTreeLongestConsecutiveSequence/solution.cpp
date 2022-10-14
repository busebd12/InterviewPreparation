#include <algorithm>
using namespace std;


/*
Solution: inspired by this post --> https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/discuss/74468/Easy-Java-DFS-is-there-better-time-complexity-solution

Time complexity: O(n) [where n is the number of nodes in the binary tree]
Space complexity: O(h) [where h is the height of the binary tree]
*/

class Solution
{
    private:
        int result=0;
    
    public:
        int longestConsecutive(TreeNode* root)
        {
            int length=0;
            
            int target=root->val;
            
            dfs(root, length, target);
            
            return result;
        }
    
        void dfs(TreeNode* root, int length, int target)
        {
            if(root==nullptr)
            {
                return;
            }
            
            if(root->val==target)
            {
                length+=1;
            }
            else
            {
                length=1;
            }
            
            result=max(result, length);
            
            dfs(root->left, length, root->val + 1);
            
            dfs(root->right, length, root->val + 1);
        }
};