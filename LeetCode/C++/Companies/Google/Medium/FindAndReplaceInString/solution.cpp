#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <utility>
#include <vector>

/*
Solution: see comments for details

Time complexity: O((n log n) + n) [where n is the number of indices in the indices vector]
Space complexity: O(n)
*/

class Solution
{
    public:
        string findReplaceString(string s, vector<int> & indices, vector<string> & sources, vector<string> & targets)
        {
            int n=s.size();

            int m=indices.size();

            string result{};

            int index=0;

            //Hashtable that maps the replacement index to a pair of strings: the source and target
            //Use map becuase we need to sort the replacement indices in increasing order
            map<int, pair<string, string>> hashtable;

            //Fill the map
            for(int i=0;i<m;i++)
            {
                hashtable.emplace(indices[i], make_pair(sources[i], targets[i]));
            }

            //Since the first replacement index could be after index zero,
            //we need to add letters from the string until we hit the first replacement index
            while(index < n && index < begin(hashtable)->first)
            {
                result+=s[index];

                index++;
            }

            //Iterate through the hashtable
            for(auto element : hashtable)
            {
                //Replacement index
                int start=element.first;

                string source=element.second.first;

                string target=element.second.second;

                int substringLength=source.size();

                //Get the substring starting at index start and extending substringLength characters
                string substring=s.substr(start, substringLength);

                //If the substring matches the source, add the target to the result string and move our index variable forward substringLength spots
                if(substring==source)
                {
                    result+=target;

                    index+=substringLength;
                }
                //Else, the source does not match the substring
                //Add the substring to the result string and move our index variable forward substringLength spots
                else
                {
                    result+=substring;

                    index+=substringLength;
                }

                //To handle the case where the current replacement index is not consecutively followed by the next replacement index, we keep moving the index variable forward till we reach the next replacement index, adding the letters as we go
                while(index < n && !hashtable.count(index))
                {
                    result+=s[index];

                    index++;
                }
            }

            return result;
        }
};