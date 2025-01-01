#include <string>
#include <vector>
using namespace std;

class Solution
{
    public:
        bool halvesAreAlike(string s)
        {
            int n=s.size();

            int half=n/2;

            vector<int> firstHalfVowelFrequency(128, 0);

            for(int index=0;index<half;index++)
            {
                if(isVowel(s[index])==true)
                {
                    int characterIndex=int(s[index]);

                    firstHalfVowelFrequency[characterIndex]+=1;
                }
            }

            int firstHalfTotalVowels=0;

            for(int index=0;index<128;index++)
            {
                int vowelFrequency=firstHalfVowelFrequency[index];
                
                if(vowelFrequency > 0)
                {
                    firstHalfTotalVowels+=vowelFrequency;
                }
            }

            vector<int> secondHalfVowelFrequency(128, 0);

            for(int index=half;index<n;index++)
            {
                if(isVowel(s[index])==true)
                {
                    int characterIndex=int(s[index]);

                    secondHalfVowelFrequency[characterIndex]+=1;
                }
            }

            int secondHalfTotalVowels=0;
            
            for(int index=0;index<128;index++)
            {
                int vowelFrequency=secondHalfVowelFrequency[index];
                
                if(vowelFrequency > 0)
                {
                    secondHalfTotalVowels+=vowelFrequency;
                }
            }

            return firstHalfTotalVowels==secondHalfTotalVowels;

        }

        bool isVowel(char & letter)
        {
            return (letter=='a' or letter=='e' or letter=='i' or letter=='o' or letter=='u' or letter=='A' or letter=='E' or letter=='I' or letter=='O' or letter=='U');
        }
};