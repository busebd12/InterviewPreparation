#include <iostream>
#include <vector>
#include <string>
using namespace std;

void createPrefixArray(vector<int> & prefixArray, string s, const size_t stringSize)
{
	int j=0;

	for(int i=1;i<stringSize;)
	{
		if(s[i]==s[j])
		{
			prefixArray[i]=j+1;

			++i;

			++j;
		}
		else
		{
			if(j!=0)
			{
				j=prefixArray[--j];
			}
			else
			{
				prefixArray[i]=0;

				++i;
			}
		}
	}

	bool repeatedSubstringPattern(string s)
	{
		if(s.empty())
		{
			return true;
		}

		const size_t stringSize=s.size();

		vector<int> prefixArray(stringSize);

		int longestSuffixLength=prefixArray[stringSize-1];

		return (longestSuffixLength > 0 && stringSize % (stringSize-longestSuffixLength)==0) ? true : false;
	}
}