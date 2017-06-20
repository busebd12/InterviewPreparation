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
#include <type_traits>
using namespace std;

void countSquares(int Start, int End)
{
	int numberOfSquares {};

	for(int number=Start;number<=End;++number)
	{
		if(!isPrime(number))
		{
			int floorOfSquareRoot=floor(sqrt(number));

			if(floorOfSquareRoot==sqrt(number))
			{
				numberOfSquares++;
			}	
		}
	}

	cout << numberOfSquares << endl;
}

int main(int argc, char* argv [])
{
	int numberOfLoops;

	int start;

	int end;

	cin >> numberOfLoops;

	for(int count=0;count<numberOfLoops;++count)
	{
		cin >> start;

		cin >> end;

		countSquares(start, end);
	}
}