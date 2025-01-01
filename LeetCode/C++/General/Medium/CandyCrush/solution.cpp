#include <deque>
#include <utility>
#include <vector>

class Solution
{
    public:
        vector<vector<int>> candyCrush(vector<vector<int>> & board)
        {
            int rows=board.size();

            int columns=board[0].size();

            const int CRUSH=-1;

            vector<pair<int, int>> spotsToCrush;

            bool done=false;

            while(done==false)
            {
                markColumns(board, spotsToCrush, rows, columns);

                markRows(board, spotsToCrush, rows, columns);

                if(!spotsToCrush.empty())
                {
                    crush(board, spotsToCrush, rows, columns, CRUSH);

                    spotsToCrush.clear();
                }
                else
                {
                    done=true;
                }
            }

            return board;
        }

        void markColumns(vector<vector<int>> & board, vector<pair<int, int>> & spotsToCrush, int rows, int columns)
        {   
            for(int column=0;column<columns;column++)
            {
                deque<pair<int, int>> replaced;
                
                int row=0;
                
                while(row < rows)
                {
                    while(row < rows and board[row][column]==0)
                    {
                        row+=1;
                    }
                    
                    int consecutive=1;
                    
                    int r=row + 1;
                    
                    spotsToCrush.emplace_back(row, column);
                    
                    while(r < rows and board[row][column]==board[r][column])
                    {
                        spotsToCrush.emplace_back(r, column);
                        
                        replaced.emplace_back(r, board[r][column]);
                        
                        consecutive+=1;
                        
                        r+=1;
                    }
                    
                    if(consecutive < 3)
                    {   
                        while(!replaced.empty())
                        {
                            auto [targetRow, value]=replaced.front();
                            
                            replaced.pop_front();
                            
                            board[targetRow][column]=value;
                        }
                        
                        for(int count=0;count<consecutive and !spotsToCrush.empty();count++)
                        {
                            spotsToCrush.pop_back();
                        }
                    }
                    
                    row=r;
                }
            }
        }

        void markRows(vector<vector<int>> & board, vector<pair<int, int>> & spotsToCrush, int rows, int columns)
        {
            for(int row=0;row<rows;row++)
            {
                deque<pair<int, int>> replaced;
                
                int column=0;
                
                while(column < columns)
                {
                    while(column < columns and board[row][column]==0)
                    {
                        column+=1;
                    }
                    
                    int consecutive=1;
                    
                    int c=column + 1;
                    
                    spotsToCrush.emplace_back(row, column);
                    
                    while(c < columns and board[row][column]==board[row][c])
                    {   
                        spotsToCrush.emplace_back(row, c);
                        
                        replaced.emplace_back(c, board[row][c]);
                        
                        consecutive+=1;
                        
                        c+=1;
                    }
                    
                    if(consecutive < 3)
                    {   
                        while(!replaced.empty())
                        {
                            auto [targetColumn, value]=replaced.front();
                            
                            replaced.pop_front();
                            
                            board[row][targetColumn]=value;
                        }
                        
                        for(int count=0;count<consecutive and !spotsToCrush.empty();count++)
                        {
                            spotsToCrush.pop_back();
                        }
                    }
                    
                    column=c;
                }
            }
        }

        void crush(vector<vector<int>> & board, vector<pair<int, int>> & spotsToCrush, int rows, int columns, const int CRUSH)
        {
            for(auto & [row, column] : spotsToCrush)
            {
                board[row][column]=CRUSH;
            }
            
            for(int column=0;column<columns;column++)
            {
                deque<int> reducedColumn;
                
                int row=rows - 1;
                
                while(row >= 0)
                {
                    if(board[row][column]!=CRUSH)
                    {
                        reducedColumn.emplace_back(board[row][column]);
                    }
                    
                    row-=1;
                }
                
                while(reducedColumn.size() < rows)
                {
                    reducedColumn.emplace_back(0);
                }
                
                row=rows - 1;
                
                while(row >= 0 and !reducedColumn.empty())
                {
                    board[row][column]=reducedColumn.front();
                    
                    reducedColumn.pop_front();
                    
                    row-=1;
                }
            }
        }
};