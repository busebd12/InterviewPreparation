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

void findLargestDecentNumber(int N)
{
	string result {};

	for(int j=N;j>=0;--j)
	{
		if(j%3==0 && (n-j)%5==0)
		{
			//add the appropriate number of 5's since j is divisible by three
			for(int i=0;i<j;i++)
			{
				result+='5';
			}

			//add the appropriate number of 3's since we know that the difference (N-j) is divisible by five
			for(int i=0;i<n-j;i++)
			{
				result+='3';
			}

			break;   
		}
	}
	if(result=="")
	{
		cout <<- 1 << endl;
	}
	else
	{
		cout << result << endl;
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

		findLargestDecentNumber(N);
	}
}