#include <string>
#include <unordered_map>
#include <vector>
using namespace std;


/*
Solution 1: brute-force.

Time complexity: O(n^2 * t) [where n is the length of nums and t is the length of target]
Space complexity: O(n^2)
*/

class Solution
{
    public:
        int numOfPairs(vector<string> & nums, string target)
        {
            int result=0;

            int n=nums.size();

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i!=j)
                    {
                        string concatenation=nums[i] + nums[j];

                        if(concatenation==target)
                        {
                            result+=1;
                        }
                    }
                }
            }

            return result;
        }
};

/*
Solution 2: using hashmap.

Time complexity: O(n + m^2) [where n is the length of nums and m is the length of target]
Space complexity: O(n)
*/

class Solution
{
    public:
        int numOfPairs(vector<string> & nums, string target)
        {
            int result=0;

            int n=nums.size();

            int m=target.size();

            unordered_map<string, int> hashtable;

            for(string & number : nums)
            {
                if(hashtable.find(number)==hashtable.end())
                {
                    hashtable.emplace(number, 0);
                }

                hashtable[number]+=1;
            }

            for(int i=0;i<m;i++)
            {
                string prefix=target.substr(0, i);

                string suffix=target.substr(i, m);

                if(prefix==suffix)
                {
                    if(hashtable.find(prefix)!=hashtable.end())
                    {
                        int frequency=hashtable[prefix];

                        int increment=frequency * (frequency - 1);

                        result+=increment;
                    }
                }
                else
                {
                    if(hashtable.find(prefix)!=hashtable.end() and hashtable.find(suffix)!=hashtable.end())
                    {
                        int prefixFrequency=hashtable[prefix];

                        int suffixFrequency=hashtable[suffix];

                        int increment=prefixFrequency * suffixFrequency;

                        result+=increment;
                    }
                }
            }

            return result;
        }
};