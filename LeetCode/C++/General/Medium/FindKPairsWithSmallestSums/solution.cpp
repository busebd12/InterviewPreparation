#include <queue>
#include <set>
#include <utility>
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

class Solution
{
    public:
        vector<vector<int>> kSmallestPairs(vector<int> & nums1, vector<int> & nums2, int k)
        {
            vector<vector<int>> result;

            int n=nums1.size();

            int m=nums2.size();

            auto compareLikeThis=[] (const tuple<int, int, int> & lhs, const tuple<int, int, int> & rhs)
            {
                return get<2>(lhs) > get<2>(rhs);
            };

            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(compareLikeThis)> minHeap(compareLikeThis);

            minHeap.emplace(make_tuple(0, 0, nums1[0] + nums2[0]));

            set<pair<int, int>> visited;

            while(!minHeap.empty() and k > 0)
            {
                auto [nums1Index, nums2Index, sum] =minHeap.top();

                minHeap.pop();

                result.emplace_back(vector<int>{nums1[nums1Index], nums2[nums2Index]});

                if(nums1Index + 1 < n and visited.find({nums1Index + 1, nums2Index})==visited.end())
                {
                    visited.emplace(nums1Index + 1, nums2Index);

                    minHeap.emplace(make_tuple(nums1Index + 1, nums2Index, nums1[nums1Index + 1] + nums2[nums2Index]));
                }

                if(nums2Index + 1 < m and visited.find({nums1Index, nums2Index + 1})==visited.end())
                {
                    visited.emplace(nums1Index, nums2Index + 1);

                    minHeap.emplace(make_tuple(nums1Index, nums2Index + 1, nums1[nums1Index] + nums2[nums2Index + 1]));
                }

                k-=1;
            }

            return result;
        }
};