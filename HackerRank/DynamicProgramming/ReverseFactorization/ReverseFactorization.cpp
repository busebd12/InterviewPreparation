#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getPath(vector<int> Divisors)
{
	vector<int> path={1};

	int number=1;

	for(int index=0;index<Divisors.size();++index)
	{
		number*=Divisors[index];

		path.emplace_back(number);
	}

	return path;
}

vector<int> reverseFactorization(int N, int Index, vector<int> Factors, vector<int> Divisors)
{
	if(N==1)
	{
		return Factors;
	}

	int currentDivisor=Divisors[Index];

	if(N % currentDivisor==0)
	{
		Factors.emplace_back(currentDivisor);

		N/=currentDivisor;
	}

	return reverseFactorization(N, Index+1, Factors, Divisors);
}

void reverseFactorizationHelper(int N, vector<int> Divisors)
{
	auto startOfRemovedDivisors=remove_if(begin(Divisors), end(Divisors), [N] (const auto & divisor) {return N % divisor!=0;});

	Divisors.erase(startOfRemovedDivisors, end(Divisors));

	sort(begin(Divisors), end(Divisors), greater<int>());

	if(Divisors.empty())
	{
		cout << -1 << endl;

		return;
	}

	int startIndex=0;

	vector<int> factors;

	factors=reverseFactorization(N, startIndex, factors, Divisors);

	reverse(begin(factors), end(factors));

	vector<int> path=getPath(factors);

	copy(begin(path), end(path), ostream_iterator<int>(cout, " "));

	cout << endl;
}