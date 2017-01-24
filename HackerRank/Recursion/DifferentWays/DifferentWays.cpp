#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cstdlib>
using namespace std;

int count(int N, int K)
{
	if(K==0)
	{
		return 1;
	}

	if(K==N)
	{
		return 1;
	}

	//count(N-1, K-1) --> select the first lemur and then select (K-1) lemurs from the remaining (N-1) lemurs
	//count(N-1, K) --> Don't select the first lemur. So, you have K lemurs left to select from the remaining (N-1) lemurs
	return count(N-1, K-1) + count(N-1, K);
}