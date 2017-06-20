#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>
using namespace std;

void findMaxProfit(vector<int> & Prices)
{
	typedef long long int LL;

	typedef unsigned long long ULL;

	int pricesSize=Prices.size();

	int maxCurrentFuturePrice {};

	LL profit {};

	for(int index=pricesSize-1;index>=0;--index)
	{
		//cout << "Determining the max between " << maxCurrentFuturePrice << " and " << Prices[index] << endl;

		maxCurrentFuturePrice=max(maxCurrentFuturePrice, Prices[index]);

		//cout << maxCurrentFuturePrice << " - " << Prices[index] << " = " << maxCurrentFuturePrice-Prices[index] << endl;

		profit+=(LL)(maxCurrentFuturePrice-Prices[index]);

		//cout << "Current profit: " << profit << endl;
	}

	cout << profit << endl;
}

int main(int agrc, char * argv [])
{
	int testCases;

	int numberOfPrices;

	int price;

	cin >> testCases;

	for(int count=0;count<testCases;++count)
	{
		cin >> numberOfPrices;

		vector<int> Prices;

		for(int counter=0;counter<numberOfPrices;++counter)
		{	
			cin >> price;

			Prices.push_back(price);
		}

		for(const auto & price : Prices)
		{
			cout << "Price: " << price << endl;
		}

		findMaxProfit(Prices);

		Prices.clear();
	}
}