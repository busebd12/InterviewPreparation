#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>

/*
Solution:
The idea is based on topological sort. In a binary tree, each node has an outdegree of either zero, one, or two, depending
on how many children the node has. A leaf node, by definition, has zero children, so its outdegree will be zero. So, in order
to solve this problem, we do the following:

1) Create two maps, one to map the child node to its parent node and one to track the outdegree for each node in the tree (how many children does the node have)

2) Iterate through the tree and fill into the two maps

3) Once we've generated the two maps, we simply add all the leaf nodes (nodes with an outdegree of zero) to a queue of TreeNodes

4) Then, while the queue is not empty, each time we remove a node, we add it to the current level of leaf nodes, decrement the outdegree of its
parent node, and if the parent node has an outdegree of zero, then it is part of the next level of leaf nodes and we add it to the queue. After
adding all the current level leaf nodes to a vector, we add that vector to the vector of vectors.

5) Return the final list of all leaf nodes

Time complexity: O(n) [where n is the number of nodes in the binary tree]
Space complexity: O(n) [where n is the number of nodes in the binary tree]
*/

class Solution
{
    public:
        void buildMaps(unordered_map<TreeNode*, TreeNode*> & childToParentMap, unordered_map<TreeNode*, int> & outdegreeMap, TreeNode* root)
        {
            if(root==nullptr)
            {
                return;
            }
            
            if(root->left==nullptr && root->right==nullptr)
            {
                outdegreeMap.insert(make_pair(root, 0));
                
                return;
            }
            
            int nodeOutdegree=0;
            
            if(root->left!=nullptr)
            {
                nodeOutdegree++;
                
                childToParentMap.insert(make_pair(root->left, root));
            }
            
            if(root->right!=nullptr)
            {
                nodeOutdegree++;
                
                childToParentMap.insert(make_pair(root->right, root));
            }
            
            outdegreeMap.insert(make_pair(root, nodeOutdegree));
            
            buildMaps(childToParentMap, outdegreeMap, root->left);
            
            buildMaps(childToParentMap, outdegreeMap, root->right);  
        }
        
        
        vector<vector<int>> findLeaves(TreeNode* root)
        {
            vector<vector<int>> leaves;
            
            if(root==nullptr)
            {
                return leaves;
            }
            
            unordered_map<TreeNode*, TreeNode*> childToParentMap;
            
            unordered_map<TreeNode*, int> outdegreeMap;
            
            buildMaps(childToParentMap, outdegreeMap, root);
            
            queue<TreeNode*> Q;
            
            for(auto itr : outdegreeMap)
            {
                if(itr.second==0)
                {
                    Q.emplace(itr.first);
                }
            }
            
            while(!Q.empty())
            {
                int qSize=Q.size();
                
                vector<int> level;
                
                for(int count=0;count<qSize;count++)
                {
                    TreeNode* node=Q.front();
                    
                    Q.pop();
                    
                    level.emplace_back(node->val);
                    
                    if(node!=root)
                    {
                        outdegreeMap[childToParentMap[node]]-=1;
                        
                        if(outdegreeMap[childToParentMap[node]]==0)
                        {
                            Q.emplace(childToParentMap[node]);
                        }
                    }
                }
                
                leaves.emplace_back(level);
            }
            
            return leaves;
        }
};

/*
Solution:
The idea is based on topological sort. In a binary tree, each node has an outdegree of either zero, one, or two, depending
on how many children the node has. A leaf node, by definition, has zero children, so its outdegree will be zero. So, in order
to solve this problem, we do the following:

1) Create two maps, one to map the child node to its parent node and one to track the outdegree for each node in the tree (how many children does the node have)

2) Iterate through the tree and fill into the two maps

3) Once we've generated the two maps, we simply add all the leaf nodes (nodes with an outdegree of zero) to a queue of TreeNodes

4) Then, while the queue is not empty, each time we remove a node, we add it to the current level of leaf nodes, decrement the outdegree of its
parent node, and if the parent node has an outdegree of zero, then it is part of the next level of leaf nodes and we add it to the queue. After
adding all the current level leaf nodes to a vector, we add that vector to the vector of vectors.

5) Return the final list of all leaf nodes

The only difference between this solution and the first one is that the maps are filled in iteratively (using an explicit stack) instead of
recursively (using an implicit stack).

Time complexity: O(n) [where n is the number of nodes in the binary tree]
Space complexity: O(n) [where n is the number of nodes in the binary tree]
*/

class Solution
{
    public:
        
        vector<vector<int>> findLeaves(TreeNode* root)
        {
            vector<vector<int>> leaves;
            
            if(root==nullptr)
            {
                return leaves;
            }
            
            unordered_map<TreeNode*, TreeNode*> childToParentMap;
            
            unordered_map<TreeNode*, int> outdegreeMap;
            
            stack<TreeNode*> stk;
            
            stk.push(root);
            
            while(!stk.empty())
            {
                TreeNode* node=stk.top();
                
                stk.pop();
                
                if(node->left==nullptr && node->right==nullptr)
                {
                    outdegreeMap.insert(make_pair(node, 0));
                }
                
                int nodeOutdegree=0;
                
                if(node->left!=nullptr)
                {
                    nodeOutdegree++;
                    
                    childToParentMap.insert(make_pair(node->left, node));
                    
                    stk.push(node->left);
                }
                
                if(node->right!=nullptr)
                {
                    nodeOutdegree++;
                    
                    childToParentMap.insert(make_pair(node->right, node));
                    
                    stk.push(node->right);
                }
                
                outdegreeMap.insert(make_pair(node, nodeOutdegree));
            }
            
            queue<TreeNode*> Q;
            
            for(auto itr : outdegreeMap)
            {
                if(itr.second==0)
                {
                    Q.emplace(itr.first);
                }
            }
            
            while(!Q.empty())
            {
                int qSize=Q.size();
                
                vector<int> level;
                
                for(int count=0;count<qSize;count++)
                {
                    TreeNode* node=Q.front();
                    
                    Q.pop();
                    
                    level.emplace_back(node->val);
                    
                    if(node!=root)
                    {
                        outdegreeMap[childToParentMap[node]]-=1;
                        
                        if(outdegreeMap[childToParentMap[node]]==0)
                        {
                            Q.emplace(childToParentMap[node]);
                        }
                    }
                }
                
                leaves.emplace_back(level);
            }
            
            return leaves;
        }
};