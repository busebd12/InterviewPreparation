#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseStr(string s, int k)
{
    const size_t stringSize=s.size();

    for(int i=0;i<s.length();i+=2*k)
    {
        if((i+k) <= stringSize)
        {
            reverse(begin(s)+i, begin(s)+(i+k));
        }
        else
        {
            reverse(begin(s)+i, end(s));
        }
    }
    
    return s;
}