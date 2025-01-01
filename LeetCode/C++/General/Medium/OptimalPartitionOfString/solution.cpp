#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
    public:
        int partitionString(string s)
        {
            int result=0;

            int n=s.size();

            unordered_set<char> hashset;

            for(int i=0;i<n;)
            {
                int j=i;

                while(j < n and hashset.find(s[j])==hashset.end())
                {
                    hashset.insert(s[j]);

                    j+=1;
                }

                result+=1;

                hashset.clear();

                i=j;
            }

            return result;
        }
};

class Solution
{
    public:
        int partitionString(string s)
        {
            int result=0;

            int n=s.size();

            vector<int> hashset(26, 0);

            for(int i=0;i<n;)
            {
                int j=i;

                while(j < n and hashset[s[j] - 'a']==0)
                {
                    hashset[s[j] - 'a']+=1;

                    j+=1;
                }

                result+=1;

                hashset.clear();

                hashset.resize(26, 0);

                i=j;
            }

            return result;
        }
};