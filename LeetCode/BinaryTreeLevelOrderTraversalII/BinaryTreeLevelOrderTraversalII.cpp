vector<vector<int> > levelOrderBottom(TreeNode *root)
{
    //Here we use the Breadth First Search(BFS) Algorithm;
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
    
    //we have to reverse the order to get the final result
    vector<vector<int>> final;
    
    for(int index=result.size()-1;index>=0;--index)
    {
    	final.push_back(result[index]);
    }
    
    return final;
}