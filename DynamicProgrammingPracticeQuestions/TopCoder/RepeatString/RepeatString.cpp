#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class RepeatString
{
	public:
		int minimum(int First, int Second, int Third)
		{
			return min(min(First, Second), Third);
		}

		int editDistance(string First, string Second, size_t FirstSize, size_t SecondSize)
		{
			vector<vector<int>> dpTable(FirstSize+1, vector<int>(SecondSize+1));

			for(int i=0;i<=FirstSize;++i)
			{
				for(int j=0;j<=SecondSize;++j)
				{
					//first string is empty so we have to add all the characters of the second string to it
					if(i==0)
					{
						dpTable[i][j]=j;
					}
					//second string is empty so we have to add all the characters of the first string to it
					else if(j==0)
					{
						dpTable[i][j]=i;
					}
					//the last character from both strings are equal. So, we ignore them and recurse for the remaining characters in the string
					else if(First[i-1]==Second[j-1])
					{
						dpTable[i][j]=dpTable[i-1][j-1];
					}
					else
					{
						//if the last characters from both strings are different, then we have to do try all three operations: 
						//inserting a character, removing a character, and replacing a character
						dpTable[i][j]=1+minimum(dpTable[i][j-1], dpTable[i-1][j], dpTable[i-1][j-1]);
					}
				}
			}

			return dpTable[FirstSize][SecondSize];
		}

		int minimalModify(string Input)
		{
			int operations{};

			size_t stringSize=Input.size();

			//if the string is empty or every character is the same
			if(Input.empty() || (Input.find_first_not_of(Input[0])==string::npos && stringSize > 1))
			{
				return 0;
			}

			//only one character
			if(stringSize==1)
			{
				return 1;
			}

			string firstHalf=Input.substr(0, stringSize/2);

			size_t firstHalfSize=firstHalf.size();

			size_t secondHalfSize=secondHalf.size();

			operations=editDistance(firstHalf, secondHalf, firstHalfSize, secondHalfSize);

			return operations;
		}
};
