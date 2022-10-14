#include <string>
#include <vector>
using namespace std;

/*
Time complexity: O(n)
Space complexity: O(26) --> O(1)
*/

class Solution
{
    public:
        long long numberOfSubstrings(string s)
        {
            long long result=0;
            
            int n=s.size();

            vector<int> hashmap(26, 0);

            for(int i=0;i<n;i++)
            {
                int index=s[i] - 'a';

                hashmap[index]+=1;

                result+=hashmap[index];
            }
            
            return result;
        }
};