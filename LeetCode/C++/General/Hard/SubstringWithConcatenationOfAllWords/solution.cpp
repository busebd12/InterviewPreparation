#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> findSubstring(string s, vector<string> & words)
        {
            vector<int> result;
            
            string_view sView=s;
    
            int n=sView.size();

            int w=words.size();

            int wordSize=words[0].size();

            int concatenatedLength=w * wordSize;

            unordered_map<string_view, int> frequencies;

            for(string & word : words)
            {
                string_view view=word;

                if(frequencies.find(view)==end(frequencies))
                {
                    frequencies.emplace(view, 0);
                }

                frequencies[view]+=1;
            }

            for(int index=0;index+concatenatedLength<=n;index++)
            {
                string_view concatenation=sView.substr(index, concatenatedLength);

                if(isValidConcatenation(frequencies, concatenation, wordSize)==true)
                {   
                    result.push_back(index);
                }
            }
            
            return result;
        }
    
        bool isValidConcatenation(unordered_map<string_view, int> frequencies, string_view & concatentation, int & wordSize)
        {
            for(int index=0;index<concatentation.size();index+=wordSize)
            {
                string_view word=concatentation.substr(index, wordSize);

                if(frequencies.find(word)==end(frequencies))
                {
                    return false;
                }

                frequencies[word]-=1;

                if(frequencies[word]==0)
                {
                    frequencies.erase(word);
                }
            }

            return true;
        }
};