#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;

/*This code is for the following question from the array and string chapter: 
Implement a method to perform basic string compression using the counts of repeated characters.
For example, the string aabcccccaaa would become a2b1c5a3. If the compressed string would be 
larger than the original string, then your method should return the original string. You can assume
the string only has uppercase and lowercase letters (a-z).
*/

string stringCompression(string String)
{
	deque<int> characterFrequency;

	int counter=0;

	/*need to do String.length()+1 because we want to compare the very last character as well*/
	for(int i=0;i<String.length()+1;++i)
	{
		char current=String[i];

		char previous;

		if(i > 0)
		{
			previous=String[i-1];

			if(current!=previous)
			{
				characterFrequency.emplace_back(counter);

				counter=0;
			}
		}
		
		counter++;
	}
	
	cout << endl;

	string copy=String;

	string compressedString="";

	for(int x=0;x<characterFrequency.size();++x)
	{
		string num=to_string(characterFrequency.at(x));

		string substring=copy.substr(0, 1);

		compressedString+=substring;

		compressedString+=num;

		copy.erase(0, characterFrequency.at(x));
	}

	size_t compressedStringLength=compressedString.length();

	size_t originalStringLength=String.length();

	string stringToReturn;

	if(compressedStringLength > originalStringLength)
	{
		stringToReturn=String;
	}
	else
	{
		stringToReturn=compressedString;
	}

	return stringToReturn;
}

int main()
{
	string String1="aabcccccaaa";

	string String2="aAAbbbc";

	string result1=stringCompression(String1);

	cout << "The result of the string compression function with the string " << String1 << " is: " << result1 << endl;

	cout << endl;

	string result2=stringCompression(String2);

	cout << "The result of the string compression function with the string " << String2 << " is: " << result2 << endl;
}