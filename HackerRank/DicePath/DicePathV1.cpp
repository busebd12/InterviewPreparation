#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
using namespace std;

enum class Direction {Right, Down, Start, End};

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

void printPath(const vector<pair<pair<int, int>, Direction>> & Path)
{
	for(const auto & element : Path)
	{
		cout << "(" << element.first.first << "," << element.first.second << ")" << " ";
	}

	cout << endl;

	cout << endl;
}

void printPaths(const vector<vector<pair<pair<int, int>, Direction>>> & Paths)
{
	cout << "Paths:" << endl;

	for(const auto & path : Paths)
	{
		for(const auto & element : path)
		{
			if(element.second==Direction::Right)
			{
				cout << "Right --> " << "(" << element.first.first << "," << element.first.second << ")" << " ";
			}

			if(element.second==Direction::Down)
			{
				cout << "Down --> " << "(" << element.first.first << "," << element.first.second << ")" << " ";
			}

			if(element.second==Direction::Start)
			{
				cout << "Start --> " << "(" << element.first.first << "," << element.first.second << ")" << " ";
			}

			if(element.second==Direction::End)
			{
				cout << "End --> " << "(" << element.first.first << "," << element.first.second << ")" << " ";
			}
		}

		cout << endl;

		cout << endl;
	}
}

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

int findMaxSumPath(vector<vector<pair<pair<int, int>, Direction>>> Paths)
{
	int maxSumPath{};

	for(auto & path : Paths)
	{
		int sumPath=1;
		
		Die die;

		for(auto & element : path)
		{
			if(element.second==Direction::Right)
			{
				Die rotatedRightDie=rotateDieRight(die);

				sumPath+=rotatedRightDie.topFace;

				die=rotatedRightDie;
			}

			if(element.second==Direction::Down)
			{
				Die rotatedDownDie=rotateDieDown(die);

				sumPath+=rotatedDownDie.topFace;

				die=rotatedDownDie;
			}
		}

		if(sumPath > maxSumPath)
		{
			maxSumPath=sumPath;
		}
	}

	return maxSumPath;
}

vector<vector<pair<pair<int, int>, Direction>>> findPaths(vector<vector<pair<pair<int, int>, Direction>>> & Paths, vector<pair<pair<int, int>, Direction>> Path, pair<int, int> CurrentPoint, pair<int, int> EndPoint, int M, int N)
{
	if(isEndPoint(CurrentPoint, EndPoint))
	{
		Paths.emplace_back(Path);
	}

	pair<int, int> rightPoint;

	pair<int, int> downPoint;

	if(canRollRight(N, CurrentPoint.second) && !canRollDown(M, CurrentPoint.first))
	{
		rightPoint=rollRight(CurrentPoint);

		CurrentPoint.first=rightPoint.first;

		CurrentPoint.second=rightPoint.second;

		pair<pair<int, int>, Direction> pathElement;

		pathElement.first=CurrentPoint;

		pathElement.second=Direction::Right;

		Path.emplace_back(pathElement);
		
		return findPaths(Paths, Path, CurrentPoint, EndPoint, M, N);
	}

	if(canRollDown(M, CurrentPoint.first) && !canRollRight(N, CurrentPoint.second))
	{
		downPoint=rollDown(CurrentPoint);

		CurrentPoint.first=downPoint.first;

		CurrentPoint.second=downPoint.second;

		pair<pair<int, int>, Direction> pathElement;

		pathElement.first=CurrentPoint;

		pathElement.second=Direction::Down;

		Path.emplace_back(pathElement);

		return findPaths(Paths, Path, CurrentPoint, EndPoint, M, N);
	}

	if(canRollRight(N, CurrentPoint.second) && canRollDown(M, CurrentPoint.first))
	{
		//DO ALL THE ROLL RIGHT STUFF
		vector<pair<pair<int, int>, Direction>> rightPath(begin(Path), end(Path));

		pair<int, int> rightRollResult;

		pair<int, int> rightPoint;

		rightRollResult=rollRight(CurrentPoint);

		rightPoint.first=rightRollResult.first;

		rightPoint.second=rightRollResult.second;

		pair<pair<int, int>, Direction> rightPathElement;

		rightPathElement.first=rightPoint;

		rightPathElement.second=Direction::Right;

		rightPath.emplace_back(rightPathElement);

		//DO ALL THE DOWN ROLL STUFF
		vector<pair<pair<int, int>, Direction>> downPath(begin(Path), end(Path));

		pair<int, int> downPoint;

		pair<int, int> downRollResult;

		downRollResult=rollDown(CurrentPoint);

		downPoint.first=downRollResult.first;

		downPoint.second=downRollResult.second;

		pair<pair<int, int>, Direction> downPathElement;

		downPathElement.first=downPoint;

		downPathElement.second=Direction::Down;

		downPath.emplace_back(downPathElement);

		return(findPaths(Paths, rightPath, rightPoint, EndPoint, M, N), findPaths(Paths, downPath, downPoint, EndPoint, M, N));
	}

	return Paths;
}

int findMaxSumPathHelper(int M, int N)
{
	pair<int, int> startingPoint(1, 1);

	pair<int, int> endPoint(M, N);

	Die die;

	vector<pair<pair<int, int>, Direction>> path;

	vector<vector<pair<pair<int, int>, Direction>>> paths;

	path.emplace_back(make_pair(startingPoint, Direction::Start));

	findPaths(paths, path, startingPoint, endPoint, M, N);

	printPaths(paths);

	int maxSumPath=findMaxSumPath(paths);

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