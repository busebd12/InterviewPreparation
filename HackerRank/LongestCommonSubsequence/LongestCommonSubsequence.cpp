#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;

void printLCS(const vector<int> & FirstSequence, const vector<int> & SecondSequence, int N, int M)
{
	vector<vector<int>> matrix(N+1, vector<int>(M+1));

	vector<vector<string>> solutionPath(N+1, vector<string>(M+1));

	for(int index=0;index<N+1;++index)
	{
		for(int innerIndex=0;innerIndex<M+1;++innerIndex)
		{
			solutionPath[index][innerIndex]="0";
		}
	}

	for(int deez=1;deez<N+1;++deez)
	{
		for(int nuts=1;nuts<M+1;++nuts)
		{
			if(FirstSequence[deez-1]==SecondSequence[nuts-1])
			
				matrix[deez][nuts]=matrix[deez-1][nuts-1] + 1;

				solutionPath[deez][nuts]="diagonal";
			}
			else
			{
				matrix[deez][nuts]=max(matrix[deez-1][nuts], matrix[deez][nuts-1]);

				if(matrix[deez][nuts]==matrix[deez-1][nuts])
				{
					solutionPath[deez][nuts]="up";
				}
				else
				{
					solutionPath[deez][nuts]="left";
				}
			}
		}
	}

	string current=solutionPath[N][M];

	string longestCommonSubstring {};

	int deez=N;

	int nuts=M;

	while(current!="0")
	{
		if(solutionPath[deez][nuts]=="diagonal")
		{
			longestCommonSubstring+=to_string(FirstSequence[deez-1]);

			--deez;

			--nuts;
		}
		else if(solutionPath[deez][nuts]=="left")
		{
			--nuts;
		}
		else if(solutionPath[deez][nuts]=="up")
		{
			--deez;
		}

		current=solutionPath[deez][nuts];
	}

	copy(crbegin(longestCommonSubstring), crend(longestCommonSubstring), ostream_iterator<char>(cout, " "));

	cout << endl;
}

int main(int argc, char* argv[])
{
	int N;

	int M;

	cin >> N >> M:

	vector<int> firstSequence;

	vector<int> secondSequence;

	for(int count=0;count<N;++count)
	{
		int value;

		cin >> value;

		firstSequence.emplace_back(value);
	}

	for(int counter=0;counter<M;++counter)
	{
		int value;

		cin >> value;

		secondSequence.emplace_back(value);
	}

	printLCS(firstSequence, secondSequence, firstSequence.size(), secondSequence.size());

	firstSequence.clear();

	secondSequence.clear();
}