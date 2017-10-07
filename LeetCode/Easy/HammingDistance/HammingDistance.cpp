#include <iostream>
#include <string>
using namespace std;

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
			binary='1'+binary
		}

		binary/=2;
	}
}

int hammingDistance(int x, int y)
{
	if(x==0 && y==0)
	{
		return 0;
	}

	string xBinary{};

	string yBinary{};

	size_t xBinarySize=0;

	size_t yBinarySize=0;

	int count=0;

	if(x==0 && y!=0)
	{
		yBinary=toBinary(y);

		yBinarySize=yBinary.size();

		for(int index=0;index<yBinarySize;++index)
		{
			if(yBinary[index]!='0')
			{
				++count;
			}
		}
	}
	else if(x!=0 && y==0)
	{
		xBinary=toBinary(x);

		xBinarySize=xBinary.size();

		for(int index=0;index<xBinarySize;++index)
		{
			if(xBinary[index]!='0')
			{
				++count;
			}
		}
	}
	else
	{
		xBinary=toBinary(x);

		yBinary=toBinary(y);

		if(xBinary.size() < yBinary.size())
		{
			int difference=yBinary.size()-xBinary.size();

			for(int count=0;count<difference;++count)
			{
				xBinary='0'+xBinary;
			}
		}
		else if(yBinary.size() < xBinary.size())
		{
			int difference=xBinary.size()-yBinary.size();

			for(int count=0;count<difference;++count)
			{
				yBinary='0'+yBinary;
			}
		}

		int i=0;

		int j=0;

		xBinarySize=xBinary.size();

		yBinarySize=yBinary.size();

		while(i < xBinarySize && j < yBinarySize)
		{
			if(xBinary[i]!=yBinary[j])
			{
				++count;
			}

			++i;

			++j;
		}

		return count;
	}
}