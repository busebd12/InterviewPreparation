#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

/*This code corresponds to the question which asks you to write an algorithm 
that replaces all occurrences of spaces in a string with %20*/

void replaceSpaces(string String, int trueLength)
{
	size_t position=0;

	/*The for loop finds the position of the first space within the string and while we are not
	at the end of the string, uses that position to find all the rest of the spaces. Then,
	replaces all the spaces with the %20*/
	for(position=String.find(" ");position!=string::npos;position=String.find(" ", position))
	{
		String.replace(position, 1, "%20");
	}

	cout << String << endl;
}

int main()
{
	string String="Why is the rum gone?";

	replaceSpaces(String, String.length());

}