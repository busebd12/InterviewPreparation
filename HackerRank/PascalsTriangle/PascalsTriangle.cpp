#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

unsigned int factorial(unsigned int N)
{
	if(N==0)
	{
		return 1;
	}
	else
	{
		return N*factorial(N-1);
	}
}

unsigned int binomial(unsigned int N, unsigned int K)
{
	return factorial(N)/(factorial(K)*factorial(N-K));
}

void pascalsTriangle(unsigned int N)
{
	vector<unsigned int> result;

	for(unsigned int k=0;k<=N;++k)
	{
		result.emplace_back(binomial(N, k));
	}

	copy(begin(result), end(result), ostream_iterator<unsigned int>(cout, " "));

	cout << endl;
}