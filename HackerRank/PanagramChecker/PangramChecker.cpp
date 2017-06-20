#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool isPangram(string String)
{
	string alphabet="abcdefghijklmnopqrstuvwxyz";

	transform(String.begin(), String.end(), String.begin(), ::tolower);

	sort(String.begin(), String.end());

	return includes(String.begin(), String.end(), alphabet.begin(), alphabet.end());
}

int main()
{
	vector<string> texts {"the quick brown fox jumps over the lazy dog", "the qiuck white cat jumped over the lazy wolf", "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG"};

	for(auto & text : texts)
	{
		if(isPangram(text))
		{
			cout << "The string: " << text << " is a pangram" << endl;
		}
	}
}