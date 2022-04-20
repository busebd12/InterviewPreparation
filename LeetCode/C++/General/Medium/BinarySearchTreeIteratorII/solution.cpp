#include <deque>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the number of nodes in the binary search tree]
Space complexity: O(n)
*/

class BSTIterator
{
    private:
        vector<int> values;
    
        deque<TreeNode*> stack;
    
        int index;
    
    public:
        BSTIterator(TreeNode* root)
        {
            inOrderTraversal(root);
            
            index=-1;
        }
    
        void inOrderTraversal(TreeNode* root)
        {
            TreeNode* current=root;
            
            while(!stack.empty() || current!=nullptr)
            {
                if(current!=nullptr)
                {
                    stack.emplace_back(current);
                    
                    current=current->left;
                }
                else
                {
                    current=stack.back();
                    
                    stack.pop_back();
                    
                    values.emplace_back(current->val);
                    
                    current=current->right;
                }
            }
        }

        bool hasNext()
        {   
            return index < static_cast<int>(values.size()-1);
        }

        int next()
        {
            int nextValue=values[index + 1];
            
            index++;
            
            return nextValue;
        }

        bool hasPrev()
        {
            return index > 0;
        }

        int prev()
        {
            index-=1;
            
            return values[index];
        }
};