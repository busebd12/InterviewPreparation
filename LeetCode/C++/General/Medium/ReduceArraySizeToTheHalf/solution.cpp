#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
    public:
        int minSetSize(vector<int> & arr)
        {
            int result=0;
            
            int n=arr.size();
            
            unordered_map<int, int> frequencies;
            
            for(int number : arr)
            {
                if(frequencies.find(number)==end(frequencies))
                {
                    frequencies.emplace(number, 0);
                }
                
                frequencies[number]+=1;
            }
            
            auto compareLikeThis=[] (pair<int, int> & lhs, pair<int, int> & rhs)
            {
                return lhs.second < rhs.second;
            };
            
            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compareLikeThis)> maxHeap(compareLikeThis);
            
            for(auto & [number, frequency] : frequencies)
            {
                maxHeap.emplace(number, frequency);
            }
            
            int size=0;
            
            while(!maxHeap.empty() and size < n/2)
            {
                size+=maxHeap.top().second;
                
                maxHeap.pop();
                
                result+=1;
            }
            
            return result;
        }
};