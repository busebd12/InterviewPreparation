#include <map>
#include <vector>
using namespace std;

class Excel
{
    private:
        vector<int> letterToColumn;

        vector<vector<int>> spreadsheet;

        map<pair<int, char>, vector<string>> hashmap;
    
    public:
        Excel(int height, char width)
        {
            letterToColumn.resize(128, 0);

            int column=0;

            //Create mapping of letters to zero-indexed columns
            for(char letter='A';letter<='Z';letter++)
            {
                int asciiIndex=int(letter);

                letterToColumn[asciiIndex]=column;

                column+=1;
            }

            createSpreadsheet(height, width);
        }

        void createSpreadsheet(int height, char width)
        {
            int asciiIndex=int(width);

            int columns=letterToColumn[asciiIndex] + 1;

            spreadsheet.resize(height, vector<int>(columns, 0));
        }
        
        void set(int row, char column, int val)
        {
            //If the value of cell (row, column) was previously dependent on other cells from the spreadsheet
            if(hashmap.find({row, column})!=hashmap.end())
            {
                //Remove the dependency mapping from the hashmap since we will be changing the value of the current cell
                hashmap.erase({row, column});
            }

            int c=letterToColumn[int(column)];

            spreadsheet[row - 1][c]=val;
        }
        
        int get(int row, char column)
        {
            //If this cell (row, column) is dependent on any other cells in the spreadsheet
            if(hashmap.find({row, column})!=hashmap.end())
            {
                //Then, we want to calculate the sum of the dependent cells since their values could have changed
                return sum(row, column, hashmap[{row, column}]);
            }

            //The current cell (row, column) is not dependent on any other cells, so just return its value
            int c=letterToColumn[int(column)];

            return spreadsheet[row - 1][c];
        }
        
        int sum(int row, char column, vector<string> numbers)
        {
            int total=0;

            //Iterate through list of cells that this cell (row, column) depends on for the sum stored in its cell
            for(string number : numbers)
            {
                //Single cell
                if(number.find(':')==string::npos)
                {
                    pair<int, char> rowColumnPair=getRowColumnPair(number);

                    total+=get(rowColumnPair.first, rowColumnPair.second);
                }
                //Range of cells
                else
                {
                    auto colonIndex=number.find(':');

                    string upperLeftNumber=number.substr(0, colonIndex);

                    pair<int, char> upperLeftRowColumnPair=getRowColumnPair(upperLeftNumber);

                    int upperLeftRow=upperLeftRowColumnPair.first;

                    char upperLeftColumn=upperLeftRowColumnPair.second;

                    string bottomRightNumber=number.substr(colonIndex + 1, string::npos);

                    pair<int, char> bottomRightRowColumnPair=getRowColumnPair(bottomRightNumber);

                    int bottomRightRow=bottomRightRowColumnPair.first;

                    char bottomRightColumn=bottomRightRowColumnPair.second;

                    for(int row=upperLeftRow;row<=bottomRightRow;row++)
                    {
                        for(char column=upperLeftColumn;column<=bottomRightColumn;column++)
                        {
                            total+=get(row, column);
                        }
                    }
                }
            }

            //Create the mapping of (row, column) --> {list of cells this cell is dependent on}
            hashmap[{row, column}]=numbers;

            return total;
        }

        //Helper function to parse out the row and column from a given cell
        pair<int, char> getRowColumnPair(string & number)
        {
            int row=0;

            if(number.size()==2)
            {
                row=(number[1] - '0');
            }
            else
            {
                row=stoi(number.substr(1, 2));
            }

            int column=number[0];

            return make_pair(row, column);
        }
};