#include <set>
#include <string>
#include <unordered_map>
#include <vector>

/*
Solution 1: see comments.

Time complexity: O(n + (n * log(n))) [where n is the length of str1 and str2]
Space complexity: O(u) [where u is the total unique characters from str1 and str2]
*/

class Solution
{
    public:
        bool canConvert(string str1, string str2)
        {
            if(str1==str2)
            {
                return true;
            }

            int n=str1.size();

            //Map characters from str1 to the corresponding character they need to be changed to in str2
            unordered_map<char, char> hashmap;

            for(int i=0;i<n;i++) //O(n)
            {
                //If the current character from str1 is already mapped to a character from str2
                if(hashmap.find(str1[i])!=hashmap.end())
                {
                    char mapped=hashmap[str1[i]];

                    //If the character it is mapped to does not match the current character in str2,
                    //then the letter from str1 has to map to two different letters. This isn't allowed
                    //since each chracter can only be transformed into at most one other character.
                    //So, return false
                    if(mapped!=str2[i])
                    {
                        return false;
                    }
                }
                //Else, no mapping yet for this str1 character, so create it
                else
                {
                    hashmap[str1[i]]=str2[i];
                }
            }

            //Set of unique characters from str2            
            set<char> str2Dictionary(str2.begin(), str2.end()); //O(n * log(n))

            //In order for str1 to successfully transform into str2, there needs to be at least one character
            //from the alphabet that is not used. Otherwise, we could end up in a situation where we are unable
            //to select target character for a transformation since it's already mapped to another letter from str1
            return str2Dictionary.size() < 26;
        }
};

/*
Solution 2: see comments from the first solution for the explanation.

Time complexity: O(n + n) --> O(n) [where n is the length of str1 and str2]
Space complexity: O(u) [where u is the total unique characters from str1 and str2]
*/

class Solution
{
    public:
        bool canConvert(string str1, string str2)
        {
            if(str1==str2)
            {
                return true;
            }

            int n=str1.size();

            unordered_map<char, char> hashmap;

            for(int i=0;i<n;i++) //O(n)
            {
                if(hashmap.find(str1[i])!=hashmap.end())
                {
                    char mapped=hashmap[str1[i]];

                    if(mapped!=str2[i])
                    {
                        return false;
                    }
                }
                else
                {
                    hashmap[str1[i]]=str2[i];
                }
            }

            vector<int> frequencies(26, 0);

            for(char letter : str2) //O(n)
            {
                int index=letter - 'a';

                frequencies[index]+=1;
            }

            int unused=count(frequencies.begin(), frequencies.end(), 0); //O(26)

            return unused > 0;
        }
};

/*
Solution 2: see comments from the first solution for the explanation.

Time complexity: O(n + n) --> O(n) [where n is the length of str1 and str2]
Space complexity: O(26) --> O(1)
*/

class Solution
{
    public:
        bool canConvert(string str1, string str2)
        {
            if(str1==str2)
            {
                return true;
            }

            int n=str1.size();

            vector<char> hashmap(26, '$');

            for(int i=0;i<n;i++) //O(n)
            {
                char str1Letter=str1[i];

                int index=str1Letter - 'a';

                if(hashmap[index]!='$')
                {
                    if(hashmap[index]!=str2[i])
                    {
                        return false;
                    }
                }
                else
                {
                    hashmap[index]=str2[i];
                }
            }

            vector<int> str2Frequencies(26, 0);

            for(char letter : str2) //O(n)
            {
                int index=letter - 'a';

                str2Frequencies[index]+=1;
            }

            int unused=count(str2Frequencies.begin(), str2Frequencies.end(), 0);

            return unused > 0;
        }
};