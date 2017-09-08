#include <iostream>
#include <string>
using namespace std;

int toDecimal(string binary)
{
	int base=1;

	int decimal=0;

	const size_t binarySize=binary.size();

	for(int index=binarySize-1;index>=0;--index)
	{
		int digit=binary[index]-'0';

		decimal+=(digit * base);

		base*=2;
	}

	return decimal;
}

string toBinary(int decimal)
{
	string binary{};

	while(decimal > 0)
	{
		if(decimal%2==0)
		{
			binary='0'+binary;
		}
		else
		{
			binary='1'+binary;
		}

		binary/=2;
	}

	return binary;
}

int findComplement(int num)
{
	string binary=toBinary(num);

	const size_t binarySize=binary.size();

	for(int index=binarySize-1;index>=0;--index)
	{
		if(binary[index]=='0')
		{
			binary[index]='1';
		}
		else
		{
			binary[index]='0';
		}
	}

	return toDecimal(binary);
}