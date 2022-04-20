#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: see comments

Time complexity: O((n log n) + n)
Space complexity: O(1)
*/

class Solution
{
    public:
        int numRescueBoats(vector<int> & people, int limit)
        {
            int result=0;
            
            int n=people.size();
            
            //Sort people according to weight
            sort(begin(people), end(people));
            
            int i=0;
            
            int j=n-1;
            
            while(i <= j)
            {
                int heaviest=people[j];
                
                int lightest=people[i];
                
                //If the heaviest and the lightest person can fit into a boat
                if(heaviest + lightest <= limit)
                {
                    i++;
                    
                    j--;
                }
                //Else, just take the heaviest person
                else
                {
                    j--;
                }
                
                result++;
            }
            
            return result;
        }
};