#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <utility>
using namespace std;

int findMinimumDistance(vector<int> AccountNumber, vector<int> Keyboard, map<pair<int, int>, int> DPCache, int Time, int LeftFingerIndex, int RightFingerIndex, int AccountNumberIndex, int LastAccountNumber)
{
	//if either of our fingers are on the key for the last number in the account, we have finished entering in the account number
	if(Keyboard[LeftFingerIndex]==LastAccountNumber || Keyboard[RightFingerIndex]==LastAccountNumber)
	{
		return Time;
	}

	int nextAccountNumber=AccountNumber[AccountNumberIndex];

	int keyUnderLeftFinger=Keyboard[LeftFingerIndex];

	int keyUnderRightFinger=Keyboard[RightFingerIndex];


	//retrive the distance from the keys under our left and right index fingers to the next number in the account number
	auto leftFingerDistance=DPCache.find(make_pair(keyUnderLeftFinger, nextAccountNumber));

	auto rightFingerDistance=DPCache.find(make_pair(keyUnderRightFinger, nextAccountNumber));

	//compare the distances to find the minimum and update the time accordingly
	if(leftFingerDistance!=end(DPCache) && rightFingerDistance!=end(DPCache))
	{
		if(leftFingerDistance->second < rightFingerDistance->second)
		{
			Time+=leftFingerDistance->second;

			Time+=1;

			if((nextAccountNumber > keyUnderLeftFinger) || nextAccountNumber==0)
			{
				LeftFingerIndex+=leftFingerDistance->second;
			}
			else
			{
				LeftFingerIndex-=leftFingerDistance->second;
			}
		}
		else
		{
			Time+=rightFingerDistance->second;

			Time+=1;

			if((nextAccountNumber > keyUnderRightFinger) || nextAccountNumber==0)
			{
				RightFingerIndex+=rightFingerDistance->second;
			}
			else
			{
				RightFingerIndex-=rightFingerDistance->second;
			}
		}
	}

	//incremnt to move on to the next number in the account number
	AccountNumberIndex++;

	return findMinimumDistance(AccountNumber, Keyboard, DPCache, Time, LeftFingerIndex, RightFingerIndex, AccountNumberIndex, LastAccountNumber);
}

