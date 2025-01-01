#include <algorithm>
#include <deque>
using namespace std;

/*
Time complexity: O(n) [where n is number of nodes in the tree]
Space complexity: O(n + h) [where h is the height of the binary tree]
*/

class Solution
{
    public:
        bool btreeGameWinningMove(TreeNode* root, int n, int x)
        {
            int nodesNeededToWin=(n / 2) + 1;

            int blueNodes=0;

            TreeNode* redNode=findNode(root, x);

            int nodesInRedLeftSubtree=0;

            preOrderTraversal(redNode->left, nodesInRedLeftSubtree);

            int nodesInRedRightSubtree=0;
            
            preOrderTraversal(redNode->right, nodesInRedRightSubtree);

            blueNodes=max(nodesInRedLeftSubtree, nodesInRedRightSubtree);

            int blueNodesIfPickParent=(n - (nodesInRedLeftSubtree + nodesInRedRightSubtree + 1));

            blueNodes=max(blueNodes, blueNodesIfPickParent);

            return blueNodes >= nodesNeededToWin;
        }

        TreeNode* findNode(TreeNode* root, int x)
        {
            TreeNode* red=nullptr;
            
            deque<TreeNode*> queue;

            queue.push_back(root);

            while(!queue.empty())
            {
                TreeNode* node=queue.front();

                queue.pop_front();

                if(node->val==x)
                {
                    red=node;
                }

                if(node->left!=nullptr)
                {
                    queue.emplace_back(node->left);
                }

                if(node->right!=nullptr)
                {
                    queue.emplace_back(node->right);
                }
            }

            return red;
        }

        void preOrderTraversal(TreeNode* root, int & nodes)
        {
            if(root==nullptr)
            {
                return;
            }

            nodes+=1;

            preOrderTraversal(root->left, nodes);

            preOrderTraversal(root->right, nodes);
        }
};