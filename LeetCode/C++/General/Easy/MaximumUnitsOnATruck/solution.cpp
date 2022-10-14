#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

/*
Solution 1: sorting + maximum heap.

Time complexity: O(n log n) [where n is the length of boxTypes]
Space complexity: O(n)
*/

class Solution
{
    public:
        int maximumUnits(vector<vector<int>> & boxTypes, int truckSize)
        {
            int result=0;
            
            auto compareLikeThis=[] (vector<int> & lhs, vector<int> & rhs)
            {
                return lhs[1] < rhs[1];
            };
            
            priority_queue<vector<int>, vector<vector<int>>, decltype(compareLikeThis)> maxHeap(compareLikeThis);
            
            for(vector<int> & boxType : boxTypes)
            {   
                maxHeap.emplace(boxType);
            }
            
            int capacity=truckSize;
            
            while(capacity > 0 and !maxHeap.empty())
            {   
                vector<int> boxType=maxHeap.top();
                
                maxHeap.pop();
                
                int numberOfBoxes=boxType[0];
                
                int numberOfUnitsPerBox=boxType[1];
                
                int count=min(capacity, numberOfBoxes);
                
                result+=(count * numberOfUnitsPerBox);
                
                numberOfBoxes-=count;
                
                capacity-=count;
                
                if(numberOfBoxes > 0)
                {
                    maxHeap.emplace(vector<int>{numberOfBoxes, numberOfUnitsPerBox});
                }
            }
            
            return result;
        }
};

/*
Solution 2: bucket sort based on the number of units per box.

Time complexity: O(n) [where n is the length of boxTypes]
Space complexity: O(1001) --> O(1)
*/

class Solution
{
    public:
        int maximumUnits(vector<vector<int>> & boxTypes, int truckSize)
        {
            int result=0;
            
            vector<int> buckets(1001, 0);
            
            for(vector<int> & boxType : boxTypes)
            {
                int numberOfBoxes=boxType[0];
                
                int numberOfUnitsPerBox=boxType[1];
                
                buckets[numberOfUnitsPerBox]+=numberOfBoxes;
            }
            
            int capacity=truckSize;
            
            for(int units=1000;units>=0;units--)
            {
                int numberOfBoxes=buckets[units];
                
                if(numberOfBoxes > 0)
                {   
                    int count=min(capacity, numberOfBoxes);
                    
                    result+=(count * units);
                    
                    capacity-=count;
                }
            }
            
            return result;
        }
};