#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

string toBinary(uint32_t n)
{
	string binary{};

	while(n > 0)
	{
		if(n%2==0)
		{
			binary='0'+binary;
		}
		else
		{
			binary='1'+binary;
		}

		n/=2;
	}

	return binary;
}

uint32_t toDecimal(string binary)
{
	uint32_t decimal{};

	int power{};

	const size_t binarySize=binary.size();

	for(int index=binarySize-1;index>=0;--index)
	{
		if(binary[index]==1)
		{
			decimal+=pow(2, power);
		}

		++power;
	}

	return decimal;
}

uint32_t reverseBits(uint32_t n)
{
	string binary=toBinary(n);

	if(binary.size() < 32)
	{
		int zerosToAdd=32-binary.size();

		for(int count=0;count<zerosToAdd;++count)
		{
			binary='0'+binary;
		}
	}

	reverse(begin(binary), end(binary));

	uint32_t answer=toDecimal(binary);

	return answer;
}