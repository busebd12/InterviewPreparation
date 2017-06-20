#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <deque>
#include <numeric>
#include <utility>
#include <type_traits>
#include <cmath>
using namespace std;

//naive, recursive solution --> O(2^n) complexity
int makeChange(vector<int> Coins, int M, int N)
{	
	/*no way to make change for a negative amount*/
	if(N < 0)
	{
		return 0;
	}

	/*only one way to make change for zero cents*/
	if(N==0)
	{
		return 1;
	}

	/*no ways to make change if we don't have any coins to begin with*/
	if(N >= 1 && M <=0)
	{
		return 0;
	}

	//return sum of solutions including the Coins[M-1] coin and the solutions excluding the Coins[M-1] coin
	return makeChange(Coins, M-1, N) + makeChange(Coins, M, N-Coins[M-1]);
}

int makeChangeDynamic(vector<int> Coins, int M, int N)
{
	//table we will use for the bottom-up dynamic programming approach
	vector<vector<int>> table;

	table.resize(N+1, vector<int>(M));

	//fill the entries for n=0 base case
	for(int index=0;index<M;++index)
	{
		table[0][index]=1;
	}

	//fill the rest of the table in a bottom up manner
	//start x at one because we have already taken
	//care of the zero case in the above for loop
	for(int x=1;x<N+1;++x)
	{
		for(int y=0;y<M;++y)
		{
			//count the number of solutions including the Coins[y] coin
			int included=(x-Coins[y] >= 0) ? table[x-Coins[y]][y]: 0;

			//count the number of solutions excluding the Coins[y] coin
			int excluded=(y >= 1) ? table[x][y-1]: 0;

			//fill table entry to be retrieved later
			table[x][y]=included+excluded;
		}
	}

	return table[N][M-1];
}

int main(int argc, char* argv [])
{
	int n=10;

	int m=4;

	vector<int> coins={2, 5, 3, 6};

	/*
	int n;

	int m;

	int coin;

	vector<int> coins;

	cin >> targetSum >> numberOfCoins;

	for(int counter=0;counter<numberOfCoins;++counter)
	{
		cin >> coin;

		coins.push_back(coin);
	}
	*/

	//int answer=makeChange(coins, m, n);

	int dynamicAnswer=makeChangeDynamic(coins, m, n);

	cout << dynamicAnswer << endl;
}