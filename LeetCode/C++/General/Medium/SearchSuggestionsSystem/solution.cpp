#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<vector<string>> suggestedProducts(vector<string> & products, string searchWord)
        {
            vector<vector<string>> result;
            
            int n=searchWord.size();
            
            //Hashtable to map prefixes to the words they come from
            map<string, set<string>> hashtable;
            
            //Iterate through products
            for(auto product : products)
            {   
                string prefix{};
                
                for(auto letter : product)
                {
                    //Create prefix
                    prefix.push_back(letter);
                    
                    //Map word the prefix came from to the prefix
                    hashtable[prefix].insert(product);
                }
            }
            
            string prefix{};
            
            for(auto letter : searchWord)
            {
                //Create prefix
                prefix.push_back(letter);
                
                //Iterator pointing to set of all words associated with the prefix
                auto itr=begin(hashtable[prefix]);
                
                vector<string> suggestion;
                
                //Only need the three lexicographically smallest words
                for(int count=0;count<3&&itr!=end(hashtable[str]);count++,itr++)
                {
                    suggestion.emplace_back(*itr);
                }
                
                //Add suggestion to result
                result.emplace_back(suggestion);
            }
            
            return result;
        }
};