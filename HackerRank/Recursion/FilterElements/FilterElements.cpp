#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
using namespace std;

vector<pair<int, pair<int, int>>> solution(vector<int> Input, vector<pair<int, pair<int, int>>> Cache, size_t T, int Index)
{
	if(Index==T)
	{
		return Cache;
	}

	int digit=Input[Index];

	auto result=find_if(begin(Cache), end(Cache), [digit](const auto & element) {return element.first==digit;});

	if(result==end(Cache))
	{
		Cache.emplace_back(make_pair(digit, make_pair(Index, 1)));
	}
	else
	{
		result->second.second++;
	}

	return solution(Input, Cache, T, Index+1);
}

void solutionHelper(vector<int> Input, size_t T, int K)
{
	vector<pair<int, pair<int, int>>> cache(T);

	cache=solution(Input, cache, T, 0);

	size_t cacheSize=cache.size();

	sort(begin(cache), end(cache), [](const auto & First, const auto & Second) {return First.second.first < Second.second.first;});

	bool noElements=false;

	for(int index=0;index<cacheSize;++index)
	{
		auto current=cache[index];

		if(current.second.second >= K)
		{
			cout << current.first << " ";

			noElements=true;
		}
	}

	if(noElements==false)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << endl;
	}
}