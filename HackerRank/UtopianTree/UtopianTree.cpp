#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <list>
#include <tuple>
#include <utility>
#include <cmath>
#include <string>
using namespace std;

void numberOfGrowthCycles(int N)
{
	int height=1;

	if(N==0)
	{
		cout << height << endl;
	}
	else
	{
		for(int count=0;count<N;++count)
		{
			//spring; height doubles
			if(count%2==0)
			{
				height+=height;
			}
			//summer; height increases only by one
			else
			{
				height+=1;
			}
		}

		cout << height << endl;
	}	
}

int main(int argc, char* argv [])
{
	int numberOfLoops;

	int N;
	
	cin >> numberOfLoops;

	for(int count=0;count<numberOfLoops;++count)
	{
		cin >> N;

		numberOfGrowthCycles(N);
	}
}