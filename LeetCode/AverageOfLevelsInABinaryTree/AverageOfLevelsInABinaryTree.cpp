#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > levelOrderBottom(TreeNode *root)
{
    //Here, we use the Breadth First Search(BFS) Algorithm;
    vector<vector<int>> result;

    vector<int> level;

    queue<TreeNode*> myQueue;

    if(root==NULL)
    {
        return result;
    }

    myQueue.push(root);

    int nodesInCurrentLevel=1;

    int nodesInNextLevel=0;

    while(!myQueue.empty())
    {
        TreeNode* currentRoot=myQueue.front();

        myQueue.pop();

        level.push_back(currentRoot->val);

        --nodesInCurrentLevel;

        if(currentRoot->left!=NULL)
        {
            myQueue.push(currentRoot->left);

            ++nodesInNextLevel;
        }

        if(currentRoot->right!=NULL)
        {
            myQueue.push(currentRoot->right);

            ++nodesInNextLevel;
        }

        //if we have traversed current level, turn to next level
        if(nodesInCurrentLevel==0)
        {
            result.push_back(level);

            level.clear();

            nodesInCurrentLevel=nodesInNextLevel;

            nodesInNextLevel=0;
        }
    }

    return result;
}

vector<double> averageOfLevels(TreeNode* root)
{
    vector<vector<int>> levelOrderTraversal=levelOrderBottom(root);
    
    vector<double> averages;
    
    for(auto & level : levelOrderTraversal)
    {
        double average=0;
        
        const size_t levelSize=level.size();
        
        for(const auto & element : level)
        {
            average+=element;
        }
        
        average/=levelSize;
        
        averages.push_back(average);
    }
    
    return averages;
}