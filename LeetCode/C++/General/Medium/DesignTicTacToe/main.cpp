#include <iostream>
#include <vector>

/*
 * Solutions:
 *
 * 1. Each time a player makes a move, we update the board and then check the entire board to see if anyone won.
 *
 * Time complexities:
 * Constructor --> O(n^2)
 * checkForWinner --> O(n^2)
 * move --> O(n^2)
 * validMove --> O(1)
 *
 * Space complexity: O(n^2)
 *
 * 2. Each time a player makes a move, we only check the row and column affected by the move and the two diagonals.
 *
 * Time complexities:
 * Constructor --> O(n^2)
 * checkForWinner --> O(n)
 * move --> O(n)
 * validMove --> O(1)
 *
 * Space complexity: O(n^2)
 */

class TicTacToe
{
    public:
        std::vector<std::vector<char>> board;

        int size;

        TicTacToe(int n)
        {
            board.resize(n, std::vector<char>(n, '.'));

            size=n;
        }

        int checkForWinner(const std::vector<std::vector<char>> & board, int & n)
        {
            int numberOfX=0;

            int numberOfO=0;

            for(auto row=0;row<n;++row)
            {
                for(auto column=0;column<n;++column)
                {
                    if(board[row][column]=='X')
                    {
                        numberOfX++;
                    }

                    if(board[row][column]=='O')
                    {
                        numberOfO++;
                    }
                }

                if(numberOfX==n)
                {
                    return 1;
                }

                if(numberOfO==n)
                {
                    return 2;
                }

                numberOfX=0;

                numberOfO=0;
            }


            for(auto column=0;column<n;++column)
            {
                for(auto row=0;row<n;++row)
                {
                    if(board[row][column]=='X')
                    {
                        numberOfX++;
                    }

                    if(board[row][column]=='O')
                    {
                        numberOfO++;
                    }
                }

                if(numberOfX==n)
                {
                    return 1;
                }

                if(numberOfO==n)
                {
                    return 2;
                }

                numberOfX=0;

                numberOfO=0;
            }


            int row=0;

            int column=0;

            while(row < n && column < n)
            {
                if(board[row][column]=='X')
                {
                    numberOfX++;
                }

                if(board[row][column]=='O')
                {
                    numberOfO++;
                }

                row+=1;

                column+=1;
            }

            if(numberOfX==n)
            {
                return 1;
            }

            if(numberOfO==n)
            {
                return 2;
            }

            numberOfX=0;

            numberOfO=0;

            row=0;

            column=n-1;

            while(row < n && column >= 0)
            {
                if(board[row][column]=='X')
                {
                    numberOfX++;
                }

                if(board[row][column]=='O')
                {
                    numberOfO++;
                }

                row+=1;

                column-=1;
            }

            if(numberOfX==n)
            {
                return 1;
            }

            if(numberOfO==n)
            {
                return 2;
            }

            return 0;
        }

        int move(int row, int column, int player)
        {
            if(!validMove(row, column))
            {
                return 0;
            }

            if(board[row][column]!='.')
            {
                return 0;
            }

            if(player==1)
            {
                board[row][column]='X';
            }
            else
            {
                board[row][column]='O';
            }

            return checkForWinner(board, size);
        }

        bool validMove(int row, int column)
        {
            return ((row >= 0 && row < size) && (column >= 0 && column < size));
        }
};

class TicTacToe
{
    public:
        std::vector<std::vector<char>> board;

        int size;

        TicTacToe(int n)
        {
            board.resize(n, std::vector<char>(n, '.'));

            size=n;
        }

        int checkForWinner(int row, int column)
        {
            int numberOfX=0;

            int numberOfO=0;

            for(auto x=0;x<size;++x)
            {
                if(board[row][x]=='X')
                {
                    numberOfX++;
                }

                if(board[row][x]=='O')
                {
                    numberOfO++;
                }
            }

            if(numberOfX==size)
            {
                return 1;
            }

            if(numberOfO==size)
            {
                return 2;
            }

            numberOfX=0;

            numberOfO=0;

            for(auto y=0;y<size;++y)
            {
                if(board[y][column]=='X')
                {
                    numberOfX++;
                }

                if(board[y][column]=='O')
                {
                    numberOfO++;
                }
            }

            if(numberOfX==size)
            {
                return 1;
            }

            if(numberOfO==size)
            {
                return 2;
            }

            numberOfX=0;

            numberOfO=0;

            int i=0;

            int j=0;

            while(i < size && j < size)
            {
                if(board[i][j]=='X')
                {
                    numberOfX++;
                }

                if(board[i][j]=='O')
                {
                    numberOfO++;
                }

                i+=1;

                j+=1;
            }

            if(numberOfX==size)
            {
                return 1;
            }

            if(numberOfO==size)
            {
                return 2;
            }

            numberOfX=0;

            numberOfO=0;

            i=0;

            j=size-1;

            while(i < size && j >= 0)
            {
                if(board[i][j]=='X')
                {
                    numberOfX++;
                }

                if(board[i][j]=='O')
                {
                    numberOfO++;
                }

                i+=1;

                j-=1;
            }

            if(numberOfX==size)
            {
                return 1;
            }

            if(numberOfO==size)
            {
                return 2;
            }

            return 0;
        }

        int move(int row, int column, int player)
        {
            if(!validMove(row, column))
            {
                return 0;
            }

            if(board[row][column]!='.')
            {
                return 0;
            }

            if(player==1)
            {
                board[row][column]='X';
            }
            else
            {
                board[row][column]='O';
            }

            int winner=checkForWinner(row, column);

            return winner;
        }

        bool validMove(int row, int column)
        {
            return ((row >= 0 && row < size) && (column >= 0 && column < size));
        }
};