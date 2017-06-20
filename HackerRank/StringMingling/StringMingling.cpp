#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string solution(string P, string Q, string Mingled, size_t N, int Index)
{
	if(Index==N)
	{
		return Mingled;
	}

	Mingled.push_back(P[Index]);

	Mingled.push_back(Q[Index]);

	return solution(P, Q, Mingled, N, Index+1);
}

string solutionHelper(string P, string Q)
{
	size_t n=P.size();

	string mingled;

	mingled.reserve(2*n);

	string R=solution(P, Q, mingled, n, 0);

	return R;
}