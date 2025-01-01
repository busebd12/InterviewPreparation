#include <vector>
using namespace std;

/*
Time complexity: O(g + w + (g * (m * n)) + (m * n)) [where g=length of guards; w=length of walls]
Space complexity: O(m * n)
*/

class Solution
{
    public:
        int countUnguarded(int m, int n, vector<vector<int>> & guards, vector<vector<int>> & walls)
        {
            int result=0;

            vector<vector<char>> cells(m, vector<char>(n, '$'));

            for(vector<int> guard : guards)
            {
                int row=guard[0];

                int column=guard[1];

                cells[row][column]='G';
            }

            for(vector<int> wall : walls)
            {
                int row=wall[0];

                int column=wall[1];

                cells[row][column]='W';
            }

            for(vector<int> guard : guards)
            {
                int row=guard[0];

                int column=guard[1];
                
                checkUp(cells, m, n, row, column);

                checkDown(cells, m, n, row, column);

                checkLeft(cells, m, n, row, column);

                checkRight(cells, m, n, row, column);
            }

            for(int row=0;row<m;row++)
            {
                for(int column=0;column<n;column++)
                {
                    if(cells[row][column]=='$')
                    {
                        result+=1;
                    }
                }
            }

            return result;
        }

        void checkUp(vector<vector<char>> & cells, int m, int n, int row, int column)
        {
            row-=1;
            
            while(row >= 0 and cells[row][column]!='W' and cells[row][column]!='G')
            {
                if(cells[row][column]=='$')
                {
                    cells[row][column]='#';
                }
                
                row-=1;
            }
        }

        void checkDown(vector<vector<char>> & cells, int m, int n, int row, int column)
        {
            row+=1;
            
            while(row < m and cells[row][column]!='W' and cells[row][column]!='G')
            {
                if(cells[row][column]=='$')
                {
                    cells[row][column]='#';
                }

                row+=1;
            }
        }

        void checkLeft(vector<vector<char>> & cells, int m, int n, int row, int column)
        {
            column-=1;
            
            while(column >= 0 and cells[row][column]!='W' and cells[row][column]!='G')
            {
                if(cells[row][column]=='$')
                {   
                    cells[row][column]='#';
                }

                column-=1;
            }
        }
        
        void checkRight(vector<vector<char>> & cells, int m, int n, int row, int column)
        {
            column+=1;
            
            while(column < n and cells[row][column]!='W' and cells[row][column]!='G')
            {
                if(cells[row][column]=='$')
                {
                    cells[row][column]='#';
                }

                column+=1;
            }
        }
};