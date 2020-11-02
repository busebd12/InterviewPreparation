#include <iostream>
#include <vector>

/*
 * Solutions:
 *
 * 1. Recursion + backtracking. We consider each letter in the board as a potential starting point for our target word.
 * Then, for each letter in the board, we try to build the target word as we recursively explore the board.
 * The recursive exploration occurrs after we have added the current letter to the matching word we are trying to build.
 * We explore all valid adjacent cells (horizontal and vertical). In order to prevent cells from being used more than once,
 * we maintain a board of booleans (same size as the input board) to mark whether or not we've used this cell before.
 * When we have successfully built the word we are searching for, we return true. Note: this solution received
 * Time Limit Exceeded when submitted for judging.
 *
 * Time complexity: O((rows * columns) * 4^k) [where rows is the number of rows in the board; columns is the number of columns in the grid; k is the length of the input word]
 * Space complexity: O((rows * columns) * 4^k + (rows * columns))
 *
 * 2. Recursion + backtracking. The main differences between this solution and the previous one are two things:
 *
 * a. We ditch the extra space used to keep track of which cells we visited by modifying the baord in place and then undoing our modification.
 * b. Instead of trying to build a copy of the word as we traverse the board, we try to match the letters on the baord with the letters
 * in the target word by index.
 *
 * Time complexity: O((rows * columns) * 4^k) [where rows is the number of rows in the board; columns is the number of columns in the grid; k is the length of the input word]
 * Space complexity: O((rows * columns) * 4^k)
 */

bool onBoard(int rows, int columns, int row, int column)
{
    return ((row >= 0 && row < rows) && (column >= 0 && column < columns));
}

bool backtracking(std::vector<std::vector<char>> & board, std::vector<std::vector<bool>> used, std::string & word, std::string & candidate, int rows, int columns, int row, int column)
{
    if(candidate==word)
    {
        return true;
    }

    if(!onBoard(rows, columns, row, column))
    {
        return false;
    }

    if(!used[row][column])
    {
        used[row][column]=true;

        candidate+=board[row][column];

        if(backtracking(board, used, word, candidate, rows, columns, row-1, column))
        {
            return true;
        }

        if(backtracking(board, used, word, candidate, rows, columns, row+1, column))
        {
            return true;
        }

        if(backtracking(board, used, word, candidate, rows, columns, row, column-1))
        {
            return true;
        }

        if(backtracking(board, used, word, candidate, rows, columns, row, column+1))
        {
            return true;
        }

        candidate.pop_back();

        used[row][column]=false;
    }

    return false;
}

bool exist(std::vector<std::vector<char>> & board, std::string & word)
{
    if(board.empty() || word.empty())
    {
        return false;
    }

    int rows=int(board.size());

    int columns=int(board[0].size());

    std::vector<std::vector<bool>> used(rows, std::vector<bool>(columns, false));

    for(auto row=0;row<rows;++row)
    {
        for(auto column=0;column<columns;++column)
        {
            std::string candidate{};

            if(backtracking(board, used, word, candidate, rows, columns, row, column))
            {
                return true;
            }
        }
    }

    return false;
}

bool backtracking(std::vector<std::vector<char>> & board, std::string & word, int rows, int columns, int row, int column, int index)
{
    if(index==word.size())
    {
        return true;
    }

    if(!onBoard(rows, columns, row, column))
    {
        return false;
    }

    if(board[row][column]!=word[index])
    {
        return false;
    }

    char currentState=board[row][column];

    board[row][column]='#';

    bool result=(backtracking(board, word, rows, columns, row-1, column, index+1) || backtracking(board, word, rows, columns, row+1, column, index+1) || backtracking(board, word, rows, columns, row, column-1, index+1) || backtracking(board, word, rows, columns, row, column+1, index+1));

    board[row][column]=currentState;

    return result;
}

bool exist(std::vector<std::vector<char>> & board, std::string & word)
{
    if(board.empty() || word.empty())
    {
        return false;
    }

    int rows=int(board.size());

    int columns=int(board[0].size());

    int index=0;

    for(auto row=0;row<rows;++row)
    {
        for(auto column=0;column<columns;++column)
        {
            if(backtracking(board, word, rows, columns, row, column, index))
            {
                return true;
            }
        }
    }

    return false;
}