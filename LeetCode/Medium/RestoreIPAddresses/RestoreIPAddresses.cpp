#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValid(string substring)
{
    if(substring.size() > 3 || stoi(substring) > 255 || substring.size()==0 || (substring[0]=='0' && substring.size() > 1))
    {
        return false;
    }

    return true;
}

vector<string> restoreIpAddresses(string s)
{
    vector<string> ipAddresses;

    const int stringSize=int(s.size());

    char dot='.';

    for(int i=1;i<4 && i<stringSize-2;++i)
    {
        for(int j=i+1;j<i+4 && j<stringSize-1;++j)
        {
            for(int k=j+1;k<j+4 && k<stringSize;++k)
            {
                string s1=s.substr(0, i);

                string s2=s.substr(i, j-i);

                string s3=s.substr(j, k-j);

                string s4=s.substr(k, stringSize-k);

                if(isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4))
                {
                    ipAddresses.emplace_back(s1 + dot + s2 + dot + s3 + dot + s4);
                }
            }
        }
    }

    return ipAddresses;
}