#include <queue>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84551/simple-Java-O(KlogK)-solution-with-explanation
*/

class Solution
{
    public:
        vector<vector<int>> kSmallestPairs(vector<int> & nums1, vector<int> & nums2, int k)
        {
            vector<vector<int>> result;
            
            int n=nums1.size();
            
            int m=nums2.size();
            
            auto compareLikeThis=[] (vector<int> & lhs, vector<int> & rhs)
            {
                return lhs[0] + lhs[1] > rhs[0] + rhs[1];
            };
            
            priority_queue<vector<int>, vector<vector<int>>, decltype(compareLikeThis)> minHeap(compareLikeThis);
            
            for(int i=0;i<min(n, k);i++)
            {
                minHeap.emplace(vector<int>{nums1[i], nums2[0], 0});
            }
            
            while(!minHeap.empty() && k > 0)
            {
                vector<int> current=minHeap.top();
                
                minHeap.pop();
                
                result.emplace_back(vector<int>{current[0], current[1]});
                
                int next=current[2] + 1;
                
                if(next < m)
                {
                    minHeap.emplace(vector<int>{current[0], nums2[next], next});
                }
                
                k-=1;
            }
            
            return result;
        }
};