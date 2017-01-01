#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <map>
using namespace std;


void isFunnyString(string String)
{
	bool result=true;

	string reverse(String.rbegin(), String.rend());

	for(int index=1;index<String.size();++index)
	{
		char current=String[index];

		char previous=String[index-1];

		char reverseCurrent=reverse[index];

		char reversePrevious=reverse[index-1];

		if(abs(current-previous)!=abs(reverseCurrent-reversePrevious))
		{
			result=false;

			break;
		}
	}

	if(result==true)
	{
		cout << "Funny" << endl;
	}
	else
	{
		cout << "Not Funny" << endl;
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

		isFunnyString(input);
	}
}