#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cstdlib>
using namespace std;

int countRecursive(int N, int K)
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

int countUsingDynamicProgramming(int N, int K)
{
	vector<vector<int>>(N+1, vector<int>(K+1)) dpTable;

	for(int i=0;i<N;++i)
	{
		for(int j=0;j<min(i, K);++j)
		{
			if(i==0 || j==i)
			{
				dpTable[i][j]=1;
			}
			else
			{
				dpTable[i][j]=dpTable[i-1][j-1] + dpTable[i-1][j];
			}
		}
	}

	return dpTable[N][K];
}