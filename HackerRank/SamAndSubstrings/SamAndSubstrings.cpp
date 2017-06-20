#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <cmath>
#include <numeric>
#include <deque>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<int, int> populateIndexMap(string Input)
{
	unordered_map<int, int> indexMap;

	for(int index=0;index<Input.size();++index)
	{
		indexMap.insert({Input.at(index)-'0', index});
	}

	for(const auto & element : indexMap)
	{
		cout << element.first << " --> " << element.second << endl;
	}

	return indexMap;
}

deque<string> solutionHelper(string Input, int Index, int InputSize, unordered_map<int, int> IndexMap)
{
	deque<string> substrings;

	if(InputSize==Index)
	{
		//cout << "In the base case" << endl;

		//cout << "size of string: " << InputSize << " and Index: " << Index << endl;

		//base case --> empty substring
		string emptyString {};

		substrings.emplace_back(emptyString);

	}
	else
	{
		//the idea is this: since every substring is just a clone of the previous substring plus the next element we want to add,
		//we simply make a clone of each previous subset and add the current element the index points to and then add that new subset to our collections of subsets
		deque<string> substringsSoFar=solutionHelper(Input, Index+1, InputSize, IndexMap);

		int number=Input.at(Index)-'0';

		for(int current=0;current<substringsSoFar.size();++current)
		{
			string currentSubstring=substringsSoFar.at(current);

			copy(begin(currentSubstring), end(currentSubstring), ostream_iterator<char>(cout, " "));

			cout << endl;

			substrings.emplace_back(currentSubstring);

			string newSubstring=to_string(number) + currentSubstring;

			copy(begin(currentSubstring), end(currentSubstring), ostream_iterator<char>(cout, " "));

			cout << endl;

			substrings.emplace_back(newSubstring);

			/*
			if(currentSubstring.size()!=0)
			{
				int firstCharacter=currentSubstring.front()-'0';

				if(IndexMap[firstCharacter] - IndexMap[number]==1)
				{
					string newSubstring=to_string(number) + currentSubstring;

					substrings.emplace_back(newSubstring);	
				}
			}
			else
			{
				string newSubstring=to_string(number) + currentSubstring;

				substrings.emplace_back(newSubstring);
			}
			*/
		}
	}

	return substrings;
}

long long solution(deque<string> Substrings)
{
	/*
	cout << "All substrings: " << endl;

	for(const auto & substring : Substrings)
	{
		copy(begin(substring), end(substring), ostream_iterator<char>(cout, " "));

		cout << endl;
	}
	*/

	long long sum {};

	for(const auto & substring : Substrings)
	{
		if(substring.size() > 0)
		{
			sum+=static_cast<long long>(stoll(substring));
		}
	}

	int modValue=(pow(10, 9) + 7); 

	return static_cast<long long>(sum % modValue);
}

int main(int argc, char* argv [])
{
	//string input="16";

	//string input="123";

	string input="972698438521";

	int index=0;

	deque<string> substrings;

	auto indexMap=populateIndexMap(input);

	substrings=solutionHelper(input, index, input.size(), indexMap);

	cout << solution(substrings) << endl;

	/*
	int number;

	cin >> number;

	string input=to_string(number);

	auto indexMap=populateIndexMap(input);

	deque<string> substrings=solutionHelper(input, 0, input.size(), indexMap);

	cout << solution(substrings) << endl;
	*/
}