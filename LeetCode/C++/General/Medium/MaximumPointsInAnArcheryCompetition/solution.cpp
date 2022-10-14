#include <limits>
#include <vector>
using namespace std;

class Solution
{
    private:
        int maxScore=numeric_limits<int>::min();
    
    public:
        vector<int> maximumBobPoints(int numArrows, vector<int> & aliceArrows)
        {   
            vector<int> result;
            
            int n=aliceArrows.size();
            
            result.resize(n, 0);
            
            vector<int> bob(n, 0);
            
            int index=0;
            
            int score=0;
            
            dfs(aliceArrows, result, bob, n, numArrows, score, index);
            
            return result;
        }
    
        void dfs(vector<int> & aliceArrows, vector<int> & result, vector<int> & bob, int n, int numArrows, int score, int index)
        {
            if(index==n)
            {
                if(score > maxScore)
                {
                    maxScore=score;
                    
                    result=bob;
                    
                    result.back()+=numArrows;
                }
                
                return;
            }
            
            dfs(aliceArrows, result, bob, n, numArrows, score, index + 1);
            
            if(numArrows > aliceArrows[index])
            {
                bob[index]=aliceArrows[index] + 1;
                
                score+=index;
                
                numArrows-=(aliceArrows[index] + 1);
                
                dfs(aliceArrows, result, bob, n, numArrows, score, index + 1);
                
                numArrows+=(aliceArrows[index] + 1);
                
                score-=index;
                
                bob[index]=0;
            }
        }
};