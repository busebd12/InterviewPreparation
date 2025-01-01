#include <unordered_set>
using namespace std;

class Solution
{
    private:
        unordered_set<int> differences;
    
    public:
        bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target)
        {
            inOrderTraversal(root1, target);

            return checkForDifference(root2);
        }

        void inOrderTraversal(TreeNode* root, int target)
        {
            deque<TreeNode*> stack;

            TreeNode* current=root;

            while(!stack.empty() or current!=nullptr)
            {
                while(current!=nullptr)
                {
                    stack.emplace_back(current);

                    current=current->left;
                }

                current=stack.back();

                stack.pop_back();

                differences.emplace(target - current->val);

                current=current->right;
            }
        }

        bool checkForDifference(TreeNode* root)
        {
            deque<TreeNode*> stack;

            TreeNode* current=root;

            while(!stack.empty() or current!=nullptr)
            {
                while(current!=nullptr)
                {
                    stack.emplace_back(current);

                    current=current->left;
                }

                current=stack.back();

                stack.pop_back();

                if(differences.find(current->val)!=differences.end())
                {
                    return true;
                }

                current=current->right;
            }

            return false;
        }
};