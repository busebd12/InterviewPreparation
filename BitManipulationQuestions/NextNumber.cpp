#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <numeric>
#include <map>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <sstream>
using namespace std;

/*Given a positive number, print the next smallest and largest number that have the same number of 1 bits in their binary representaiton*/

string getBinaryRepresentation(const int Number)
{
	bitset<8> b=Number;

	return b.to_string();
}

int printNextAndPrevious(int Number)
{
	string current=getBinaryRepresentation(Number);

	int next=Number;

	int previous=Number;

	int numberOfOnesInCurrentNumber=count_if(begin(current), end(current), [] (const auto & element) {return element=='1';});

	int numberOfOnesInPreviousNumber=0;

	int numberOfOnesInNextNumber=0;

	int greaterThan;

	int lessThan;

	while(numberOfOnesInPreviousNumber!=numberOfOnesInCurrentNumber)
	{
		previous=previous-1;

		string previousAsString=getBinaryRepresentation(previous);

		//cout << "The binary representation of the given number " << Number << " is " << current << endl;

		//cout << "The binary representation of the next number less than  " << Number << ", " << previous << ", "<< "is " << previousAsString << endl;

		numberOfOnesInPreviousNumber=count_if(begin(previousAsString), end(previousAsString), [] (const auto & element) {return element=='1';});

		cout << "The number of ones in " << previous << " is " << numberOfOnesInPreviousNumber << ", and the number of ones in " << Number << " is " << numberOfOnesInCurrentNumber << endl;

		lessThan=previous;	
	}

	cout << endl;

	cout << endl;

	while(numberOfOnesInNextNumber!=numberOfOnesInCurrentNumber)
	{
		next=next+1;

		string nextAsString=getBinaryRepresentation(next);

		//cout << "The binary representation of " << Number << " is " << current << endl;

		//cout << "The binary representation of the next number greater than  " << Number << ", " << next << ", "<< "is " << nextAsString << endl;

		numberOfOnesInNextNumber=count_if(begin(nextAsString), end(nextAsString), [] (const auto & element) {return element=='1';});

		cout << "The number of ones in " << next << " is " << numberOfOnesInNextNumber << ", and the number of ones in " << Number << " is " << numberOfOnesInCurrentNumber << endl;

		greaterThan=next;
	}

	cout << endl;

	cout << "The number greater than " << Number << " that has the same number of ones is " << greaterThan << endl;

	cout << endl;

	cout << "The number less than " << Number << " that has the same number of ones is " << lessThan << endl;

	return 0;
}

int main()
{
	int number=56;

	printNextAndPrevious(number);
}