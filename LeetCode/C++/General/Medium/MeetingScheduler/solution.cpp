#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O((n log n) + (m log m) + n + m) [where n is the length of slots1 and m is the length of slots2]
Space complexity: O(1)
*/

class Solution
{
    public:
        vector<int> minAvailableDuration(vector<vector<int>> & slots1, vector<vector<int>> & slots2, int duration)
        {
            vector<int> result;
            
            int n=slots1.size();
            
            int m=slots2.size();
            
            //Custom sort comparator
            auto compareLikeThis=[] (vector<int> & lhs, vector<int> & rhs)
            {
                if(lhs[0]!=rhs[0])
                {
                    return lhs[0] < rhs[0];
                }
                else
                {
                    return lhs[1] < rhs[1];
                }
            };
            
            //Sort slots1 and slots2 using the custom comparator
            sort(begin(slots1), end(slots1), compareLikeThis);
            
            sort(begin(slots2), end(slots2), compareLikeThis);
            
            int i=0;
            
            int j=0;
            
            bool done=false;
            
            while(true)
            {   
                //Caclulate the intersection of the two intervals, slots1[i] and slots2[j]
                int intersectionStart=max(slots1[i][0], slots2[j][0]);
                    
                int intersectionEnd=min(slots1[i][1], slots2[j][1]);

                //Get the length of the intersection
                int difference=intersectionEnd - intersectionStart;

                //If the intersection is at least as long as the duration, we have our answer
                if(difference >= duration)
                {
                    done=true;

                    result.push_back(intersectionStart);

                    result.emplace_back(intersectionStart + duration);
                }
                
                bool incrementI=false;
                
                bool incrementJ=false;
                
                //If the interval slots1[i] comes before the interval slots2[j]
                if(slots1[i][0] <= slots2[j][0])
                {   
                    //If i has not reached the end of slots1
                    if(i < n - 1)
                    {
                        incrementI=true;
                    }
                    //Else, i has reached the end of slots1
                    else
                    {
                        //If j hasn't reached the end of slots2, we can still increment j
                        if(j < m - 1)
                        {
                            incrementJ=true;
                        }
                    }
                    
                    //If the start of slots1 interval is equal to the start of slots2 interval
                    if(slots1[i][0]==slots2[j][0])
                    {
                        //If j hasn't reached the end of slots2, increment j
                        if(j < m - 1)
                        {
                            incrementJ=true;
                        }
                    }
                }
                //Else if the slots2[j] interval comes before the slots1[i] interval
                else if(slots1[i][0] > slots2[j][0])
                {   
                    //If j hasn't reached the end of slots2, increment j
                    if(j < m - 1)
                    {
                        incrementJ=true;
                    }
                    //Else, j has reached the end of slots2
                    else
                    {
                        //If i hasn't reached the end of slots1, let's increment it
                        if(i < n - 1)
                        {
                            incrementI=true;
                        }
                    }
                }
                
                if(done==true)
                {
                    break;
                }
                
                if(incrementI==false && incrementJ==false)
                {
                    break;
                }
                
                if(incrementI==true)
                {
                    i+=1;
                }
                
                if(incrementJ==true)
                {
                    j+=1;
                }
            }
            
            return result;
        }
};