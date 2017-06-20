#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string iterativeSolution(string Input)
{
	size_t inputSize=Input.size();

	string result{};

	int count=1;

	for(int index=0;index<inputSize;++index)
	{
		char current=Input[index];

		char next=Input[index+1];

		if(current==next)
		{
			count++;
		}
		else
		{
			if(count > 1)
			{
				
				result+=(current+to_string(count));
			}
			else
			{
				result+=current;
			}

			count=1;
		}
	}

	return result;
}

string recursiveSolution(string Input, string Compressed, size_t InputSize, int Count, int Index)
{
	if(Index==InputSize)
	{
		return Compressed;
	}

	char current=Input[Index];

	char next=Input[Index+1];

	if(current==next)
	{
		Count++;
	}
	else
	{
		if(Count > 1)
		{
			Compressed+=(current+to_string(Count));
		}
		else
		{
			Compressed+=current;
		}

		Count=1;
	}

	return recursiveSolution(Input, Compressed, InputSize, Count, Index+1);
}

string recursiveSolutionHelper(string Input)
{
	size_t inputSize=Input.size();

	int count=1;

	string compressed{};

	string result=recursiveSolution(Input, compressed, inputSize, count, 0);

	return result;
}