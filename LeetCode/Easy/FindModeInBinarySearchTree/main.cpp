#include "../TreeNode.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

/*
 * Approaches:
 *
 * 1) Breadth-first. We traverse the tree level-by-level and map each number to how many times it appears
 * in the tree, using a hashtable (unordered_map<int, int>). Then, we find the element with the max frequency, the mode,
 * and add it to our result vector. We then search in the hashtable for more than one mode and add any more modes
 * to our result vector.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary search tree]
 * Space complexity: O(n)
 *
 * 2) Similar logic to the first solution, we just take a depth-first approach instead.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary search tree]
 * Space complexity: O(n)
 */

vector<int> findMode(TreeNode* root)
{
    vector<int> result;

    if(root==nullptr)
    {
        return result;
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        result.emplace_back(root->val);

        return result;
    }

    queue<TreeNode*> Q;

    unordered_map<int, int> hashtable;

    Q.push(root);

    while(true)
    {
        int qSize=int(Q.size());

        if(qSize==0)
        {
            break;
        }

        for(int count=0;count<qSize;++count)
        {
            TreeNode* current=Q.front();

            Q.pop();

            hashtable[current->val]++;

            if(current->left!=nullptr)
            {
                Q.emplace(current->left);
            }

            if(current->right!=nullptr)
            {
                Q.emplace(current->right);
            }
        }
    }

    pair<int, int> modePair=*(max_element(hashtable.begin(), hashtable.end(), [] (const auto & p1, const auto & p2) {return p1.second < p2.second;}));

    int frequency=modePair.second;

    for_each(hashtable.begin(), hashtable.end(), [&result, frequency] (const auto & p) {if(p.second==frequency){result.emplace_back(p.first);}});

    return result;
}

vector<int> findMode(TreeNode* root)
{
    vector<int> result;

    if(root==nullptr)
    {
        return result;
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        result.emplace_back(root->val);

        return result;
    }

    stack<TreeNode*> stk;

    unordered_map<int, int> hashtable;

    stk.push(root);

    while(!stk.empty())
    {
        TreeNode* current=stk.top();

        stk.pop();

        hashtable[current->val]++;

        if(current->left!=nullptr)
        {
            stk.push(current->left);
        }

        if(current->right!=nullptr)
        {
            stk.push(current->right);
        }
    }

    pair<int, int> modePair=*(max_element(hashtable.begin(), hashtable.end(), [] (const auto & p1, const auto & p2) {return p1.second < p2.second;}));

    int frequency=modePair.second;

    for_each(hashtable.begin(), hashtable.end(), [&result, frequency] (const auto & p) {if(p.second==frequency){result.emplace_back(p.first);}});

    return result;
}