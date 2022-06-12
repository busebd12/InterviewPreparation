#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n log n)
Space complexity: O(n)
*/

class Solution
{
    public:
        int maxEnvelopes(vector<vector<int>> & envelopes)
        {
            int result=0;
            
            size_t n=envelopes.size();
            
            //Custom comparator used when we sort the envelopes
            auto compareLikeThis=[] (vector<int> & lhs, vector<int> & rhs)
            {
                //If the width of two envelopes is not the same
                if(lhs[0]!=rhs[0])
                {
                    //The envelope with the smaller width comes before the envelope with the larger width
                    return lhs[0] < rhs[0];
                }
                //Else, the widths of the two envelopes are the same
                else
                {
                    //The envelope with the larger height comes before the envelope with the smaller height
                    return lhs[1] > rhs[1];
                }
            };
            
            //Sort the envelopes
            sort(begin(envelopes), end(envelopes), compareLikeThis);
            
            //List of increasing width values
            vector<int> widths;
            
            //Iterate through all the envelopes
            for(size_t i=0;i<n;i++)
            {
                //Width of the current envelope
                int width=envelopes[i][1];
                
                //Find the width in the vector that is greater than or equal to it
                auto itr=lower_bound(begin(widths), end(widths), width);
                
                //If no such width exists within the vector, then this width is the largest width we've seen so far
                //Add it to the end of the vector
                if(itr==end(widths))
                {
                    widths.push_back(width);
                }
                //Else, there is a width that is at least as large as the current one in the vecotr
                else
                {
                    //Get the index of the width from the vector
                    int index=itr - begin(widths);
                    
                    //Replace the width that's in the vector with the current one since the current one may help form a larger chain of envelopes
                    widths[index]=width;
                }
            }
            
            result=int(widths.size());
            
            return result;
        }
};