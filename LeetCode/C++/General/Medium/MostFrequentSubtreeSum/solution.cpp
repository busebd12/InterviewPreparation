#include <algorithm>
#include <limits>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution 1: post-order traversal + hashmaps (unordered_map<int, int> and map<int, vector<int>>)

Time complexity: O(n + f * log(s)) [where f is the total number of unique subtree sum frequencies and s is the total number of subtree sums]
Space complexity: O(f)
*/

class Solution
{
    public:
        const int INF=numeric_limits<int>::max();
        
        vector<int> findFrequentTreeSum(TreeNode* root)
        {
            vector<int> result;

            unordered_map<int, int> frequencies;

            helper(root, frequencies);

            map<int, vector<int>> hashmap;
            
            for(auto & [subtreeSum, frequency] : frequencies)
            {
                if(hashmap.find(frequency)==hashmap.end())
                {
                    hashmap.emplace(frequency, vector<int>());
                }

                hashmap[frequency].push_back(subtreeSum);
            }

            auto highestFrequencyItr=hashmap.rbegin();

            for(auto subtreeSum : highestFrequencyItr->second)
            {
                result.push_back(subtreeSum);
            }

            return result;
        }

        int helper(TreeNode* root, unordered_map<int, int> & frequencies)
        {
            if(root==nullptr)
            {
                return INF;
            }

            int leftSubtreeSum=helper(root->left, frequencies);

            int rightSubtreeSum=helper(root->right, frequencies);

            int subtreeSum=root->val;

            if(leftSubtreeSum!=INF)
            {
                subtreeSum+=leftSubtreeSum;
            }

            if(rightSubtreeSum!=INF)
            {
                subtreeSum+=rightSubtreeSum;
            }

            if(frequencies.find(subtreeSum)==frequencies.end())
            {
                frequencies.emplace(subtreeSum, 0);
            }

            frequencies[subtreeSum]+=1;

            return subtreeSum;
        }
};

/*
Solution 2: post-order traversal + hashmap (unordered_map<int, int>)

Time complexity: O(n + f) [where f is the total number of unique subtree sum frequencies]
Space complexity: O(f)
*/



class Solution
{
    public:
        const int INF=numeric_limits<int>::max();
        
        vector<int> findFrequentTreeSum(TreeNode* root)
        {
            vector<int> result;

            unordered_map<int, int> frequencies;

            helper(root, frequencies);
            
            for(auto & [subtreeSum, frequency] : frequencies)
            {
                if(hashmap.find(frequency)==hashmap.end())
                {
                    hashmap.emplace(frequency, vector<int>());
                }

                hashmap[frequency].push_back(subtreeSum);
            }

            int maxFrequency=0;

            for(auto & [subtreeSum, frequency] : frequencies)
            {
                maxFrequency=max(maxFrequency, frequency);
            }

            for(auto & [subtreeSum, frequency] : frequencies)
            {
                if(frequency==maxFrequency)
                {
                    result.push_back(subtreeSum);
                }
            }

            return result;
        }

        int helper(TreeNode* root, unordered_map<int, int> & frequencies)
        {
            if(root==nullptr)
            {
                return INF;
            }

            int leftSubtreeSum=helper(root->left, frequencies);

            int rightSubtreeSum=helper(root->right, frequencies);

            int subtreeSum=root->val;

            if(leftSubtreeSum!=INF)
            {
                subtreeSum+=leftSubtreeSum;
            }

            if(rightSubtreeSum!=INF)
            {
                subtreeSum+=rightSubtreeSum;
            }

            if(frequencies.find(subtreeSum)==frequencies.end())
            {
                frequencies.emplace(subtreeSum, 0);
            }

            frequencies[subtreeSum]+=1;

            return subtreeSum;
        }
};