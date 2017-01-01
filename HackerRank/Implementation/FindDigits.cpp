#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <list>
#include <tuple>
#include <utility>
#include <cmath>
#include <string>
using namespace std;

void findDigits(int N)
{
	string numberAsString=to_string(N);

	int count=0;

	for(int index=0;index<numberAsString.size();++index)
	{
		int candidate=numberAsString[index]-'0';

		if(candidate==0)
		{
			continue;
		}
		else
		{
			if(N%candidate==0)
			{
				count++;
			}
		}
	}

	cout << count << endl;
}

int main(int argc, char* argv [])
{
	/*
	int numberOfLoops;

	int N;
	
	cin >> numberOfLoops;

	for(int count=0;count<numberOfLoops;++count)
	{
		cin >> N;

		numberOfGrowthCycles(N);
	}
	*/

	int number;

	cout << "Enter a number: " << endl;

	cin >> number;

	findDigits(number);

}