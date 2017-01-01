#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <functional>
using namespace std;

/*This code corresponds to the question from the chapter on arrays and strings in which 
you are asked to write a funtion to determine whether or not a string contains all unique characters
*/

void hasUniqueCharacters(string S)
{
	/*sort the string from least to greatest using the sort function 
	provided by the standard template library*/
	sort(S.begin(), S.end());

	copy(S.begin(), S.end(), ostream_iterator<char>(cout, " "));

	cout << endl;

	/*Searches the range [first,last) in this case, our string, for the first occurrence of two consecutive elements that match
	and returns an iterator to the first of these two elements. Since we have sorted the string, any duplicate characters will be adjacent to each other*/
	auto itr=adjacent_find(S.begin(), S.end());

	/*if we find an adjacent pair*/
	if(itr!=S.end())
	{
		cout << "The string has duplicate characters!" << endl;

		if(*itr==' ')
		{
			cout << "The first character of a pair of identical characters is a space" << endl;
		}
		else
		{
			cout << "The first of character of a pair of identical characters is " << *itr << endl;	
		}
	}
	/*else, we didn't find an adjacent pair*/
	else
	{
		cout << "The string does not have duplicate characters" << endl;
	}

}

int main()
{
	string myString="The the quick brown fox jumped over the lazy dog";

	hasUniqueCharacters(myString);
}