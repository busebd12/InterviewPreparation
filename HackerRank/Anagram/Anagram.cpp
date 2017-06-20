#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <map>
#include <tuple>
#include <utility>
using namespace std;

void numberOfOperations(string String)
{
	int stringSize=String.size();

	//if the string is of odd length, then it can't possibly be an anagram
	if(String.size()%2!=0)
	{
		cout << -1 << endl;
	}
	else
	{
		vector<char> occurance;

		occurance.resize(26);

		int sum {};

		for(auto & element : occurance)
		{
			element=0;
		}

		//count up all the letters that are used in the first half of the word
		for(int count=0;count<stringSize/2;++count)
		{
			char letter=String[count];

			++occurance[letter-'a'];
		}

		//count down all the letters that are used in the second half of the world
		for(int count=stringSize/2;count<stringSize;++count)
		{
			char letter=String[count];

			--occurance[letter-'a'];
		}

		//sum the occurances of all the characters
		for(auto & element : occurance)
		{
			sum+=abs(element);
		}

		//Divide the total sum since it's only necessaryto change one half of the full string and all possible charachters that can change have been counted.
		sum/=2;

		cout << sum << endl;
	}
}

int main(int argc, char* argv [])
{
	int numberOfLoops;

	string input;

	cin >> numberOfLoops;

	for(int count=0;count<numberOfLoops;++count)
	{
		cin >> input;

		numberOfOperations(input);
	}
}