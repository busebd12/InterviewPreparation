#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

int solution(string P, string Q, int S)
{
	int n=P.size();

	int maxLength{};

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			int mismatches{};

			for(int k=0;k<i+k<n && j+k<n;++k)
			{
				if(P[i+k]!=Q[j+k])
				{
					mismatches++;
				}

				if(mismatches <= S)
				{
					maxLength=max(maxLength, k+2);
				}
			}
		}
	}

	return maxLength;
}

int main(int argc, char* argv[])
{
	/*
	string p="tabriz";

	string q="torino";

	int s=2;
	*/


	string p="abacba";

	string q="abcaba";

	int s=0;
	

	/*
	string p="helloworld";

	string q="yellomarin";

	int s=3;
	*/

	cout << solution(p, q, s) << endl;

	/*
	int testCases;

	cin >> testCases;

	for(int count=0;count<testCases;++count)
	{
		int S;

		string P;

		string Q;

		cin >> S;

		cin >> P;

		cin >> Q;

		cout << solution(P, Q, S) << endl;
	}
	*/
	
}