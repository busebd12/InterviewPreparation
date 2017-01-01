#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

long long gcd(long long Larger, long long Smaller, vector<long long> Remainders)
{
	if(Smaller==0)
	{
		return Remainders[Remainders.size()-2];
	}

	long long howManyTimes=Larger/Smaller;

	long long currentRemainder=Larger-(Smaller*howManyTimes);

	Remainders.emplace_back(currentRemainder);

	return gcd(Smaller, currentRemainder, Remainders);
}