#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/*
This code corresponds to the question from the chapter on Arrays and Strings where
you have to write an algorithm to determine if two strings are permutations
*/

void checkPermutation(string stringOne, string stringTwo)
{
	
	/*is_permutation is an Algorithm provided by the Standard Template Library
	that determines if two ranges (things) are permutations*/
	if(is_permutation(stringOne.begin(), stringOne.end(), stringTwo.begin()))
	{
		cout << stringOne << " and " << stringTwo << " are permutations" << endl;
	}
	else
	{
		cout << stringOne << " and " << stringTwo << " are not permutations" << endl;
	}
}


int main()
{
	string stringOne="army";

	string stringTwo="mary";

	string s1="tom";

	string s2="mop";

	checkPermutation(stringOne, stringTwo);

	cout << endl;

	checkPermutation(s1, s2);
}