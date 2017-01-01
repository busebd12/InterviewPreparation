#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string solution(string String, size_t N, int Index)
{
	if(Index==N)
	{
		return String;
	}

	swap(String[Index], String[Index+1]);

	return solution(String, N, Index+2);
}