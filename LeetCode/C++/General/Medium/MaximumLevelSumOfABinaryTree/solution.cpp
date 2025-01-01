#include <algorithm>
#include <deque>
#include <unordered_map>
using namespace std;

/*
Solution 1: breadth-first search + hashmap

Time complexity: O(n) [where n is the number of nodes in the binary tree]
Space complexity: O(n + l) [where l is the total number of level sums]
*/

class Solution
{
    public:
        int maxLevelSum(TreeNode* root)
        {
            int result=0;

            int level=1;

            unordered_map<int, int> hashmap;

            deque<TreeNode*> queue;

            queue.push_back(root);

            while(!queue.empty())
            {
                int levelSum=0;
                
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    TreeNode* node=queue.front();

                    queue.pop_front();

                    levelSum+=node->val;

                    if(node->left!=nullptr)
                    {
                        queue.emplace_back(node->left);
                    }

                    if(node->right!=nullptr)
                    {
                        queue.emplace_back(node->right);
                    }
                }

                if(hashmap.find(levelSum)==hashmap.end())
                {
                    hashmap.emplace(levelSum, level);
                }
                else
                {
                    hashmap[levelSum]=min(level, hashmap[levelSum]);
                }

                level+=1;
            }

            bool flag=false;

            int sumSoFar=0;

            for(auto & [sum, level] : hashmap)
            {
                if(flag==false)
                {
                    result=level;

                    sumSoFar=sum;

                    flag=true;
                }
                else
                {
                    if(sum > sumSoFar)
                    {
                        sumSoFar=sum;

                        result=level;
                    }
                    else if(sum==sumSoFar)
                    {
                        result=min(result, level);
                    }
                }
            }

            return result;
        }
};

/*
Solution 2: breadth-first search

Time complexity: O(n) [where n is the number of nodes in the binary tree]
Space complexity: O(n)
*/

class Solution
{
    public:
        int maxLevelSum(TreeNode* root)
        {
            int result=0;

            int level=1;

            deque<TreeNode*> queue;

            int sumSoFar=numeric_limits<int>::min();

            queue.push_back(root);

            while(!queue.empty())
            {
                int levelSum=0;
                
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    TreeNode* node=queue.front();

                    queue.pop_front();

                    levelSum+=node->val;

                    if(node->left!=nullptr)
                    {
                        queue.emplace_back(node->left);
                    }

                    if(node->right!=nullptr)
                    {
                        queue.emplace_back(node->right);
                    }
                }

                if(levelSum > sumSoFar)
                {
                    sumSoFar=levelSum;

                    result=level;
                }

                level+=1;
            }

            return result;
        }
};