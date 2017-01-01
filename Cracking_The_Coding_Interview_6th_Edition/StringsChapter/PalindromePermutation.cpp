#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;

/*This code goes along with the question: 
Given a string, write a function to check if it is a permutation of a palindrome
*/

bool palindromePermutation(string String)
{
	/*The main logic is as follows: strings with even length must 
	have all even counts of characters. Strings of odd length must have
	exactly one character with an odd count. So, of course, an even length string
	can't have an odd number of exactly one character, otherwise, it would 
	be an even length string. Likewise, a string with odd length can't have 
	all characters with even counts. Therefore, all we need to do to 
	is count how many times there is a character with an odd count, and if
	there are more than one, we know it can't be a permutation of a palindrome
	*/

	transform(String.begin(), String.end(), String.begin(), ::tolower);

	map<char,int> characterCounter;

	/*store each character and its count in a map
	in other terms, we are mapping each character
	in the string to how many times it appears in the string
	*/
	for(int i=0;i<String.length();++i)
	{
		char temp=String[i];

		if(!(isalpha(temp)))
		{
			characterCounter[temp]=-1;
		}
		else
		{
			characterCounter[temp];

			characterCounter[temp]++;
		}
	}

	int oddValueCount=0;

	/*count the number of times there is a 
	character with an odd count
	*/
	for(const auto & element : characterCounter)
	{
		if(element.second==1)
		{
			oddValueCount++;
		}
	}

	/*if the aforementioned count is 1
	then we have a permutation of a palindrome
	if not, then no we don't
	*/
	if(oddValueCount==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	string String="Tact Coa";

	bool result=palindromePermutation(String);

	/*Use boolalpha to print out 0/1 as false/true
	cout << boolalpha << result << endl;
}