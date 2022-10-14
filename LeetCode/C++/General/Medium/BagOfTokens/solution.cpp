#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O((n log n) + n)
Space complexity: O(1)
*/

class Solution
{
    public:
        int bagOfTokensScore(vector<int> & tokens, int power)
        {
            int result=0;
            
            if(tokens.empty())
            {
                return result;
            }
            
            int n=tokens.size();
            
            int low=0;
            
            int high=n - 1;
            
            //Sort the tokens in increasing order
            sort(begin(tokens), end(tokens));
            
            if(power < tokens[0])
            {
                return result;
            }
            
            int score=0;
            
            while(low < high)
            {
                //if we can play the token face up, then play the token with the smallest value
                if(power >= tokens[low])
                {
                    power-=tokens[low];
                    
                    score+=1;
                    
                    low+=1;
                }
                //If we want to play a token face down, play the token with the largest value
                else if(score > 0)
                {
                    power+=tokens[high];
                    
                    score-=1;
                    
                    high-=1;
                }
            }
            
            //After the while loop, low will equal high, so do one more check to see if we can increment our score one more time
            if(power >= tokens[low])
            {
                score+=1;
            }
            
            result=score;
            
            return result;
        }
};