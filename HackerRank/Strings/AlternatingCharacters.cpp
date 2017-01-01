#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

void numberOfDeletions(string String)
{
	int deletions=0;

	int current;

	int next;

	for(int spot=0;spot<String.size();)
	{
		current=spot;

		next=++spot;

		if(String[current]==String[next])
		{
			deletions++;
		}
	}

	//cout << "The number of deletions: " << deletions << endl;

	cout << deletions << endl;
}

int main(int argc, char * argv[])
{
	string input;

	while(cin.good())
	{
		cout << "Enter a word" << endl;

		cin >> input;

		//check to see if the string has an digits in it
		if(!(any_of(input.begin(), input.end(), ::isdigit)))
		{
			numberOfDeletions(input);
		}
 	}
}