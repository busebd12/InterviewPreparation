#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

/*
Solution 1: brute force.

Time complexity: O(n^2)
Space complexity: O(1)
*/

class Solution
{
    public:
        int hIndex(vector<int> & citations)
        {
            int result=0;
            
            size_t n=citations.size();
            
            for(size_t h=1;h<=n;h++)
            {
                int papersWithAtLeastHCitations=count_if(begin(citations), end(citations), [&h] (int citation) {return citation >= h;});
                
                if(papersWithAtLeastHCitations > h)
                {
                    papersWithAtLeastHCitations=h;
                }
                
                int remaining=n - papersWithAtLeastHCitations;
                
                int papersWithNoMoreThanHCitations=count_if(begin(citations), end(citations), [&h] (int citation) {return citation <= h;});
                
                if(papersWithNoMoreThanHCitations >= remaining && papersWithAtLeastHCitations==h)
                {
                    result=max(result, int(h));
                }
            }
            
            return result;
        }
};

/*
Solution 2: sorting via maximum heap.

Time complexity: O(n log n)
Space complexity: O(n)
*/

class Solution
{
    public:
        int hIndex(vector<int> & citations)
        {
            int result=1;
            
            priority_queue<int, vector<int>, less<int>> maxHeap(begin(citations), end(citations));
            
            while(!maxHeap.empty() && result <= maxHeap.top())
            {   
                maxHeap.pop();
                
                result+=1;
            }
            
            return result - 1;
        }
};

/*
Solution 3: bucket/counting sort

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        int hIndex(vector<int> & citations)
        {
            int result=0;
            
            size_t n=citations.size();
            
            vector<int> buckets(n + 1);
            
            for(int citation : citations)
            {
                if(citation >= n)
                {
                    buckets[n]+=1;
                }
                else
                {
                    buckets[citation]+=1;
                }
            }
            
            int totalPapers=0;
            
            for(int index=n;index>=0;index--)
            {
                totalPapers+=buckets[index];
                
                if(totalPapers >= index)
                {
                    result=index;
                    
                    break;
                }
            }
            
            return result;
        }
};