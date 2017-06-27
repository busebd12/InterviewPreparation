#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool containsDuplicates(vector<int> & Nums)
{
	map<int, int> numsMap;

	for(auto & element : Nums)
	{
		numsMap[element]++;
	}

	for(auto & element : Nums)
	{
		if(numsMap[element] > 1)
		{
			return true;
		}
	}

	return true;
}