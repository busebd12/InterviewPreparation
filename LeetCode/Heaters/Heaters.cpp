#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findRadius(vector<int> & houses, vector<int> & heaters)
{
	sort(begin(heaters), end(heaters));

	int answer=0;

	for(auto & house : houses)
	{
		auto heater=lower_bound(begin(heaters), end(heaters), house);

		int Distance=numeric_limits<int>::max();

		if(heater!=end(heaters))
		{
			Distance=min(Distance, *heater-house);
		}

		if(heater!=begin(heaters))
		{
			Distance=min(Distance, h-(*(heater-1)));
		}

		answer=max(answer, Distance);
	}

	return answer;
}