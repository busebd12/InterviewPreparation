#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <utility>
using namespace std;

void printCrosswordBoard(vector<string> CrosswordBoard)
{
	size_t boardSize=CrosswordBoard.size();

	for(int row=0;row<boardSize;++row)
	{
		size_t rowSize=CrosswordBoard[row].size();

		for(int column=0;column<rowSize;++column)
		{
			cout << CrosswordBoard[row][column] << " ";
		}

		cout << endl;
	}
}

void solution(vector<string> CrosswordBoard, vector<string> & WordList)
{
	vector<vector<pair<int, int>>> horizontalSpotsForWords;

	vector<vector<pair<int, int>>> verticalSpotsForWords;

	size_t boardSize=CrosswordBoard.size();
	
	vector<pair<int, int>> verticalWordSpot;

	int column=0;

	for(int count=0;count<boardSize;++count)
	{
		for(int row=0;row<boardSize;++row)
		{
			char currentCharacter=CrosswordBoard[row][column];

			if(currentCharacter=='-')
			{
				if(row==0)
				{
					char nextCharacter=CrosswordBoard[row+1][column];

					if(nextCharacter=='+')
					{
						verticalWordSpot.emplace_back(make_pair(row, column));

						verticalSpotsForWords.emplace_back(verticalWordSpot);

						verticalWordSpot.clear();
					}
					else
					{
						verticalWordSpot.emplace_back(make_pair(row, column));
					}
				}

				if(row > 0 && row <= 8)
				{
					char previousCharacter=CrosswordBoard[row-1][column];

					char nextCharacter=CrosswordBoard[row+1][column];

					if(previousCharacter=='+' && nextCharacter=='+')
					{
						verticalWordSpot.emplace_back(make_pair(row, column));

						verticalSpotsForWords.emplace_back(verticalWordSpot);

						verticalWordSpot.clear();
					}
					else
					{
						verticalWordSpot.emplace_back(make_pair(row, column));
					}
				}

				if(row > 8)
				{
					 verticalWordSpot.emplace_back(make_pair(row, column));
				}
			}
		}

		verticalSpotsForWords.emplace_back(verticalWordSpot);

		verticalWordSpot.clear();

		++column;
	}
	
	for(int row=0;row<boardSize;++row)
	{
		vector<pair<int, int>> wordSpot;

		size_t rowSize=CrosswordBoard[row].size();

		for(int column=0;column<rowSize;++column)
		{
			char currentCharacter=CrosswordBoard[row][column];

			if(currentCharacter=='-')
			{
				wordSpot.emplace_back(make_pair(row, column));
			}
		}

		horizontalSpotsForWords.emplace_back(wordSpot);
	}

	sort(begin(WordList), end(WordList), [WordList] (const auto & First, const auto & Second){return First.size() > Second.size();});

	sort(begin(horizontalSpotsForWords), end(horizontalSpotsForWords), [horizontalSpotsForWords] (const auto & First, const auto & Second){return First.size() > Second.size();});

	sort(begin(verticalSpotsForWords), end(verticalSpotsForWords), [verticalSpotsForWords] (const auto & First, const auto & Second){return First.size() > Second.size();});

	size_t horizontalSpotsForWordsSize=horizontalSpotsForWords.size();

	size_t verticalSpotsForWordsSize=verticalSpotsForWords.size();

	for(int spot=0;spot<verticalSpotsForWordsSize;++spot)
	{
		size_t spotSize=verticalSpotsForWords[spot].size();

		auto word=find_if(begin(WordList), end(WordList), [WordList, spotSize] (const auto & w) {return w.size()==spotSize;});

		if(word!=end(WordList))
		{
			string foundWord=*(word);

			for(int index=0;index<spotSize;++index)
			{
				int column=verticalSpotsForWords[spot][index].first;

				int row=verticalSpotsForWords[spot][index].second;

				CrosswordBoard[column][row]=foundWord[index];
			}

			WordList.erase(remove_if(begin(WordList), end(WordList), [foundWord] (const auto & word){return word==foundWord;}), end(WordList));
		}
	}

	for(int spot=0;spot<horizontalSpotsForWordsSize;++spot)
	{
		size_t spotSize=horizontalSpotsForWords[spot].size();

		auto word=find_if(begin(WordList), end(WordList), [WordList, spotSize](const auto & w){return w.size()==spotSize;});

		if(word!=end(WordList))
		{
			string foundWord=*(word);

			for(int index=0;index<spotSize;++index)
			{
				int row=horizontalSpotsForWords[spot][index].first;

				int column=horizontalSpotsForWords[spot][index].second;

				CrosswordBoard[row][column]=foundWord[index];
			}

			WordList.erase(remove_if(begin(WordList), end(WordList), [foundWord] (const auto & word){return word==foundWord;}), end(WordList));
		}
	}

	printCrosswordBoard(CrosswordBoard);
}