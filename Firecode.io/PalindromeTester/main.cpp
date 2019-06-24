#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

bool is_string_palindrome(string str)
{   
    int i=0;
    
    int j=int(str.size()-1);
    
    while(i < j)
    {
        if(str[i++]!=str[j--])
        {
            return false;
        }
    }
    
    return true;
}
