#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

string solution(string Input, vector<char> PreviouslySeenCharacters, int Index)
{
	if(Index==Input.size())
	{
		string output(begin(PreviouslySeenCharacters), end(PreviouslySeenCharacters));

		return output;
	}

	char current=Input[Index];

	auto result=find(begin(PreviouslySeenCharacters), end(PreviouslySeenCharacters), current);

	if(result!=end(PreviouslySeenCharacters))
	{
		return solution(Input, PreviouslySeenCharacters, Index+1);
	}
	else
	{
		PreviouslySeenCharacters.emplace_back(current);

		return solution(Input, PreviouslySeenCharacters, Index+1);
	}
}

string solutionHelper(string Input)
{
	vector<char> previouslySeenCharacters;

	string result=solution(Input, previouslySeenCharacters, 0);

	return result;
}