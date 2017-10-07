#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string reverseVowels(string s)
{
    unordered_map<char, int> letterMap;
    
    letterMap['A']=1;
    
    letterMap['E']=1;
    
    letterMap['I']=1;
    
    letterMap['O']=1;
    
    letterMap['U']=1;
    
    letterMap['a']=1;
    
    letterMap['e']=1;
    
    letterMap['i']=1;
    
    letterMap['o']=1;
    
    letterMap['u']=1;
    
    int start=0;
    
    int end=(int)s.size()-1;
    
    while(start < end)
    {
        while(start < end && letterMap[s[start]]==0)
        {
            start++;
        }

        while(start < end && letterMap[s[end]]==0)
        {
            end--;
        }
            
        swap(s[start],s[end]);
        
        start++;
        
        end--;
    }
    
    return s;
}