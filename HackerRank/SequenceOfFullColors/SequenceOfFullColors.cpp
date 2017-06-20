#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

bool prefixConditionsSatisfied(string Sequence, int PrefixesThatPass, int Offset, int SequenceSize)
{
	if(Offset==SequenceSize)
	{
		return (PrefixesThatPass==Offset) ? true : false;
	}

	int redBalls{};

	int blueBalls{};

	int greenBalls{};

	int yellowBalls{};

	for(int current=SequenceSize-Offset;current >= 0;--current)
	{
		char ball=Sequence[current];

		if(ball=='R')
		{
			++redBalls;
		}
		if(ball=='B')
		{
			++blueBalls;
		}
		if(ball=='G')
		{
			++greenBalls;
		}
		if(ball=='Y')
		{
			++yellowBalls;
		}
	}

	bool correctRedAndGreenDifference=(redBalls-greenBalls <= 1) ? true : false;

	bool correctBlueAndYellowDifference=(yellowBalls-blueBalls <= 1) ? true : false;

	if(correctRedAndGreenDifference && correctBlueAndYellowDifference)
	{
		++PrefixesThatPass;
	}

	return prefixConditionsSatisfied(Sequence, PrefixesThatPass, Offset+1, SequenceSize);
}

bool sameNumberOfBlueBallsAsYellowBalls(string Sequence, int BlueBalls, int YellowBalls, int SequenceSize, int Index)
{
	if(Index==SequenceSize)
	{
		return (BlueBalls==YellowBalls) ? true : false;
	}

	char ball=Sequence[Index];

	if(ball=='B')
	{
		++BlueBalls;
	}
	if(ball=='Y')
	{
		++YellowBalls;
	}

	return sameNumberOfBlueBallsAsYellowBalls(Sequence, BlueBalls, YellowBalls, SequenceSize, Index+1);
}

bool sameNumberOfRedBallsAsGreenBalls(string Sequence, int RedBalls, int GreenBalls, int SequenceSize, int Index)
{
	if(Index==SequenceSize)
	{
		return (RedBalls==GreenBalls) ? true : false;
	}

	char ball=Sequence[Index];

	if(ball=='R')
	{
		++RedBalls;
	}
	if(ball=='G')
	{
		++GreenBalls;
	}

	return sameNumberOfRedBallsAsGreenBalls(Sequence, RedBalls, GreenBalls, SequenceSize, Index+1);
}

bool solution(string Sequence)
{
	size_t sequenceSize=Sequence.size();

	int redBalls{};

	int blueBalls{};

	int greenBalls{};

	int yellowBalls{};

	bool redBallsAndGreenBallsEqual=sameNumberOfRedBallsAsGreenBalls(Sequence, redBalls, greenBalls, sequenceSize, 0);

	bool blueBallsAndYellowBallsEqual=sameNumberOfBlueBallsAsYellowBalls(Sequence, blueBalls, yellowBalls, sequenceSize, 0);

	int prefixesThatPass{};

	int offset{};

	bool allPrefixesPass=prefixConditionsSatisfied(Sequence, prefixesThatPass, offset, sequenceSize);

	return (redBallsAndGreenBallsEqual && blueBallsAndYellowBallsEqual && allPrefixesPass) ? true : false;
}
