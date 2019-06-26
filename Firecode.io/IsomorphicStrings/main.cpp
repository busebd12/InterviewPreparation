#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

bool is_isomorphic(string input1, string input2)
{
    if(input1.empty() && input2.empty())
    {
        return true;
    }
    
    if(input1.empty() || input2.empty())
    {
        return false;
    }
    
    if(input1.size()!=input2.size())
    {
        return false;
    }
    
    int n=int(input1.size());
    
    unordered_map<char, int> mapped;
    
    unordered_set<char> found;
    
    for(int index=0;index<n;++index)
    {
        char letter1=input1[index];
        
        char letter2=input2[index];
        
        if(mapped.count(letter1))
        {
            if(mapped[letter1]!=letter2)
            {
                return false;
            }
        }
        else
        {
            if(found.count(letter2))
            {
                return false;
            }
            
            mapped[letter1]=letter2;
            
            found.insert(letter2);
        }
    }
    
    return true;
}
