#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

class OrderOfOperations
{
	public:
		int minTime(vector<string> Commands, int N, int M)
		{
			sort(begin(Commands), end(Commands)); //O(N log N)

			int minimumExecutionTime=numeric_limits<int>::max();

			unordered_set<int> memoryCache;

			do
			{
				int executionTime{};

				for(int command=0;command<N;++command) //O(N)
				{
					int numberOfOnes{};

					for(int index=0;index<M;++index) //O(M)
					{
						if(Commands[command][index]=='1')
						{
							auto result=memoryCache.find(index);

							if(result==end(memoryCache))
							{
								int characterAsNumber=Commands[command][index]-'0';

								memoryCache.emplace(index);

								++numberOfOnes;
							}
						}
					}

					executionTime+=pow(numberOfOnes, 2);
				}

				if(executionTime < minimumExecutionTime)
				{
					minimumExecutionTime=executionTime;
				}

				memoryCache.clear();
			}
			while(next_permutation(begin(Commands), end(Commands))); //O(N)

			return minimumExecutionTime;
		}
};

int main(int argc, char** argv)
{
	OrderOfOperations O;

	/*
	vector<string> commands={"111", "001", "010"};

	int n=3;

	int m=3;

	//returns 3
	*/

	/*
	vector<string> commands={"11101", "00111", "10101", "00000", "11000"};

	int n=5;

	int m=5;

	//Returns: 9
	*/
	
	

	/*
	vector<string> commands={"11111111111111111111"};

	int n=1;

	int m=20;

	//Returns: 400
	*/
	

	/*
	vector<string> commands={"1000", "1100", "1110"};

	int n=3;

	int m=4;

	//Returns: 3
	*/

	/*
	vector<string> commands={"111", "111", "110", "100"};

	int n=4;

	int m=3;

	//Returns: 3
	*/

	cout << O.minTime(commands, n, m) << endl;
}