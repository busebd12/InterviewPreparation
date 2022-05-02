#include <algorithm>
#include <deque>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/727354/C%2B%2B-or-O(n)-intuitive-BFS-solution-using-Queue-or-Detailed-Explanation

Time complexity: O(n) [where n is the number of non-null nodes in the binary tree]
Space complexity: O(n)

Note: to solve the overflow issue, use size_t instead of int. size_t has a maximum value of 2^64 - 1, while int has a max value of 2^32 - 1
*/

class Solution
{
    public:
        int widthOfBinaryTree(TreeNode* root)
        {
            size_t result=0;
        
            if(root==nullptr)
            {
                return 0;
            }

            int level=0;

            deque<pair<TreeNode*, size_t>> queue;

            queue.emplace_back(root, 1);

            while(!queue.empty())
            {
                auto qSize=queue.size();

                size_t width=(queue.back().second - queue.front().second) + 1;
                
                result=max(result, width);

                for(int count=0;count<qSize;count++)
                {
                    auto [node, index]=queue.front();

                    queue.pop_front();
                    
                    if(node->left!=nullptr)
                    {
                        size_t leftIndex=index * 2;
                        
                        queue.emplace_back(node->left, leftIndex);
                    }

                    if(node->right!=nullptr)
                    {
                        size_t rightIndex=(index * 2) + 1;
                        
                        queue.emplace_back(node->right, rightIndex);
                    }
                }
            }

            return result;
        }
};