#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

/*
Time complexity: O(n) [where n is the length of croakOfFrogs]
Space complexity: O(4) --> O(1)
*/

class Solution
{
    public:
        int minNumberOfFrogs(string croakOfFrogs)
        {
            int result=0;

            int frogs=0;

            unordered_map<char, int> hashmap={{'c', 0}, {'r', 0}, {'o', 0}, {'a', 0}, {'k', 0}};

            for(char & letter : croakOfFrogs)
            {
                hashmap[letter]+=1;
                
                if(letter=='c')
                {   
                    frogs+=1;

                    result=max(result, frogs);
                }
                else if(letter=='r')
                {
                    if(hashmap['c']==0)
                    {
                        return -1;
                    }

                    hashmap['c']-=1;
                }
                else if(letter=='o')
                {
                    if(hashmap['r']==0)
                    {
                        return -1;
                    }

                    hashmap['r']-=1;
                }
                else if(letter=='a')
                {
                    if(hashmap['o']==0)
                    {
                        return -1;
                    }

                    hashmap['o']-=1;
                }
                else if(letter=='k')
                {
                    if(hashmap['a']==0)
                    {
                        return -1;
                    }

                    hashmap['a']-=1;

                    frogs-=1;
                }
            }

            return (frogs==0) ? result : -1;
        }
};