#include <iostream>
#include <string>
#include <utility>
using namespace std;

bool judgeCircle(string moves)
{
	if(moves.empty())
	{
		return false;
	}

	const size_t movesSize=moves.size();

	pair<int, int> start=make_pair(0, 0);

	pair<int, int> end=make_pair(0, 0);

	for(const auto & letter : moves)
	{
		if(letter=='u' || letter=='U')
		{
			end.first++;
		}
		else if(letter=='d' || letter=='D')
		{
			end.first--;
		}
		else if(letter=='l' || letter=='L')
		{
			end.second--;
		}
		else
		{
			end.second++;
		}
	}

	return end==start;
}