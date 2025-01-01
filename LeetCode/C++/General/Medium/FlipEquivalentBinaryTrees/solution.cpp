#include <deque>
using namespace std;

/*
Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        bool flipEquiv(TreeNode* root1, TreeNode* root2)
        {
            return helper(root1, root2);
        }

        bool helper(TreeNode* root1, TreeNode* root2)
        {
            if(root1==nullptr and root2==nullptr)
            {
                return true;
            }

            if(root1==nullptr or root2==nullptr)
            {
                return false;
            }

            if(root1->val!=root2->val)
            {
                return false;
            }

            bool subproblemSolution=false;

            bool leftSubtreeNoFlip=helper(root1->left, root2->left);

            bool rightSubtreeNoFlip=helper(root1->right, root2->right);

            bool leftSubtreeWithFlip=helper(root1->left, root2->right);

            bool rightSubtreeWithFlip=helper(root1->right, root2->left);

            subproblemSolution=(leftSubtreeNoFlip and rightSubtreeNoFlip) or (leftSubtreeWithFlip and rightSubtreeWithFlip);

            return subproblemSolution;
        }
};

/*
Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        bool flipEquiv(TreeNode* root1, TreeNode* root2)
        {
            deque<TreeNode*> queue;

            queue.push_back(root1);

            queue.push_back(root2);

            while(!queue.empty())
            {
                TreeNode* node1=queue.front();

                queue.pop_front();

                TreeNode* node2=queue.front();

                queue.pop_front();

                if(node1==nullptr and node2==nullptr)
                {
                    continue;
                }

                if(nodesAreEqual(node1, node2)==false)
                {
                    return false;
                }

                if(nodesAreEqual(node1->left, node2->left)==true and nodesAreEqual(node1->right, node2->right)==true)
                {
                    queue.emplace_back(node1->left);

                    queue.emplace_back(node2->left);

                    queue.emplace_back(node1->right);

                    queue.emplace_back(node2->right);
                }
                else if(nodesAreEqual(node1->left, node2->right)==true and nodesAreEqual(node1->right, node2->left)==true)
                {
                    queue.emplace_back(node1->left);

                    queue.emplace_back(node2->right);

                    queue.emplace_back(node1->right);

                    queue.emplace_back(node2->left);
                }
                else
                {
                    return false;
                }
            }

            return true;
        }

        bool nodesAreEqual(TreeNode* root1, TreeNode* root2)
        {
            if(root1==nullptr and root2==nullptr)
            {
                return true;
            }
            else if(root1!=nullptr and root2!=nullptr and root1->val==root2->val)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

/*
Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        bool flipEquiv(TreeNode* root1, TreeNode* root2)
        {
            if(root1==nullptr and root2==nullptr)
            {
                return true;
            }

            if(root1==nullptr or root2==nullptr)
            {
                return false;
            }

            unordered_map<int, int> tree1Map;

            unordered_map<int, int> tree2Map;

            tree1Map.emplace(root1->val, -1);

            tree2Map.emplace(root2->val, -1);

            populateMap(root1, tree1Map);

            populateMap(root2, tree2Map);

            if(tree1Map.size()!=tree2Map.size())
            {
                return false;
            }

            for(auto & [nodeValue, parent] : tree1Map)
            {
                if(tree2Map.find(nodeValue)!=tree2Map.end() and tree2Map[nodeValue]==parent)
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }

            return true;
        }

        void populateMap(TreeNode* root, unordered_map<int, int> & map)
        {
            deque<TreeNode*> queue;

            queue.push_back(root);

            while(!queue.empty())
            {
                TreeNode* node=queue.front();

                queue.pop_front();

                if(node->left!=nullptr)
                {
                    map.emplace(node->left->val, node->val);

                    queue.emplace_back(node->left);
                }

                if(node->right!=nullptr)
                {
                    map.emplace(node->right->val, node->val);

                    queue.emplace_back(node->right);
                }
            }
        }
};