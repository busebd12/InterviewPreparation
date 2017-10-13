#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s)
{
    if(s.size()==0 || s.size()==1)
    {
		return s;
    }

	int start=0;

    int maxLength=1;

    for(int i=0;i<s.size();++i)
    {
        int j=i;

        int k=i;

        while(k < s.size()-1 && s[k]==s[k+1])
        {
            k++;
        }

        while(j > 0 && k < s.size()-1 && s[j-1]==s[k+1])
        {
            k++;

            j--;
        }

        if(k-j+1 > maxLength)
        {
            maxLength=k-j+1;

            start=j;
        }
    }

    return s.substr(start, maxLength);
}

void expandAroundTheCenter(string s, int left, int right, int & start, size_t & maxLength)
{
    const size_t stringSize=s.size();

    while(left >= 0 && right < stringSize && s[left]==s[right])
    {
        if((right-left)+1 > maxLength)
        {
            start=left;

            maxLength=(right-left)+1;
        }

        --left;

        ++right;
    }
}

string longestPalindrome(string s)
{
    const size_t stringSize=s.size();

    if(stringSize < 2)
    {
        return s;
    }

    int left=0;

    size_t maxLength=1;

    for(int index=0;index<stringSize;++index)
    {
        expandAroundTheCenter(s, index-1, index, start, maxLength);

        expandAroundTheCenter(s, index-1, index+1, start, maxLength);
    }

    return s.substr(start, maxLength);
}