#include <algorithm>
#include <utility>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/discuss/101520/DFS-C%2B%2B-Python-solutions

Time complexity: O(n) [where n is the number of nodes in the binary tree]
Space complexity: O(h) [where n is the height of the binary tree]
*/

class Solution
{
    public:
        int longestConsecutive(TreeNode* root)
        {
            int result=0;
            
            helper(root, result);
            
            return result;
        }
    
        pair<int, int> helper(TreeNode* root, int & result)
        {
            if(root==nullptr)
            {
                return make_pair(0, 0);
            }
            
            auto [leftSubtreeIncreasingPath, leftSubtreeDecreasingPath]=helper(root->left, result);
            
            auto [rightSubtreeIncreasingPath, rightSubtreeDecreasingPath]=helper(root->right, result);
            
            int currentIncreasingPathLength=1;
            
            int currentDecreasingPathLength=1;
            
            if(root->left!=nullptr)
            {
                if(root->left->val - 1 == root->val)
                {
                    currentIncreasingPathLength+=leftSubtreeIncreasingPath;
                }
                else if(root->left->val + 1 == root->val)
                {
                    currentDecreasingPathLength+=leftSubtreeDecreasingPath;
                }
            }
            
            if(root->right!=nullptr)
            {
                if(root->right->val - 1 == root->val)
                {
                    currentIncreasingPathLength=max(currentIncreasingPathLength, rightSubtreeIncreasingPath + 1);
                }
                else if(root->right->val + 1 == root->val)
                {
                    currentDecreasingPathLength=max(currentDecreasingPathLength, rightSubtreeDecreasingPath + 1);
                }
            }
            
            int currentRootLongestPathLength=(currentIncreasingPathLength + currentDecreasingPathLength) - 1;
            
            result=max(result, currentRootLongestPathLength);
            
            return make_pair(currentIncreasingPathLength, currentDecreasingPathLength);
        }
};