#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <list>
#include <tuple>
#include <utility>
#include <cmath>
using namespace std;

void isClassCancelled(int CancellationThreshold, vector<int> StudentArrivalTimes)
{
	int nonLateStudents=count_if(StudentArrivalTimes.begin(), StudentArrivalTimes.end(), [] (const auto & time) {return time <= 0;});

	if(nonLateStudents < CancellationThreshold)
	{
		cout << "YES" << end
	}
	else
	{
		cout << "NO" << endl;
	}
}

int main(int argc, char * argv [])
{
	int numberOfStudents;

	int cancellationThreshold;

	int numberOfLoops;

	vector<int> studentArrivalTimes;

	cin >> numberOfLoops;

	for(int count=0;count<numberOfLoops;++count)
	{
		cin >> numberOfStudents;

		cin >> cancellationThreshold;

		for(int start=0;start<numberOfStudents;++start)
		{
			int temp;

			cin >> temp;

			studentArrivalTimes.push_back(temp);
		}

		isclassCancelled(cancellationThreshold, studentArrivalTimes);
	}
}