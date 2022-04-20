#include <string>
#include <unordered_map>
#include <vector>

/*
Solution: see comments.

Time complexity: O(n * L) [where n is the length of strings and L is the average length of a string from strings]
Space complexity: O(n)
*/

class Solution
{
    public:
        string getHash(string s)
        {
            string hash{};
            
            int m=s.size();
            
            //Generate hash for the current string
            //Example: if the string is abc, then the hash is (b-a)$(c-b) => 1$1
            for(int i=1;i<m;i++)
            {
                //Calculate the ASCII difference between the current and previous character
                int difference=s[i] - s[i-1];
                
                //If the difference is negative, add 26 to make it positive
                if(difference < 0)
                {
                    difference+=26;
                }
                
                //Add the value to our hash string
                hash.append(to_string(difference));
                
                //Add separator character
                hash.push_back('$');
            }
            
            //Remove extra $ character from the end of the hash
            if(hash.back()=='$')
            {
                hash.pop_back();
            }
            
            return hash;
        }
    
        vector<vector<string>> groupStrings(vector<string> & strings)
        {
            vector<vector<string>> result;
            
            //Map hash values to the strings that share that particular hash value
            unordered_map<string, vector<string>> theMap;
            
            for(string & s : strings)
            {
                //Generate the hash for the current string
                string hash=getHash(s);
                
                //Add the string to the list of strings that share the hash
                theMap[hash].emplace_back(s);
            }
            
            //Iterate through the map and add the strings to the result
            for(auto & [key, values] : theMap)
            {
                result.emplace_back(values);
            }
            
            return result;
        }
};