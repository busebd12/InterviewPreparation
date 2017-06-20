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

int findMaxSumPath(int M, int N)
{
	Die die;

	vector<Die> previouslyRotatedDice;

	previouslyRotatedDice.emplace_back(die);

	pair<int, int> currentPoint(1,1);

	pair<int, int> endPoint(M, N);

	int maxSumPath=1;

	while(true)
	{
		cout << "Current point: " << "(" << currentPoint.first << "," << currentPoint.second << ")" << endl;

		cout << endl;

		if(isEndPoint(currentPoint, endPoint))
		{
			break;
		}

		size_t previouslyRotatedDiceSize=previouslyRotatedDice.size();

		if(canRollDown(M, currentPoint.first) && !canRollRight(N, currentPoint.second))
		{
			cout << "We can roll down!" << endl;

			cout << endl;

			Die rotatedDownDie=rotateDieDown(previouslyRotatedDice[previouslyRotatedDiceSize-1]);

			cout << "Going to add " << rotatedDownDie.topFace << " to the sum" << endl;

			cout << endl;

			maxSumPath+=rotatedDownDie.topFace;

			previouslyRotatedDice.emplace_back(rotatedDownDie);

			currentPoint.first+=1;
		}

		if(canRollRight(N, currentPoint.second) && !canRollDown(M, currentPoint.first))
		{
			cout << "We can roll right!" << endl;

			cout << endl;

			Die rotatedRightDie=rotateDieRight(previouslyRotatedDice[previouslyRotatedDiceSize-1]);

			cout << "Going to add " << rotatedRightDie.topFace << " to the sum" << endl;

			cout << endl;

			maxSumPath+=rotatedRightDie.topFace;

			previouslyRotatedDice.emplace_back(rotatedRightDie);

			currentPoint.second+=1;
		}

		if(canRollDown(M, currentPoint.first) && canRollRight(N, currentPoint.second))
		{
			cout << "We can roll down and right!" << endl;

			cout << endl;

			Die right=previouslyRotatedDice[previouslyRotatedDiceSize-1];

			Die down=previouslyRotatedDice[previouslyRotatedDiceSize-1];

			Die rotatedDownDie=rotateDieDown(right);

			Die rotatedRightDie=rotateDieRight(down);

			if(rotatedRightDie.topFace > rotatedDownDie.topFace)
			{
				cout << "Choose to go with right" << endl;

				cout << endl;

				maxSumPath+=rotatedRightDie.topFace;

				cout << "Going to add " << rotatedRightDie.topFace << " to the sum" << endl;

				cout << endl;					

				previouslyRotatedDice.emplace_back(rotatedRightDie);

				currentPoint.second+=1;
			}

			if(rotatedDownDie.topFace > rotatedRightDie.topFace)
			{
				cout << "Choose to go down" << endl;

				cout << endl;

				cout << "Going to add " << rotatedDownDie.topFace << " to the sum" << endl;

				cout << endl;

				maxSumPath+=rotatedDownDie.topFace;

				previouslyRotatedDice.emplace_back(rotatedDownDie);

				currentPoint.first+=1;
			}

			if(rotatedDownDie.topFace==rotatedRightDie.topFace)
			{
				maxSumPath+=rotatedRightDie.topFace;

				previouslyRotatedDice.emplace_back(rotatedRightDie);

				currentPoint.second+=1;
			}
		}
	}

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
	
	

	
	int m=3;

	int n=3;

	//returns 19
	
	
	

	cout << findMaxSumPath(m, n) << endl;
}