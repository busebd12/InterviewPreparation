#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int solution(string Input, size_t InputSize)
{
	if(InputSize==1)
	{
		return stoi(Input);
	}

	int number{};

	for(int index=0;index<InputSize;++index)
	{
		number+=Input[index]-'0';
	}

	string numberAsString=to_string(number);

	size_t numberSize=numberAsString.size();

	return solution(numberAsString, numberSize);
}

int solutionHelper(int N, int K)
{
	string input{};

	for(int count=0;count<K;++count)
	{
		input+=to_string(N);
	}

	size_t inputSize=input.size();

	int superDigit=solution(input, inputSize);

	return superDigit;
}