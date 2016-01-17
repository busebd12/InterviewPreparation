#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <numeric>
#include <map>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

bool isPowerOfTwo(int Number)
{
	while(Number%2==0 && Number > 1)
	{
		Number/=2;
	}

	return (Number==1);
}

int doubleToInt(double Input)
{
	ostringstream strs;

	strs << Input;

	//cout << strs.str() << endl;

	string doubleAsString=strs.str();

	//cout << doubleAsString << endl;

	auto positionOfDecimalPoint=doubleAsString.find(".");

	string justNumberPart=doubleAsString.substr(++positionOfDecimalPoint);

	//cout << justNumberPart << endl;

	int number=stoi(justNumberPart);

	//cout << number << endl;

	return number;
}

int getPowerOfTwoForOdds(const int Number, map<int, int> & Map)
{
	int k=1;

	int exponent=0;

	bool mapAlreadyFilled=false;

	while(k < Number)
	{
		if(k*2 > Number)
		{
			if(mapAlreadyFilled==false)
			{
				Map[exponent];

				for(int i=0;i<exponent;++i)
				{
					Map[i];
				}
			}

			Map[exponent]++;

			break;
		}

		//cout << "Exponent: " << exponent << endl;

		//cout << "k: " << k << endl;

		k*=2;

		exponent++;
	}

	/*
	cout << "Map in the getPowerOfTwo function" << endl;

	for(const auto & element : Map)
	{
		cout << element.first << " -> " << element.second << endl;
	}
	*/

	return k;	
}

int getPowerOfTwoForEvens(const int Number, map<int, int> & Map)
{
	int k=1;

	int exponent=0;

	bool mapAlreadyFilled=false;

	if(isPowerOfTwo(Number)==true)
	{
		//cout << Number << " is a power of two" << endl;

		while(k!=Number)
		{
			k*=2;
			
			exponent++;		
		}

		for(int i=0;i<exponent;++i)
		{
			Map[i];
		}

		Map[exponent]++;
	}
	else
	{
		//cout << Number << " is not a power of two" << endl;

		while(k < Number)
		{
			if((k*2) > Number)
			{
				//cout << "exponent: " << exponent << endl;

				//cout << "Number: " << Number << endl;

				//cout << "k: " << k << endl;

				//cout << Number-k << endl;

				if(mapAlreadyFilled==false)
				{
					Map[exponent];

					for(int i=0;i<exponent;++i)
					{
						Map[i];
					}
				}

				Map[exponent]++;

				break;
			}

			//cout << "k: " << k << endl;

			k*=2;

			exponent++;
		}
	}

	/*
	cout << "Map in the getPowerOfTwoForEvens function" << endl;

	for(const auto & element : Map)
	{
		cout << element.first << " -> " << element.second << endl;
	}
	*/

	//cout << k << endl;

	return k;	
}

void printString(const map<int, int> & Map)
{
	string result {};

	for(const auto & digit : Map)
	{
		result+=to_string(digit.second);
	}

	if(result.size() > 32)
	{
		cout << "ERROR" << endl;
	}
	else
	{
		reverse(result.begin(), result.end());

		cout << result << endl;
	}
}

void binaryToString(double Input)
{
	map<int, int> powersOfTwoMap;

	auto convertedDouble=doubleToInt(Input);

	if(convertedDouble%2==1)
	{
		//cout << convertedDouble << " is an odd number" << endl;

		while(convertedDouble!=1)
		{
			int chunk=getPowerOfTwoForOdds(convertedDouble, powersOfTwoMap);

			convertedDouble-=chunk;
		}

		powersOfTwoMap[0]++;

		/*
		cout << "Map in the binaryToStringFunction" << endl;

		for(const auto & element : powersOfTwoMap)
		{
			cout << element.first << " -> "	<< element.second << endl;	
		}
		*/
	}
	else
	{
		//cout << convertedDouble << " is an even number" << endl;

		while(convertedDouble!=0)
		{
			int chunk=getPowerOfTwoForEvens(convertedDouble, powersOfTwoMap);

			//cout << "Chunk: " << chunk << endl;

			convertedDouble-=chunk;

			//cout << convertedDouble << endl;
		}

		/*
		cout << "Map in the binaryToStringFunction" << endl;

		for(const auto & element : powersOfTwoMap)
		{
			cout << element.first << " -> "	<< element.second << endl;	
		}
		*/
	}

	printString(powersOfTwoMap);
}

int main()
{

	binaryToString(0.75);

	binaryToString(0.64);

	binaryToString(0.88);
}