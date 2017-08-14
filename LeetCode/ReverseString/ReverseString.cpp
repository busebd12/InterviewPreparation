#include <iostream>
#include <string>
using namespace std;

void reverseStringHelper(string & s, int left, int right)
{
    const size_t halfway=(s.size())/2;
    
    if(left==halfway+1 || right==halfway-1)
    {
        return;
    }
    
    swap(s[left], s[right]);
    
    reverseStringHelper(s, --left, ++right);
}

string reverseString(string s)
{
    if(s.empty())
    {
        return "";
    }
    
    int right=0;
    
    int left=s.size()-1;
    
    reverseStringHelper(s, left, right);
    
    return s;
}