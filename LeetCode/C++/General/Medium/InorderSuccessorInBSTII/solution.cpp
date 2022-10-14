class Solution
{
    public:
        Node* inorderSuccessor(Node* node)
        {
            Node* result=nullptr;
            
            //If there is only one node in the tree
            if(node->parent==nullptr and node->left==nullptr and node->right==nullptr)
            {
                return result;
            }
            
            //If the right child of the current node is null
            if(node->right==nullptr)
            {
                //If the parent of the current node is not null
                if(node->parent!=nullptr)
                {
                    //If the parent of the current node is larger
                    if(node->parent->val > node->val)
                    {
                        result=node->parent;
                    }
                    //Else, the parent of the current node is smaller
                    else
                    {
                        Node* current=node->parent;
                    
                        //Iterate up the tree until we find a parent that is larger
                        while(current!=nullptr and current->val < node->val)
                        {
                            current=current->parent;
                        }

                        if(current!=nullptr)
                        {
                            result=current;
                        }
                    }
                }
            }
            //Else, the right child of the current node is not null
            else
            {
                //If the left child of the current node's right child is null
                if(node->right->left==nullptr)
                {
                    result=node->right;
                }
                //Else, there is a smaller value than the current node's right child in the left subtree of the current node's right child
                else
                {
                    Node* current=node->right->left;
                    
                    while(current!=nullptr)
                    {
                        result=current;
                        
                        current=current->left;
                    }
                }
            }
            
            return result;
        }
};