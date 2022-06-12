#include <algorithm>
#include <set>
#include <queue>
#include <vector>
using namespace std;

/*
Solution 1: sorting via a multiset.

Time complexity: O(n log n)
Space complexity: O(n)
*/

class Solution
{
    public:
        int fOfX(int number, int a, int b, int c)
        {
            int transformed=0;
            
            int aTerm=a * (number * number);
            
            int bTerm=b * number;
            
            transformed=aTerm + bTerm + c;
            
            return transformed;
        }
    
        vector<int> sortTransformedArray(vector<int> & nums, int a, int b, int c)
        {
            vector<int> result;
            
            multiset<int> ordered;
            
            for(int number : nums)
            {
                int transformed=fOfX(number, a, b, c);
                
                ordered.insert(transformed);
            }
            
            while(!ordered.empty())
            {
                result.emplace_back(*(begin(ordered)));
                
                ordered.erase(begin(ordered));
            }
            
            return result;
        }
};

/*
Solution 2: sorting via a minimum heap.

Time complexity: O(n log n)
Space complexity: O(n)
*/
class Solution
{
    public:
        int fOfX(int number, int a, int b, int c)
        {
            int transformed=0;
            
            int aTerm=a * (number * number);
            
            int bTerm=b * number;
            
            transformed=aTerm + bTerm + c;
            
            return transformed;
        }
    
        vector<int> sortTransformedArray(vector<int> & nums, int a, int b, int c)
        {
            vector<int> result;
            
            priority_queue<int, vector<int>, greater<int>> minHeap;
            
            for(int number : nums)
            {
                int transformed=fOfX(number, a, b, c);
                
                minHeap.emplace(transformed);
            }
            
            while(!minHeap.empty())
            {
                result.emplace_back(minHeap.top());
                
                minHeap.pop();
            }
            
            return result;
        }
};

/*
Solution 3: sorting via a std::lower_bound (binary search) and a vector.

Time complexity: O(n log n)
Space complexity: O(n)
*/
class Solution
{
    public:
        int fOfX(int number, int a, int b, int c)
        {
            int transformed=0;
            
            int aTerm=a * (number * number);
            
            int bTerm=b * number;
            
            transformed=aTerm + bTerm + c;
            
            return transformed;
        }
    
        vector<int> sortTransformedArray(vector<int> & nums, int a, int b, int c)
        {
            vector<int> result;
            
            for(int number : nums)
            {
                int transformed=fOfX(number, a, b, c);
                
                auto itr=lower_bound(begin(result), end(result), transformed);
                
                result.insert(itr, transformed);
            }
            
            return result;
        }
};