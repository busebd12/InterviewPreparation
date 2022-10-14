#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> minOperations(string boxes)
        {
            vector<int> result;
            
            int n=boxes.size();
            
            result.resize(n, 0);
            
            vector<int> oneIndices;
            
            for(int i=0;i<n;i++)
            {
                if(boxes[i]=='1')
                {
                    oneIndices.push_back(i);
                }
            }
            
            for(int i=0;i<n;i++)
            {
                int totalMoves=0;
                
                for(int oneIndex : oneIndices)
                {
                    int moves=abs(oneIndex - i);
                    
                    totalMoves+=moves;
                }
                
                result[i]=totalMoves;
            }
            
            return result;
        }
};