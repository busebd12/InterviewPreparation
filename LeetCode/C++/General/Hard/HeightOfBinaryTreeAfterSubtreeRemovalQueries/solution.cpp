#include <algorithm>
#include <deque>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/solutions/2757990/python-3-explanation-with-pictures-dfs/

Time complexity: O(n) [where n=number of nodes in the binary tree]
Space complexity: O(n)
*/

class Solution
{
    private:
        unordered_map<int, int> nodeToHeight;

        unordered_map<int, int> nodeToLevel;

        unordered_map<int, deque<pair<int, int>>> nodesOnSameLevel;
    
    public:
        vector<int> treeQueries(TreeNode* root, vector<int> & queries)
        {
            vector<int> result;

            int q=queries.size();

            result.resize(q, 0);

            int level=0;

            //Get height of tree and all subtrees while populating the nodeToHeight and nodeToLevel hashmaps
            int treeHeight=getTreeHeight(root, level);

            //For each {node, level} pair in nodeToLevel hashmap
            for(auto & [rootValue, level] : nodeToLevel)
            {
                int height=nodeToHeight[rootValue];

                //Add pair{height, root value} to list of nodes that share the same level
                nodesOnSameLevel[level].emplace_back(height, rootValue);

                //Sort the list of nodes in increasing order based on height
                sort(nodesOnSameLevel[level].begin(), nodesOnSameLevel[level].end(), less<pair<int, int>>());

                //We only want to maintain the 2 nodes with the tallest and second tallest heights because the node being removed
                //could be the one with maximum height. In that case, we need atleast one more node that has the next largest height.
                if(nodesOnSameLevel[level].size() > 2)
                {
                    nodesOnSameLevel[level].pop_front();
                }
            }

            //Iterate through the queries
            for(int i=0;i<q;i++)
            {
                int rootValue=queries[i];

                int level=nodeToLevel[rootValue];

                //If the root of the subtree we are removing is the only node on level "level", then the tallest remaining height has length level - 1
                if(nodesOnSameLevel[level].size()==1)
                {
                    result[i]=level - 1;
                }
                //Else, if the root of the subtree we are removing has the highest height on level "level",
                //then the answer is the level plus the height of the node with the second heighest height
                else if(nodesOnSameLevel[level].back().second==rootValue)
                {
                    int height=level + nodesOnSameLevel[level].front().first;

                    result[i]=height;
                }
                //Else, in all other cases, the height will the highest height of the tree
                else
                {
                    result[i]=treeHeight;
                }
            }

            return result;
        }

        int getTreeHeight(TreeNode* root, int level)
        {
            if(root==nullptr)
            {
                return -1;
            }

            int leftSubtreeHeight=getTreeHeight(root->left, level + 1);

            int rightSubtreeHeight=getTreeHeight(root->right, level + 1);

            int rootHeight=1 + max(leftSubtreeHeight, rightSubtreeHeight);

            nodeToLevel[root->val]=level;

            nodeToHeight[root->val]=rootHeight;

            return rootHeight;
        }
};