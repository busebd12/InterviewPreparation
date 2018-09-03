#include <iostream>
#include <vector>
using namespace std;

 struct TreeNode
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class BSTIterator
{
    private:
        vector<int> tree;
        int position;
        size_t treeSize;

    public:
        BSTIterator(TreeNode *root)
        {
            populateVector(root);

            treeSize=tree.size();

            position=0;
        }

        void populateVector(TreeNode* root)
        {
            if(root==nullptr)
            {
                return;
            }

            populateVector(root->left);

            tree.emplace_back(root->val);

            populateVector(root->right);
        }

        bool hasNext()
        {
            return position < treeSize;
        }

        int next()
        {
            return tree[position++];
        }
};