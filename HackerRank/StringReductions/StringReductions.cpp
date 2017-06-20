#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <tuple>
#include <utility>
#include <string>
#include <iterator>
using namespace std;

void stringReduction(string Input)
{
	vector<char> seenCharacters;

	for(auto current=Input.begin();current!=Input.end();++current)
	{
		char letter=*current;

		//check to see if we've already seen the character
		auto result=find_if(seenCharacters.begin(), seenCharacters.end(), [letter] (const char & element) {return element==letter;});

		//if we haven't, add it to the vector
		if(result==seenCharacters.end())
		{
			seenCharacters.push_back(letter);
		}
	}

	cout << "The string with characters removed that occured previously:" << endl;

	copy(seenCharacters.begin(), seenCharacters.end(), ostream_iterator<char>(cout, ""));

	cout << endl;
}

int main(int argc, char *argv [])
{
	string input;

	while(cin.good())
	{
		cin >> input;

		stringReduction(input);
	}
}