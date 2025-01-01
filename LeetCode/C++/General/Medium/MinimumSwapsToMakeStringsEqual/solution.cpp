#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
    public:
        int minimumSwap(string s1, string s2)
        {
            int result=0;

            int n=s1.size();

            int m=s2.size();

            unordered_set<string> seen;

            for(int i=0;i<n;i++)
            {
                if(s1[i]!=s2[i])
                {
                    string pattern="";

                    pattern.push_back(s1[i]);

                    pattern.push_back(s2[i]);

                    auto itr=seen.find(pattern);

                    if(itr!=seen.end())
                    {
                        result+=1;

                        seen.erase(itr);
                    }
                    else
                    {
                        seen.insert(pattern);
                    }
                }
            }

            if(seen.size()==1)
            {
                result=-1;
            }
            else if(seen.size()==2)
            {
                result+=2;
            }

            return result;
        }
};