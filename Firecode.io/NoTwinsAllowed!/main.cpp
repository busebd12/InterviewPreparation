#include <unordered_set>
#include <string>
using namespace std;

bool are_all_characters_unique(string str)
{   
    unordered_set<char> cache;
    
    for(const char & c : str)
    {
        if(cache.count(c))
        {
            return false;
        }
        else
        {
            cache.insert(c);
        }
    }
    
    return true;
}
