#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int convertBinaryToDecimal(string binary)
{
    int value=0;

    int exponent=0;

    const int binarySize=int(binary.size());

    for(int i=binarySize-1;i>=0;--i)
    {
        if(binary[i]=='1')
        {
            value+=pow(2, exponent);
        }

        ++exponent;
    }

    return value;
}

vector<string> helper(int n)
{
    vector<string> binary;

    if(n==1)
    {
        binary.emplace_back("0");

        binary.emplace_back("1");

        return binary;
    }
    else
    {
        vector<string> previous=helper(n-1);

        for(int index=int(previous.size()-1);index>=0;--index)
        {
            previous.emplace_back(previous[index]);
        }

        for(int i=0;i<previous.size()/2;++i)
        {
            previous[i]='0' + previous[i];
        }

        for(int j=int(previous.size()/2);j<previous.size();++j)
        {
            previous[j]='1' + previous[j];
        }

        binary.clear();

        for(const auto & element : previous)
        {
            binary.emplace_back(element);
        }

        return binary;
    }
}

vector<int> grayCode(int n)
{
    vector<int> grayCode;

    if(n==0)
    {
        grayCode.emplace_back(0);

        return grayCode;
    }

    vector<string> binary=helper(n);

    for(auto & s : binary)
    {
        grayCode.emplace_back(convertBinaryToDecimal(s));
    }

    return grayCode;
}