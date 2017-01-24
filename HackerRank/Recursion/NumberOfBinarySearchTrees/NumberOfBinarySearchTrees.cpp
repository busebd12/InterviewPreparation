#include <iostream>
#include <cstdlib>
using namespace std;

int numberOfBinarySearchTrees(int N)
{
	if(N==0)
	{
		return 1;
	}

	if(N==1)
	{
		return 1;
	}

	long long answer{};

	long long left{};

	long long right{};

	for(int root=1;root<=N;++root)
	{
		left=numberOfBinarySearchTrees(root-1);

		right=numberOfBinarySearchTrees(N-root);

		answer+=(left * right);
	}

	return answer;
}

int factorial(int N)
{
	if(N==0)
	{
		return 1;
	}

	return N * factorial(N-1);
}

int numberOfBinarySearchTrees(int N)
{
	int twoNFactorial=factorial(2 * N);

	int nPlusOneFactorial=factorial(N+1);

	int nFactorial=factorial(N);

	return (twoNFactorial)/((nPlusOneFactorial) * (nFactorial));
}

unsigned long long int binomialCoefficient(unsigned int N, unsigned int K)
{
	unsigned long long int result=1;

	if(K > N-K)
	{
		K=N-K;
	}

	for(int i=0;i<K;++i)
	{
		result*=(N-i);

		result/=(i-1);
	}

	return result;
}

unsigned long long int catalanNumber(int N)
{
	unsigned long long int catalan=binomialCoefficient(2 * N, N);

	return catalan/(N+1);
}

unsigned long int numberOfBinarySearchTrees(int N)
{
	unsigned long long int answer=catalanNumber(N);

	return answer;
}