#include <map>
#include <unordered_map>
using namespace std;

class Solution
{
    public:
        int minDeletions(string s)
        {
            int result=0;
            
            unordered_map<char, int> frequencies;
            
            for(char letter : s)
            {
                frequencies[letter]+=1;
            }
            
            map<int, unordered_set<char>> frequencyBuckets;
            
            for(auto [letter, frequency] : frequencies)
            {
                frequencyBuckets[frequency].insert(letter);
            }
            
            for(auto itr=rbegin(frequencyBuckets);itr!=rend(frequencyBuckets);itr++)
            {
                int frequency=itr->first;
                
                while(itr->second.size() > 1)
                {
                    auto letterItr=begin(itr->second);
                    
                    if(frequency - 1 > 0)
                    {
                        frequencyBuckets[frequency - 1].insert(*(letterItr));   
                    }
                    
                    itr->second.erase(letterItr);
                    
                    result+=1;
                }
            }
            
            return result;
        }
};