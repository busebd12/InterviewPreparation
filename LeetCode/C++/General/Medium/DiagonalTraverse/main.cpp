#include <iostream>
#include <vector>

/*
 * Solution: the algorithm mirrors how one would solve this problem by hand. First, we handle some edge cases.
 * If the matrix is a 1-by-1 matrix, then it is just a single element. If the matrix has only one row, then we
 * just return that row. If the matrix has multiple rows but only one element per row, then the solution will be
 * all the single elements in every row. Otherwise, it is the general case. We start with adding the number in the
 * upper left-hand corner. Then, we move one column over in preparation for going diagonal down. We traverse diagonal
 * down as far as we can. Then, we either move down one row or move over one column to the right. Then, we traverse
 * digonally up as far as we can go. Then, we either move down or to the right one column. Repeat this process until
 * we reach the bottom right-hand corner of the matrix (i.e. the last number). Then, just add the last number of break
 * out of the loop.
 *
 * Time complexity: O(M * N) [where M is the number of rows and N is the number of columns]
 * Space complexity: O(1)
 */

bool isValid(int & M, int & N, int row, int column)
{
    return ((row >= 0 && row < M) && (column >= 0 && column < N));
}

std::vector<int> findDiagonalOrder(std::vector<std::vector<int>> & matrix)
{
    std::vector<int> result;

    if(matrix.empty())
    {
        return result;
    }

    int M=int(matrix.size());

    int N=int(matrix[0].size());

    if(M==1 && N==1)
    {
        result.emplace_back(matrix[M-1][N-1]);

        return result;
    }

    if(M==1 && N > 1)
    {
        return matrix[0];
    }

    if(M > 1 && N==1)
    {
        for(auto i=0;i<M;++i)
        {
            result.emplace_back(matrix[i][0]);
        }

        return result;
    }

    bool down=true;

    int row=0;

    int column=0;

    while(true)
    {
        if(row==0 && column==0)
        {
            result.emplace_back(matrix[row][column]);

            column+=1;
        }
        else if(row==M-1 && column==N-1)
        {
            result.emplace_back(matrix[row][column]);

            break;
        }
        else
        {
            if(down)
            {
                while(true)
                {
                    result.emplace_back(matrix[row][column]);

                    if(isValid(M, N, row+1, column-1))
                    {
                        row+=1;

                        column-=1;
                    }
                    else
                    {
                        break;
                    }
                }

                if(!isValid(M, N, row+1, column))
                {
                    column+=1;
                }
                else
                {
                    row+=1;
                }

                down=false;
            }
            else
            {
                while(true)
                {
                    result.emplace_back(matrix[row][column]);

                    if(isValid(M, N, row-1, column+1))
                    {
                        row-=1;

                        column+=1;
                    }
                    else
                    {
                        break;
                    }
                }

                if(!isValid(M, N, row, column+1))
                {
                    row+=1;
                }
                else
                {
                    column+=1;
                }

                down=true;
            }
        }
    }

    return result;
}