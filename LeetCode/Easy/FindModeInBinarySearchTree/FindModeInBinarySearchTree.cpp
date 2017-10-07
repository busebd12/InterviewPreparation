#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void inOrderTraversal(TreeNode* root, unordered_map<int, int> & table)
{
    if(root==nullptr)
    {
        return;
    }
    
    inOrderTraversal(root->left, table);

    table[root->val]++;

    inOrderTraversal(root->right, table);
}

vector<int> findMode(TreeNode* root)
{
    vector<int> result;
    
    if(root==nullptr)
    {
        return result;
    }
    
    unordered_map<int, int> table;
    
    using pairType=decltype(table)::value_type;
    
    inOrderTraversal(root, table);
    
    auto maxValue=max_element(begin(table), end(table), [] (const pairType & e1, const pairType & e2) {return e1.second < e2.second;});
    
    result.emplace_back(maxValue->first);
    
    for(const auto & element : table)
    {
        if(element.second==maxValue->second)
        {
            if(element.first!=maxValue->first)
            {
                result.emplace_back(element.first);
            }   
        }
    }
    
    return result;
}