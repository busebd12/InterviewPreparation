#include <algorithm>
#include <string>
using namespace std;

class Solution
{
    public:
        int maxVowels(string s, int k)
        {
            int result=0;

            int n=s.size();

            int index=0;

            int vowels=0;

            for(;index<k;index+=1)
            {
                if(isVowel(s[index])==true)
                {
                    vowels+=1;
                }
            }

            result=max(result, vowels);

            for(;index<n;index+=1)
            {
                if(isVowel(s[index - k])==true)
                {
                    vowels-=1;
                }

                if(isVowel(s[index])==true)
                {
                    vowels+=1;
                }

                result=max(result, vowels);
            }

            return result;
        }

        bool isVowel(char c)
        {
            return c=='a' or c=='e' or c=='i' or c=='o' or c=='u';
        }
};