int findMinimumDistanceHelper(vector<int> AccountNumber)
{
	if(AccountNumber.empty())
	{
		cout << "No account number provided" << endl;

		return 0;
	}

	//where we store the time distances between all the different keys in the keyboard
	map<pair<int, int>, int> dpCache;

	vector<int> keyboard={1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	//the index of the keyboard where our left finger is
	int leftFingerIndex{};

	//the index of the keyboard where our right finger is
	int rightFingerIndex{};

	//the total time it takes us to type in the account number
	int Time{};

	size_t accountNumberSize=AccountNumber.size();

	size_t keyboardSize=keyboard.size();

	int firstAccountNumber=AccountNumber[0];

	int secondAccountNumber=AccountNumber[1];

	int lastAccountNumber=AccountNumber[accountNumberSize-1];

	//start at two since we have already typed the first two numbers in the account number
	int accountNumberIndex=2;

	//figure out where to put our left and right index fingers on the keyboard at the beginning
	if(firstAccountNumber < secondAccountNumber)
	{
		if(firstAccountNumber==0)
		{
			rightFingerIndex=keyboardSize-1;

			leftFingerIndex=secondAccountNumber-1;
		}
		else
		{
			rightFingerIndex=secondAccountNumber-1;

			leftFingerIndex=firstAccountNumber-1;
		}
	}

	if(secondAccountNumber < firstAccountNumber)
	{
		if(secondAccountNumber==0)
		{
			rightFingerIndex=keyboardSize-1;

			leftFingerIndex=firstAccountNumber-1;
		}
		else
		{
			rightFingerIndex=firstAccountNumber-1;

			leftFingerIndex=secondAccountNumber-1;
		}
	}

	//calculate the time differences between all the keys on the keyboard
	for(int index=0;index<keyboardSize;++index)
	{
		int firstKey=keyboard[index];

		for(int innerIndex=0;innerIndex<keyboardSize;++innerIndex)
		{
			int secondKey=keyboard[innerIndex];

			if(firstKey < secondKey)
			{
				int difference{};

				if(firstKey==0)
				{
					difference=keyboardSize-secondKey;
				}
				else
				{
					difference=firstKey-secondKey;

					difference*=-1;
				}

				dpCache.emplace(make_pair(make_pair(firstKey, secondKey), difference));
			}
			else
			{
				int difference=firstKey-secondKey;

				dpCache.emplace(make_pair(make_pair(firstKey, secondKey), difference));
			}
		}
	}

	//since we have already typed the first two numbers in the account number
	Time+=2;

	Time=findMinimumDistance(AccountNumber, keyboard, dpCache, Time, leftFingerIndex, rightFingerIndex, accountNumberIndex, lastAccountNumber);

	return Time;
}

int findMinimumDistanceIterative(vector<int> AccountNumber)
{
	if(AccountNumber.empty())
	{
		cout << "No account number provided" << endl;

		return 0;
	}

	vector<int> keyboard={1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	//where we store the time distances between all the different keys in the keyboard
	map<pair<int, int>, int> dpCache;

	//the index of the keyboard where our left finger is
	int leftFingerIndex{};

	//the index of the keyboard where our right finger is
	int rightFingerIndex{};

	//the total time it takes us to type in the account number
	int Time{};

	size_t accountNumberSize=AccountNumber.size();

	size_t keyboardSize=keyboard.size();

	int firstAccountNumber=AccountNumber[0];

	int secondAccountNumber=AccountNumber[1];

	//figure out where to put our left and right index fingers on the keyboard at the beginning
	if(firstAccountNumber < secondAccountNumber)
	{
		if(firstAccountNumber==0)
		{
			rightFingerIndex=keyboardSize-1;

			leftFingerIndex=secondAccountNumber-1;
		}
		else
		{
			rightFingerIndex=secondAccountNumber-1;

			leftFingerIndex=firstAccountNumber-1;
		}
	}

	if(secondAccountNumber < firstAccountNumber)
	{
		if(secondAccountNumber==0)
		{
			rightFingerIndex=keyboardSize-1;

			leftFingerIndex=firstAccountNumber-1;
		}
		else
		{
			rightFingerIndex=firstAccountNumber-1;

			leftFingerIndex=secondAccountNumber-1;
		}
	}

	//calculate the time differences between all the keys on the keyboard
	for(int index=0;index<keyboardSize;++index)
	{
		int firstKey=keyboard[index];

		for(int innerIndex=0;innerIndex<keyboardSize;++innerIndex)
		{
			int secondKey=keyboard[innerIndex];

			if(firstKey < secondKey)
			{
				int difference{};

				if(firstKey==0)
				{
					difference=keyboardSize-secondKey;
				}
				else
				{
					difference=firstKey-secondKey;

					difference*=-1;
				}

				dpCache.emplace(make_pair(make_pair(firstKey, secondKey), difference));
			}
			else
			{
				int difference=firstKey-secondKey;

				dpCache.emplace(make_pair(make_pair(firstKey, secondKey), difference));
			}
		}
	}

	//since we have already typed the first two numbers in the account number
	Time+=2;

	int keyUnderRightFinger=keyboard[rightFingerIndex];

	int keyUnderLeftFinger=keyboard[leftFingerIndex];

	for(int index=2;index<accountNumberSize;++index)
	{
		int nextAccountNumber=AccountNumber[index];

		int keyUnderLeftFinger=keyboard[leftFingerIndex];

		int keyUnderRightFinger=keyboard[rightFingerIndex];

		//retrive the distance from the keys under our left and right index fingers to the next number in the account number
		auto leftFingerDistance=dpCache.find(make_pair(keyUnderLeftFinger, nextAccountNumber));

		auto rightFingerDistance=dpCache.find(make_pair(keyUnderRightFinger, nextAccountNumber));

		//compare the distances to find the minimum and update the time accordingly
		if(leftFingerDistance!=end(dpCache) && rightFingerDistance!=end(dpCache))
		{
			if(leftFingerDistance->second < rightFingerDistance->second)
			{
				Time+=leftFingerDistance->second;

				Time+=1;

				if((nextAccountNumber > keyUnderLeftFinger) || nextAccountNumber==0)
				{
					leftFingerIndex+=leftFingerDistance->second;
				}
				else
				{
					leftFingerIndex-=leftFingerDistance->second;
				}
			}
			else
			{
				Time+=rightFingerDistance->second;

				Time+=1;

				if((nextAccountNumber > keyUnderRightFinger) || nextAccountNumber==0)
				{
					rightFingerIndex+=rightFingerDistance->second;
				}
				else
				{
					rightFingerIndex-=rightFingerDistance->second;
				}
			}
		}
	}

	return Time;
}