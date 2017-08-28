#include <iostream>
#include <string>
using namespace std;

string addStrings(string num1, string num2)
{
    if(num1.empty() && num2.empty())
    {
        return "";
    }

    if(num1.empty())
    {
        return num2;
    }

    if(num2.empty())
    {
        return num1;
    }

    const size_t num1Size=num1.size();

    const size_t num2Size=num2.size();

    int carry=0;

    string answer="";

    int i=num1Size-1;
    
    int j=num2Size-1;
    
    while(i>=0 || j>=0 || carry)
    {
        long sum=0;
        
        if(i >= 0)
        {
            sum+=(num1[i] - '0');
            
            i--;
        }
        
        if(j >= 0)
        {
            sum += (num2[j] - '0');
            
            j--;
        }
        
        sum+=carry;
        
        carry=sum/10;
        
        sum=sum % 10;
        
        answer=answer + to_string(sum);
    }
    
    reverse(begin(answer), end(answer));
    
    return answer;
}