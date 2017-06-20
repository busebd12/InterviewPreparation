#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
using namespace std;

struct Die
{
	int topFace;

	int bottomFace;

	int leftFace;

	int rightFace;

	int frontFace;

	int backFace;

	Die()
	{
		topFace=1;

		bottomFace=6;

		leftFace=3;

		rightFace=4;

		frontFace=2;

		backFace=5;
	}

	void operator=(const Die & D)
	{
		topFace=D.topFace;

		bottomFace=D.bottomFace;

		leftFace=D.leftFace;

		rightFace=D.rightFace;

		frontFace=D.frontFace;

		backFace=D.backFace;
	}
};

bool isEndPoint(pair<int, int> Point, pair<int, int> EndPoint)
{
	return (Point.first==EndPoint.first && Point.second==EndPoint.second);
}

bool canRollRight(int N, int Column)
{	
	if(Column < 0 || Column >= N)
	{
		return false;
	}

	return true;
}

bool canRollDown(int M, int Row)
{
	if(Row < 0 || Row >= M)
	{
		return false;
	}

	return true;
}

Die rotateDieRight(Die D)
{
	Die die;

	die.topFace=D.leftFace;

	die.bottomFace=D.rightFace;

	die.leftFace=D.bottomFace;

	die.rightFace=D.topFace;

	die.frontFace=D.frontFace;

	die.backFace=D.backFace;

	return die;
}

Die rotateDieDown(Die D)
{
	Die die;

	die.topFace=D.backFace;

	die.bottomFace=D.frontFace;

	die.leftFace=D.leftFace;

	die.rightFace=D.rightFace;

	die.frontFace=D.topFace;

	die.backFace=D.bottomFace;

	return die;	
}

pair<int, int> rollDown(pair<int, int> CurrentPoint)
{
	pair<int, int> newCurrentPoint;

	newCurrentPoint.first=CurrentPoint.first+1;

	newCurrentPoint.second=CurrentPoint.second;

	return newCurrentPoint;
}

pair<int, int> rollRight(pair<int, int> CurrentPoint)
{
	pair<int, int> newCurrentPoint;

	newCurrentPoint.first=CurrentPoint.first;

	newCurrentPoint.second=CurrentPoint.second+1;

	return newCurrentPoint;
}

int findMaxSumPath(pair<int, int> CurrentPoint, pair<int, int> EndPoint, int M, int N, int Sum, Die CurrentDie)
{
	if(isEndPoint(CurrentPoint, EndPoint))
	{
		return Sum;
	}

	pair<int, int> rightPoint;

	pair<int, int> downPoint;

	if(canRollRight(N, CurrentPoint.second) && !canRollDown(M, CurrentPoint.first))
	{
		Die rightDie;

		rightPoint=rollRight(CurrentPoint);

		CurrentPoint.first=rightPoint.first;

		CurrentPoint.second=rightPoint.second;

		rightDie=rotateDieRight(CurrentDie);

		Sum+=rightDie.topFace;
		
		return findMaxSumPath(CurrentPoint, EndPoint, M, N, Sum, rightDie);
	}

	if(canRollDown(M, CurrentPoint.first) && !canRollRight(N, CurrentPoint.second))
	{
		Die downDie;

		downPoint=rollDown(CurrentPoint);

		CurrentPoint.first=downPoint.first;

		CurrentPoint.second=downPoint.second;

		downDie=rotateDieDown(CurrentDie);

		Sum+=downDie.topFace;

		return findMaxSumPath(CurrentPoint, EndPoint, M, N, Sum, downDie);
	}

	if(canRollRight(N, CurrentPoint.second) && canRollDown(M, CurrentPoint.first))
	{
		//DO ALL THE ROLL RIGHT STUFF
		int rightSum=Sum;

		Die rightDie;

		rightPoint=rollRight(CurrentPoint);

		rightDie=rotateDieRight(CurrentDie);

		rightSum+=rightDie.topFace;

		//DO ALL THE DOWN ROLL STUFF
		int downSum=Sum;

		Die downDie;

		downPoint=rollDown(CurrentPoint);

		downDie=rotateDieDown(CurrentDie);

		downSum+=downDie.topFace;

		return max(findMaxSumPath(rightPoint, EndPoint, M, N, rightSum, rightDie), findMaxSumPath(downPoint, EndPoint, M, N, downSum, downDie));
	}
}

int findMaxSumPathHelper(int M, int N)
{
	pair<int, int> startingPoint(1, 1);

	pair<int, int> endPoint(M, N);

	int sum=1;

	Die die;

	int maxSumPath=findMaxSumPath(startingPoint, endPoint, M, N, sum, die);

	return maxSumPath;
}

int main(int argc, char** argv)
{
	/*
	int m=2;

	int n=2;

	//returns 9
	*/
	

	/*
	int m=1;

	int n=2;

	//returns 4
	*/
	
	

	/*
	int m=2;

	int n=1;

	//returns 6
	*/
	
	

	/*
	int m=3;

	int n=3;

	//returns 19
	*/
	
	

	cout << findMaxSumPathHelper(m, n) << endl;
}