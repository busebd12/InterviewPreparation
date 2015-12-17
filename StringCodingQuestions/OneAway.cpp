#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <cmath>
using namespace std;

bool oneOrZeroEditsAway(string String1, string String2)
{
	/*Three types of edits that can be made to a string: insert a character, remove a character, or replace a character*/

	bool result;

	int lengthOfStringOne=String1.length();

	int lengthOfStringTwo=String2.length();

	int lengthDifference=abs(lengthOfStringOne-lengthOfStringTwo);

	if(lengthDifference > 1)
	{
		result=false;
	}

	int totalLength=lengthOfStringOne+lengthOfStringTwo;

	map<char, int> characterMap;

	/*Do the same for loop twice because the strings might
	not be the same length, so we could miss a character when we
	are adding characters to the map
	*/
	for(int i=0;i<lengthOfStringOne;++i)
	{
		char temp=String1[i];

		characterMap[temp];

		characterMap[temp]++;
	}

	for(int j=0;j<lengthOfStringTwo;++j)
	{
		char temp=String2[j];

		characterMap[temp];

		characterMap[temp]++;
	}

	int characterPairCount=0;

	for(const auto & element : characterMap)
	{
		if(element.second==2)
		{
			characterPairCount++;
		}
	}

	int newTotalLength=totalLength-(characterPairCount*2);

	/*If the strings are the same length, we only have to change one (or zero if the strings are the same) characters 
	since we are limited to a max of one edit. So, if we take the number of 
	pairs of characters, multiply that by two (since each pair contains two characters).
	and subtract the result from the combined length of the two strings, we should get 2,
	the exact number of characters that differ between the two strings. If we get something
	more than two, then we know it would take more than one (more than the max we are allowed)
	edits to change one string into the other
	*/
	if(lengthDifference==0)
	{
		if(newTotalLength > 2)
		{
			result=false;
		}
		else
		{
			result=true;
		}
	}

	/*If the strings differ in length by one, then we have to change at least one character
	however, since we are only allowed a max of one edit, we can only change one character
	so, we do the same math as in the case when the length difference between the two strings was zero
	except if the difference between the combined length of the two strings and the number of pairs of characters
	is greater than one, then we know we can't transform one string into another in just one edit
	*/
	else if(lengthDifference==1)
	{
		if(newTotalLength > 1)
		{
			result=false;
		}
		else
		{
			result=true;
		}
	}

	return result;
}

int main()
{
	string String3="pale";

	string String4="ple";

	bool outcome2=oneOrZeroEditsAway(String3, String4);

	cout << boolalpha << outcome2 << endl;

	cout << endl;

	string String5="pales";

	string String6="pale";

	bool outcome3=oneOrZeroEditsAway(String5, String6);

	cout << boolalpha << outcome3 << endl;

	cout << endl;

	string String7="pale";

	string String8="bale";

	bool outcome4=oneOrZeroEditsAway(String7, String8);

	cout << boolalpha << outcome4 << endl;

	cout << endl;

	string String1="Pale";

	string String2="Bake";

	bool outcome1=oneOrZeroEditsAway(String1, String2);

	cout << boolalpha << outcome1 << endl;

	cout << endl;

	string String9="puddles";

	string String10="mud";

	bool outcome5=oneOrZeroEditsAway(String9, String10);

	cout << boolalpha << outcome5 << endl;
}