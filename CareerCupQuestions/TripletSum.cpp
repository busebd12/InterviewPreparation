#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <numeric>
#include <functional>
#include <tuple>
using namespace std;

/*Question: write a function to find all combinations of three numbers in an array that sum to a given value*/

void findAllTripletCombinations(const vector<int> & Array, const int Sum)
{
	unordered_multimap<int, vector<int>> smallerSums;

	vector<vector<int>> triplets;

	//Go through array and calculate the sum of each pair of numbers and add them to the hash table
	//So, we are hasing the sum of each pair of numbers to that pair of numbers
	for(int index=0;index<Array.size();++index)
	{
		for(int spot=0;spot<Array.size();++spot)
		{
			smallerSums.insert(pair<int, vector<int>>((Array[index]+Array[spot]), {Array[index], Array[spot]}));
		}
	}

	//loop through the array and for each element, calculate the difference between the desired sum and the element
	//then, check to see if any sum within our hash table matches that difference, and if it does, add all the numbers to the vector and add the vector to the vector of vectors
	for(const auto & element : Array)
	{
		int numberToFind=Sum-element;		

		auto found=smallerSums.find(numberToFind);

		if(found!=smallerSums.end())
		{
			vector<int> temp;

			temp.push_back(element);

			for(const auto & number : found->second)
			{
				temp.push_back(number);
			}

			triplets.push_back(temp);
		}
	}

	cout << "Triplets:" << endl;

	for(const auto & triplet : triplets)
	{
		for(const auto & number : triplet)
		{
			cout << number << endl;
		}

		cout << endl;
	}
}

int main(int argc, char *argv [])
{
	vector<int> V={2, 3, 1, -2, -1, 0, 2, -3, 0};

	int sum=0;

	findAllTripletCombinations(V, sum);
}