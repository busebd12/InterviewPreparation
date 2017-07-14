#include <iostream>
#include <vector>
using namespace std;

void printRows(const vector<vector<int>> & Rows)
{
    cout << "Size of rows: " << Rows.size() << endl;

    if(!Rows.empty())
    {
        for(const auto & row : Rows)
        {
            for(const auto & element : row)
            {
                cout << element << " ";
            }
            
            cout << endl;
        }

        cout << endl;
    }
    else
    {
        cout << "Empty vector of vectors" << endl;

        cout << endl;
    }
}

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> rows;
    
    if(numRows==0)
    {
        return rows;
    }

    if(numRows==1)
    {
        //cout << "numRows is 1" << endl;

        //cout << endl;

        vector<int> v={1};
        
        rows.emplace_back(v);

        //cout << "After adding v to rows, size of rows is: " << rows.size() << endl;

        //cout << endl;

        //return rows;
    }

    if(numRows==2)
    {
        //cout << "numRows is 2" << endl;

        //cout << endl;

        vector<int> v={1, 1};
        
        rows.emplace_back(v);

        //return rows;
    }
    else if(numRows > 2)
    {
        //cout << "numRows is greater than 2" << endl;

        //cout << endl;

        vector<vector<int>> currentRows=generate(numRows-1);

        cout << "currentRows size: " << currentRows.size() << endl;

        cout << endl;

        vector<int> lastRow=currentRows[currentRows.size()-1];

        vector<int> newRow;
        
        //cout << "Adding " << lastRow[0] << " to new row" << endl;
        
        //cout << endl;

        newRow.emplace_back(lastRow[0]);

        int current=0;

        int next=1;

        while(true)
        {
            if(next==lastRow.size())
            {
                //cout << "Adding " << lastRow[current] << " to the new row" << endl;
                
                //cout << endl;
                
                newRow.emplace_back(lastRow[current]);

                break;
            }
            else
            {
                int sum=lastRow[current]+lastRow[next];
                
                //cout << "Adding sum " << sum << " to the new row" << endl;
                
                //cout << endl;

                newRow.emplace_back(sum);
            }

            ++current;

            ++next;
        }

        rows.emplace_back(newRow);

        //cout << "After adding new row, size of rows is " << rows.size() << endl;

        //cout << endl;
    }
    
    //cout << "Going to return rows" << endl;

    return rows;
}

int main()
{
    for(int numRows=0;numRows<10;++numRows)
    {
        cout << "numRows: " << numRows << endl;

        auto result=generate(numRows);
    
        printRows(result);   
    }
}