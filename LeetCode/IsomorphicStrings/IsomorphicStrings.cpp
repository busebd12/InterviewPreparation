#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;

bool isIsomorphic(string s, string t)
{
    if(s.empty() || t.empty())
    {
        return true;
    }
    
    map<char, char> sToTCharacters;
    
    map<char, char> tToSCharacters;
    
    const size_t stringSize=s.size();
    
    for(int index=0;index<stringSize;++index)
    {
        //if we haven't seen the character in s and the character in t before, add them to the map
        if(sToTCharacters.find(s[index])==end(sToTCharacters) && tToSCharacters.find(t[index])==end(tToSCharacters))
        {
            sToTCharacters[s[index]]=t[index];
            
            tToSCharacters[t[index]]=s[index];
        }
        else
        {
            //we have either seen the character from s or the character from t before.
            //let's make sure that all occurances map to the same character.
            //i.e. no two characters can map to the same character
            if(sToTCharacters[s[index]]!=t[index] || tToSCharacters[t[index]]!=s[index])
            {
                return false;
            }
        }
    }
    
    return true;
}
