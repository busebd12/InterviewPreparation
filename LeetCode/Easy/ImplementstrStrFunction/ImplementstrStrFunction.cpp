#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle)
{
	if(haystack.size() < needle.size())
	{
		return -1;
	}

	if(haystack.empty() && needle.empty())
	{
		return 0;
	}

	if(needle.empty() && !haystack.empty())
	{
		return 0;
	}

	const size_t haystackSize=haystack.size();

	const size_t needleSize=needle.size();

	string search{};

	for(int i=0;i<haystackSize;++i)
	{
		if(i+needleSize > haystackSize)
		{
			break;
		}

		for(int j=i;j<needleSize+i;++j)
		{
			search+=haystack[j];
		}

		if(search==needle)
		{
			return i;
		}
		else
		{
			search.clear();
		}
	}

	return -1;
}