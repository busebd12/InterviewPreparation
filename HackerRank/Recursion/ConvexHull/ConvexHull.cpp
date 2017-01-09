#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

void printVector(const vector<pair<int, int>> & Points)
{
	for(const auto & point : Points)
	{
		cout << "(" << point.first << "," << point.second << ")" << " ";
	}

	cout << endl;

	cout << endl;
}

float calculateDistance(pair<int, int> First, pair<int, int> Second)
{
	float xComponent=(Second.first-First.first)*(Second.first-First.first);

	float yComponent=(Second.second-First.second)*(Second.second-First.second);

	float distance=sqrt(xComponent+yComponent);

	return distance;
}

vector<pair<int, int>> solution(vector<pair<int, int>> Points, vector<pair<int, int>> ConvexHullHalf, pair<int, int> EdgePoint, pair<int, int> TrianglePoint)
{
	if(Points.empty())
	{
		return ConvexHullHalf;
	}

	float distance{};

	pair<int, int> trianglePoint;

	for(const auto & p : Points)
	{
		pair<int, int> Point;

		Point.first=p.first;

		Point.second=p.second;

		float currentDistance=calculateDistance(Point, EdgePoint);

		if(currentDistance > distance)
		{
			distance=currentDistance;

			trianglePoint.first=Point.first;

			trianglePoint.second=Point.second;
		}
	}

	ConvexHullHalf.emplace_back(make_pair(trianglePoint.first, trianglePoint.second));

	vector<pair<int, int>> aboveTriangle;

	vector<pair<int, int>> belowTriangle;

	for(const auto & p : Points)
	{
		if(p.second > trianglePoint.second && p.second > EdgePoint.second)
		{
			aboveTriangle.emplace_back(make_pair(p.first, p.second));
		}
		if(p.second < trianglePoint.second && p.second < EdgePoint.second)
		{
			belowTriangle.emplace_back(make_pair(p.first, p.second));
		}
	}

	return solution(aboveTriangle, ConvexHullHalf, EdgePoint, trianglePoint);

	return solution(belowTriangle, ConvexHullHalf, EdgePoint, trianglePoint);
}

void solutionHelper(vector<pair<int, int>> Points)
{
	vector<pair<int, int>> convexHull;

	auto minMaxPoints=(minmax_element(begin(Points), end(Points), [](const auto & First, const auto & Second) {return First.first < Second.first && First.second < Second.second;}));

	pair<int, int> maxPoint;

	pair<int, int> minPoint;

	minPoint.first=minMaxPoints.first->first;

	minPoint.second=minMaxPoints.first->second;

	maxPoint.first=minMaxPoints.second->first;

	maxPoint.second=minMaxPoints.second->second;

	convexHull.emplace_back(make_pair(minPoint.first, minPoint.second));

	convexHull.emplace_back(make_pair(maxPoint.first, maxPoint.second));

	Points.erase(remove_if(begin(Points), end(Points), [minPoint](auto & element) {return element.first==minPoint.first && element.second==minPoint.second;}));

	Points.erase(remove_if(begin(Points), end(Points), [maxPoint](auto & element) {return element.first==maxPoint.first && element.second==maxPoint.second;}));

	vector<pair<int, int>> aboveTheLine;

	vector<pair<int, int>> belowTheLine;

	for(const auto & point : Points)
	{
		if(point.second > minPoint.second && point.second > maxPoint.second)
		{
			aboveTheLine.emplace_back(make_pair(point.first, point.second));
		}
		if(point.second < minPoint.second && point.second < maxPoint.second)
		{
			belowTheLine.emplace_back(make_pair(point.first, point.second));
		}
	}

	vector<pair<int, int>> firstHalfConvexHull;

	vector<pair<int, int>> secondHalfConvexHull;

	firstHalfConvexHull=solution(aboveTheLine, firstHalfConvexHull, minPoint, maxPoint);

	secondHalfConvexHull=solution(belowTheLine, secondHalfConvexHull, minPoint, maxPoint);

	size_t firstHalfConvexHullSize=firstHalfConvexHull.size();

	size_t secondHalfConvexHullSize=secondHalfConvexHull.size();

	for(int index=0;index<firstHalfConvexHullSize;++index)
	{
		auto point=firstHalfConvexHull[index];

		convexHull.emplace_back(make_pair(point.first, point.second));
	}

	for(int index=0;index<secondHalfConvexHullSize;++index)
	{
		auto point=secondHalfConvexHull[index];

		convexHull.emplace_back(make_pair(point.first, point.second));
	}

	float finalDistance{};

	size_t convexHullSize=convexHull.size();

	int current=0;

	int ahead=1;

	while(ahead < convexHullSize)
	{
		auto firstPoint=convexHull[current];

		auto secondPoint=convexHull[ahead];

		finalDistance+=calculateDistance(firstPoint, secondPoint);

		current++;

		ahead++;
	}

	finalDistance+=calculateDistance(convexHull[convexHullSize-1], convexHull[0]);

	cout << finalDistance << endl;
}

int main(int argc, char**argv)
{
	vector<pair<int, int>> points;

	points.emplace_back(make_pair(1, 1));

	points.emplace_back(make_pair(2, 5));

	points.emplace_back(make_pair(3, 3));

	points.emplace_back(make_pair(5, 3));

	points.emplace_back(make_pair(3, 2));

	points.emplace_back(make_pair(2, 2));

	solutionHelper(points);
}