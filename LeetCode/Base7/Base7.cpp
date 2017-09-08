#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string convertToBaseHelper(int num, int base)
{
    if(num==0)
    {
        return "0";
    }
    
    string result="";

    bool isNegative=(num < 0) ? true : false;

    if(isNegative)
    {
        num*=-1;
    }

    while(num!=0)
    {
        int remainder=num % base;

        int quotient=num/base;

        num=quotient;

        result+=('0' + remainder);
    }

    reverse(begin(result), end(result));

    if(isNegative)
    {
        result='-' + result;
    }

    return result;
}

string convertToBase7(int num)
{
    int base=7;

    return convertToBaseHelper(num, base);
}