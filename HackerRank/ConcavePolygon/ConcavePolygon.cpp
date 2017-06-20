#include <iostream>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;

float calculateAngle(pair<int, int> FirstPoint, pair<int, int>SecondPoint)
{
	const float pi=acos(-1);

	float angle=atan2(FirstPoint.second-SecondPoint.second, FirstPoint.first-SecondPoint.first);

	angle=angle*(180/pi);

	return angle;
}

int solution(vector<pair<int, int>> Points, size_t PointsSize, int Current, int Next, int Count)
{
	if(Next==PointsSize)
	{
		float angle=calculateAngle(Points[0], Points[PointsSize-1]);

		if(angle > 180)
		{
			++Count;
		}

		return Count;
	}

	float angle=calculateAngle(Points[Current], Points[Next]);

	if(angle > 180)
	{
		++Count;
	}

	return solution(Points, PointsSize, Current+1, Next+1, Count);
}

string solutionHelper(vector<pair<int, int>> Points)
{
	const string no="NO";

	const string yes="YES";

	size_t pointsSize=Points.size();

	if(pointsSize <= 3)
	{
		return no;
	}

	int count{};

	int current{};

	int next{};

	int result=solution(Points, pointsSize, current, next, count);

	if(result >= 1)
	{
		return yes;
	}
	else
	{
		return no;
	}
}