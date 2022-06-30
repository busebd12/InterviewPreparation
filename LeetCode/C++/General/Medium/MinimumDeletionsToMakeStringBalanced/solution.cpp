#include <set>
#include <string>
using namespace std;

class Solution
{
    public:
        int minimumDeletions(string s)
        {
            int result=0;
            
            int n=s.size();
    
            set<int> aIndices;

            for(int index=0;index<n;index++)
            {
                if(s[index]=='a')
                {
                    aIndices.insert(index);
                }
            }

            for(int index=0;index<n;index++)
            {
                if(s[index]=='b')
                {
                    auto itr=aIndices.lower_bound(index);

                    if(itr!=end(aIndices))
                    {
                        result+=1;

                        aIndices.erase(itr);
                    }
                }
            }
            
            return result;
        }
};

class Solution
{
    public:
        int minimumDeletions(string s)
        {
            int result=0;
            
            int n=s.size();
    
            int bCount=0;

            for(int index=0;index<n;index++)
            {
                if(s[index]=='b')
                {
                    bCount+=1;
                }
                else if(bCount > 0)
                {
                    result+=1;
                    
                    bCount-=1;
                }
            }
            
            return result;
        }
};