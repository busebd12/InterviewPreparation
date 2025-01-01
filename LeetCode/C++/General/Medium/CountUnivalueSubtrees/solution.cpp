#include <utility>
using namespace std;

class Solution
{
    public:
        int countUnivalSubtrees(TreeNode* root)
        {
            return dfs(root).second;
        }

        pair<bool, int> dfs(TreeNode* root)
        {
            if(root==nullptr)
            {
                return make_pair(false, 0);
            }

            int isUnivalueSubtree=1;

            auto [isLeftSubtreeUnivalue, leftSubtreeCount]=dfs(root->left);

            auto [isRightSubtreeUnivalue, rightSubtreeCount]=dfs(root->right);

            if(root->left!=nullptr and root->right!=nullptr)
            {
                if((root->val!=root->left->val or root->val!=root->right->val) or (isLeftSubtreeUnivalue==false or isRightSubtreeUnivalue==false))
                {
                    isUnivalueSubtree=0;
                }
            }
            else if(root->left!=nullptr)
            {
                if(root->val!=root->left->val or isLeftSubtreeUnivalue==false)
                {
                    isUnivalueSubtree=0;
                }
            }
            else if(root->right!=nullptr)
            {
                if(root->val!=root->right->val or isRightSubtreeUnivalue==false)
                {
                    isUnivalueSubtree=0;
                }
            }

            return make_pair(isUnivalueSubtree, isUnivalueSubtree + leftSubtreeCount + rightSubtreeCount);
        }
};