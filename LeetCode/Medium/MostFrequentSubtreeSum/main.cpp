#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

 struct TreeNode
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

pair<int, bool> helper(TreeNode* root, unordered_map<int, int> & sumFrequencies)
{
    if(root==nullptr)
    {
        return make_pair(0, true);
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        return make_pair(root->val, false);
    }

    int subtreeSum=root->val;

    pair<int, bool> leftSubtreeSum=helper(root->left, sumFrequencies);

    if(!leftSubtreeSum.second)
    {
        sumFrequencies[leftSubtreeSum.first]++;
    }

    pair<int, bool> rightSubtreeSum=helper(root->right, sumFrequencies);

    if(!rightSubtreeSum.second)
    {
        sumFrequencies[rightSubtreeSum.first]++;
    }

    subtreeSum+=leftSubtreeSum.first;

    subtreeSum+=rightSubtreeSum.first;

    sumFrequencies[subtreeSum]++;

    return make_pair(subtreeSum, true);
}


vector<int> findFrequentTreeSum(TreeNode* root)
{
    vector<int> result;

    if(root==nullptr)
    {
        return result;
    }

    if(root->right==nullptr && root->left==nullptr)
    {
        result.emplace_back(root->val);

        return result;
    }

    unordered_map<int, int> sumFrequencies;

    helper(root, sumFrequencies);

    int maxFrequency=0;

    for(auto & element : sumFrequencies)
    {
        if(element.second > maxFrequency)
        {
            maxFrequency=element.second;
        }
    }

    for(auto & element : sumFrequencies)
    {
        if(element.second==maxFrequency)
        {
            result.emplace_back(element.first);
        }
    }

    return result;
}