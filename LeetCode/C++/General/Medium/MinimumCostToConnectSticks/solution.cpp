#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution
{
    public:
        int connectSticks(vector<int> & sticks)
        {
            int result=0;
            
            if(sticks.size() < 2)
            {
                return result;
            }
            
            multiset<int> sorted;
            
            for(int stick : sticks)
            {
                sorted.insert(stick);
            }
            
            while(sorted.size() > 1)
            {
                int firstLength=*(begin(sorted));
                
                sorted.erase(begin(sorted));
                
                int secondLength=*(begin(sorted));
                
                sorted.erase(begin(sorted));
                
                int combinedLength=firstLength + secondLength;
                
                sorted.insert(combinedLength);
                
                result+=combinedLength;
            }
            
            return result;
        }
};

class Solution
{
    public:
        int connectSticks(vector<int> & sticks)
        {
            int result=0;
            
            if(sticks.size() < 2)
            {
                return result;
            }
            
            priority_queue<int, vector<int>, greater<int>> minHeap;
            
            for(int stick : sticks)
            {
                minHeap.push(stick);
            }
            
            while(minHeap.size() > 1)
            {
                int firstLength=minHeap.top();
                
                minHeap.pop();
                
                int secondLength=minHeap.top();
                
                minHeap.pop();
                
                int combinedLength=firstLength + secondLength;
                
                minHeap.push(combinedLength);
                
                result+=combinedLength;
            }
            
            return result;
        }
};