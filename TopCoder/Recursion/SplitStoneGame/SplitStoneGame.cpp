#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class SplitStoneGame
{
	public:
		int winOrLoseHelper(vector<int> Number, int Turn)
		{
			if(Number.size()-1==1 || Number.size()==1)
			{
				return Turn;
			}

			int index=Number.size()-1;

			for(;index>=0;--index)
			{
				int currentElement=Number[index];

				if(currentElement >= 2)
				{
					int pileA=currentElement/2;

					int pileB=currentElement-pileA;

					Number[--index]+=pileA;

					int twoBeforeIndex=(index-=2);

					Number[twoBeforeIndex]+=pileB;

					break;
				}
			}

			Number.erase(begin(Number)+index);

			++Turn;

			return winOrLoseHelper(Number, Turn);
		}

		string winOrLose(vector<int> Number)
		{
			int elementsGreaterThanOrEqualToTwo=count_if(begin(Number), end(Number), [] (const auto & element) {return element >= 2;});

			if(elementsGreaterThanOrEqualToTwo==0)
			{
				return "LOSE";
			}

			int turn{};

			if(!is_sorted(begin(Number), end(Number)))
			{
				sort(begin(Number), end(Number));
			}

			int result=winOrLoseHelper(Number, turn);

			if(result%2==0 && result >= 0)
			{
				return "LOSE";
			}
			else
			{
				return "WIN";
			}
		}
};