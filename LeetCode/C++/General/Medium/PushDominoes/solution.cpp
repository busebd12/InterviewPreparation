#include <string>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/push-dominoes/discuss/1965633/javaoror-easy-to-understandoror-left-and-right-traversal

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        string pushDominoes(string dominoes)
        {
            string result="";
            
            int n=dominoes.size();
            
            vector<int> firstLeftDominoeThatFalls(n, -1);
            
            int leftIndex=-1;
            
            for(int i=n-1;i>=0;i--)
            {
                char c=dominoes[i];
                
                if(c=='R')
                {
                    leftIndex=-1;
                }
                
                if(c=='L')
                {
                    leftIndex=i;
                }
                
                firstLeftDominoeThatFalls[i]=leftIndex;
            }
            
            int rightIndex=-1;
            
            vector<int> firstRightDominoeThatFalls(n, -1);
            
            for(int i=0;i<n;i++)
            {
                char c=dominoes[i];
                
                if(c=='L')
                {
                    rightIndex=-1;
                }
                
                if(c=='R')
                {
                    rightIndex=i;
                }
                
                firstRightDominoeThatFalls[i]=rightIndex;
            }
            
            for(int i=0;i<n;i++)
            {
                if(dominoes[i]=='.')
                {
                    int closestLeftDominoe=firstLeftDominoeThatFalls[i];
                
                    int closestRightDominoe=firstRightDominoeThatFalls[i];

                    int distanceToClosestLeftDominoe=numeric_limits<int>::max();

                    int distanceToClosestRightDominoe=numeric_limits<int>::max();

                    if(closestLeftDominoe!=-1)
                    {
                        distanceToClosestLeftDominoe=abs(closestLeftDominoe - i);
                    }

                    if(closestRightDominoe!=-1)
                    {
                        distanceToClosestRightDominoe=abs(closestRightDominoe - i);
                    }

                    if(distanceToClosestLeftDominoe==distanceToClosestRightDominoe)
                    {
                        result.push_back('.');
                    }
                    else if(distanceToClosestLeftDominoe < distanceToClosestRightDominoe)
                    {
                        result.push_back('L');
                    }
                    else if(distanceToClosestRightDominoe < distanceToClosestLeftDominoe)
                    {
                        result.push_back('R');
                    }
                }
                else
                {
                    result.push_back(dominoes[i]);
                }
            }
            
            return result;
        }
};