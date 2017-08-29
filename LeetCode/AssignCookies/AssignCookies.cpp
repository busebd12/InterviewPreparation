#include <iostream>
#include <vector>
using namespace std;

int findContentChildren(vector<int> & s, vector<int> & g)
{
	if(s.empty() || g.empty())
	{
		return 0;
	}

	sort(begin(s), end(s));

	sort(begin(g), end(g));

	int greedIndex=0;

	int answer=0;

	const size_t sSize=s.size();

	const size_t gSize=g.size();

	for(int cookieIndex=0;cookieIndex<sSize && greedIndex<gSize;++cookieIndex)
	{
		if(s[cookieIndex] >= g[greedIndex])
		{
			++answer;

			++greedIndex;
		}
	}

	return answer;
}