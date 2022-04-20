#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;


class Solution
{
    public:
        std::vector<int> partitionLabels(std::string S)
        {
            vector<int> result;
            
            int n=S.size();
            
            //Map each character in S to a pair of indices - the first index at which the letter appears in S and the last index at which the letter appears in S
            unordered_map<char, pair<int, int>> hashtable;
            
            //Create the mappings
            for(int i=0;i<n;i++)
            {
                char c=S[i];
                
                if(!hashtable.count(c))
                {
                    hashtable[c]=make_pair(i, i);
                }
                else
                {
                    hashtable[c].second=max(hashtable[c].second, i);
                }
            }
            
            //We use this unordered_set to prevent us from considering duplicate characters as we iterate through S
            unordered_set<char> cache;
            
            //Start of the partition
            int start=hashtable[S[0]].first;
            
            //End of the partition
            int end=hashtable[S[0]].second;
            
            //Insert the first letter of S into the cache
            cache.insert(S[0]);
            
            //Iterate through S
            for(int i=0;i<n;i++)
            {
                char c=S[i];
                
                //If we haven't seen the character before
                if(!cache.count(c))
                {
                    //The first index at which the character appears
                    int cStart=hashtable[c].first;
                    
                    //The last index at which the character appears
                    int cEnd=hashtable[c].second;
                    
                    //If the start and end indices for the current character fall within the current parition range
                    if(start < cStart && cEnd < end)
                    {   
                        //Insert the character into the cache
                        cache.insert(c);
                    }
                    //Else if, the start index for the current character falls within the partition range but the end index does not, then extend the end of the partition
                    else if(start < cStart && cStart < end && cEnd > end)
                    {   
                        cache.insert(c);
                        
                        end=cEnd;
                    }
                    //Else if, the start and end indices for the current character fall outside of the partitions range, then the current partition ends at this index
                    else if(cStart > end && cEnd > end)
                    {
                        //Calculate the length of the partition
                        int length=(end - start) + 1;
                        
                        result.emplace_back(length);
                        
                        cache.clear();
                        
                        cache.insert(c);
                        
                        //Update start and end values to match the start and end of the new partition
                        start=cStart;
                        
                        end=cEnd;
                    }
                }
            }
            
            //If the end of the last partition extends to the last index of S, then calculate the length and add it to the result
            int length=(end - start) + 1;
            
            result.emplace_back(length);
            
            return result;
        }
};