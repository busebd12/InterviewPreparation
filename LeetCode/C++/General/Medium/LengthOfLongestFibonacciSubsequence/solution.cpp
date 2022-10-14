#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Time complexity: O(n^2)
Space complexity: O(n)
*/

class Solution
{
    public:
        int lenLongestFibSubseq(vector<int> & arr)
        {
            int result=0;
            
            int n=arr.size();
            
            unordered_set<int> numbers(begin(arr), end(arr));
            
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    int length=2;
                    
                    int first=arr[i];
                    
                    int second=arr[j];
                    
                    int next=first + second;
                    
                    while(numbers.find(next)!=end(numbers))
                    {
                        length+=1;
                        
                        first=second;
                        
                        second=next;
                        
                        next=first + second;
                    }
                    
                    result=max(result, length);
                }
            }
            
            return (result==2) ? 0 : result;
        }
};