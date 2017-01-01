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

void fillAlphabet(string & Alphabet)
{
	for(char letter='a';letter<='z';++letter)
	{
		Alphabet.push_back(letter);
	}
}

void determineGemstones(vector<string> Strings, string Alphabet, int NumberOfLoops)
{
	map<char, int> possibleGemstones;

	for(int current=0;current<Strings.size();++current)
	{
		string currentString=Strings[current];

		for(int spot=0;spot<currentString.size();++spot)
		{
			char currentStringLetter=currentString[spot];

			char alphabetLetter=Alphabet[spot];

			if(currentStringLetter==alphabetLetter)
			{
				possibleGemstones[currentStringLetter]++;
			}
		}
	}

	int gemstones {};

	for(const auto & letter : possibleGemstones)
	{
		if(letter.second==NumberOfLoops)
		{
			gemstones++;
		}
	}

	cout << gemstones << endl;
}

void removeDuplicateCharacters(string & String)
{
	sort(String.begin(), String.end());

	String.erase(unique(String.begin(), String.end()), String.end());
}

int main(int argc, char * argv[])
{
	string alphabet {};

	vector<string> strings;

	int numberOfLoops;

	string input;

	cin >> numberOfLoops;

	fillAlphabet(alphabet);

	for(int count=0;count<numberOfLoops;++count)
	{
		cin >> input;

		removeDuplicateCharacters(input);

		strings.push_back(input);
	}

	determineGemstones(strings, alphabet, numberOfLoops);
}