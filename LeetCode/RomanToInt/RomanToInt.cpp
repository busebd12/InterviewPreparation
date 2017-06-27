#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;

void stringToUppercase(string & s)
{
	size_t stringSize=s.size();

	for(int index=0;index<stringSize;++index)
	{
		s[index]=toupper(s[index]);
	}
}

int romanToInt(string s)
{
	if(s.empty())
	{
		return 0;
	}

	int sum{};

	map<char, char> romanNumeralsMap;

	romanNumeralsMap.emplace('I', 1);

	romanNumeralsMap.emplace('V', 5);

	romanNumeralsMap.emplace('X', 10);

	romanNumeralsMap.emplace('L', 50);

	romanNumeralsMap.emplace('C', 100);

	romanNumeralsMap.emplace('D', 500);

	romanNumeralsMap.emplace('M', 1000);

	size_t stringSize=s.size();

	stringToUppercase(s);

	for(int index=0;index<stringSize;)
	{
		if(romanNumeralsMap[s[index]] < romanNumeralsMap[s[index+1]])
		{
			sum+=abs(romanNumeralsMap[s[index]]-romanNumeralsMap[s[index+1]]);

			index+=2;
		}
		else
		{
			sum+=romanNumeralsMap[s[index]];

			++index;
		}
	}

	return sum;
}