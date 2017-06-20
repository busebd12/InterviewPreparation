#include <iostream>
#include <algorithm>
#include <utility>
#include <numeric>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <unordered_map>
#include <iterator>
#include <random>
#include "CreateTestCase.cpp"
using namespace std;

long long int solution(vector<long long int> & Healths)
{
	size_t healthsSize=Healths.size();

	//sort the healths
	sort(begin(Healths), end(Healths));

	//get the sum
	long long int sum=accumulate(begin(Healths), end(Healths), static_cast<long long int>(0));

	int strength=1;

	long long int pExperiencePoints=sum;

	long long int currentMax {};

	/*
	The main idea is this: we start with our max experience points being the sum of the all the healths of all the monsters.
	This would be like if we just battled every monster. Then, as we loop through all the health values, we increase our strength
	since we ate a monster and then we mutliply our sum (minus the health value of the monster we just ate) by our new strength.
	If the product we just calculated is greater than the original sum, then that is our new greatest experience point value.
	At some point, our increase in experience points will stop. This is the point where we have eaten the perfect amount of monsters*;	
	*/
	for(int index=0;index<healthsSize;++index)
	{
		++strength;

		sum-=Healths[index];

		currentMax=sum*strength;

		if(currentMax > pExperiencePoints)
		{
			pExperiencePoints=currentMax;
		}
	}

	return pExperiencePoints;
}

int main(int argc, char * argv [])
{
	int numberOfTestCases;

	cin >> numberOfTestCases;

	while(numberOfTestCases--)
	{
		int numberOfMandragoras;

		cin >> numberOfMandragoras;

		vector<long long int> healths;

		for(int index=0;index<numberOfMandragoras;++index)
		{
			long long int health;

			cin >> health;

			healths.push_back(health);
		}

		cout << solution(healths) << endl;

		healths.clear();
	}
}