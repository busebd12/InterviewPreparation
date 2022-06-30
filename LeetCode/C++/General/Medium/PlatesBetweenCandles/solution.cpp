#include <string>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> platesBetweenCandles(string s, vector<vector<int>> & queries)
        {
            vector<int> result;
            
            int q=queries.size();
            
            result.resize(q);
            
            int n=s.size();
            
            const char CANDLE='|';
            
            const char PLATE='*';
            
            vector<int> leftCandleIndices(n, -1);
            
            int leftCandleIndex=-1;
            
            for(int i=0;i<n;i++)
            {
                if(s[i]==CANDLE)
                {
                    leftCandleIndex=i;
                }
                
                leftCandleIndices[i]=leftCandleIndex;
            }
            
            vector<int> rightCandleIndices(n, -1);
            
            int rightCandleIndex=-1;
            
            for(int i=n-1;i>=0;i--)
            {
                if(s[i]==CANDLE)
                {
                    rightCandleIndex=i;
                }
                
                rightCandleIndices[i]=rightCandleIndex;
            }
            
            vector<int> prefixSums(n, 0);
            
            prefixSums[0]=(s[0]=='*' ? 1 : 0);
            
            for(int i=1;i<n;i++)
            {
                if(s[i]==PLATE)
                {
                    prefixSums[i]=prefixSums[i - 1] + 1;
                }
                else
                {
                    prefixSums[i]=prefixSums[i - 1] + 0;
                }
            }
            
            vector<int> candleIndices;
            
            for(int i=0;i<n;i++)
            {
                if(s[i]==CANDLE)
                {
                    candleIndices.push_back(i);
                }
            }
            
            for(int index=0;index<q;index++)
            {
                int leftSubstringIndex=queries[index][0];
                
                int rightSubstringIndex=queries[index][1];
                
                leftCandleIndex=rightCandleIndices[leftSubstringIndex];
                
                rightCandleIndex=leftCandleIndices[rightSubstringIndex];
                
                int total=0;
                
                if(leftCandleIndex!=-1 && rightCandleIndex!=-1 && leftCandleIndex < rightCandleIndex)
                {
                    total=prefixSums[rightCandleIndex] - prefixSums[leftCandleIndex];
                }
                
                result[index]=total;
            }
            
            return result;
        }
};