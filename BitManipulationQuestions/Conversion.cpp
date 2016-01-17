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

/*Wrtite a function to determine the number of bits you would need to flip to convert integer A to integer B*/

string getBinaryRepresentation(const int Number)
{
	bitset<8> b=Number;

	return b.to_string();
}

void numberOfBits(int A, int B)
{
	string AInBinary=getBinaryRepresentation(A);

	string BInBinary=getBinaryRepresentation(B);

	/*mismatch is a function provided by the STL that finds the first mismatch between two ranges*/
	auto Mismatch=mismatch(AInBinary.begin(), AInBinary.end(), BInBinary.begin());

	int numberOfBitsToFlip=0;

	while(Mismatch.first!=end(AInBinary))
	{
		//cout << *Mismatch.first << endl;

		//cout << *Mismatch.second << endl;

		Mismatch=mismatch(++Mismatch.first, end(AInBinary), ++Mismatch.second);

		numberOfBitsToFlip++;
	}

	cout << endl;

	cout << "The number of bits you needed to flip is " << numberOfBitsToFlip << endl;
}

int main()
{
	numberOfBits(10, 11);

	numberOfBits(29, 15);
}