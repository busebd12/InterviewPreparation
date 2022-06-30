#include <vector>
using namespace std;

class Solution
{
    public:
        void backtracking(vector<bool> & visited, int n, int & result, int index)
        {
            if(index > n)
            {
                result+=1;
                
                return;
            }
            
            for(int i=1;i<=n;i++)
            {
                bool condition1=i % index;
                
                bool condition2=index % i;
                
                if(visited[i]==false && (condition1==0 || condition2==0))
                {
                    visited[i]=true;
                    
                    backtracking(visited, n, result, index + 1);
                    
                    visited[i]=false;
                }
            }
        }
    
        int countArrangement(int n)
        {
            int result=0;
            
            vector<bool> visited(n + 1, false);
            
            int index=1;
            
            backtracking(visited, n, result, index);
            
            return result;
        }
};