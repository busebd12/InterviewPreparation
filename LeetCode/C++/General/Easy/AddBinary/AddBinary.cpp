#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string a, string b)
{
    if(a.empty())
    {
        return b;
    }
    
    if(b.empty())
    {
        return a;
    }
    
    if(a.empty() && b.empty())
    {
        return "";
    }
    
    string answer{};
    
    int i=a.size()-1;
    
    int j=b.size()-1;
    
    int carry=0;
    
    while(i >= 0 || j >= 0)
    {
        int sum=carry;
        
        if(i >= 0)
        {   
            sum+=a[i]-'0';
        }
        
        if(j >= 0)
        {   
            sum+=b[j]-'0';
        }
        
        answer+=to_string(sum%2);
        
        carry=sum/2;
        
        --i;
        
        --j;
    }
    
    if(carry!=0)
    {
        answer+=to_string(carry);
    }
    
    reverse(begin(answer), end(answer));
    
    return answer;
}