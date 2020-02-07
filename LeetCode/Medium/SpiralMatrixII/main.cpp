#include <iostream>
#include <vector>

/*
 * Solution: we first generate a matrix of size n-squared filled with zeroes.
 * Then, we iterate through the matrix in spiral order replacing the zeroes
 * with the correct numbers from [1, n] as we go.
 *
 * Time complexity: O(n-squared) [where n is the input number]
 * Space complexity: O(n-squared) [if we are counting the returned matrix] O(1) [if we are not counting the returned matrix]
 */

void convertToSpiralOrder(std::vector<std::vector<int>> & result, int n)
{
    int rows=n;

    int columns=n;

    int topRow=0;

    int bottomRow=rows-1;

    int leftColumn=0;

    int rightColumn=columns-1;

    int number=1;

    int direction=0;

    while(topRow <= bottomRow && leftColumn <= rightColumn)
    {
        if(direction==0)
        {
            for(int i=leftColumn;i<=rightColumn;++i)
            {
                result[topRow][i]=number;

                number++;
            }

            topRow++;
        }
        else if(direction==1)
        {
            for(int i=topRow;i<=bottomRow;++i)
            {
                result[i][rightColumn]=number;

                number++;
            }

            rightColumn--;
        }
        else if(direction==2)
        {
            for(int i=rightColumn;i>=leftColumn;--i)
            {
                result[bottomRow][i]=number;

                number++;
            }

            bottomRow--;
        }
        else if(direction==3)
        {
            for(int i=bottomRow;i>=topRow;--i)
            {
               result[i][leftColumn]=number;

               number++;
            }

            leftColumn++;
        }

        direction=(direction + 1) % 4;
    }
}

std::vector<std::vector<int>> generateMatrix(int n)
{
    int size=n * n;

    std::vector<std::vector<int>> result(n, std::vector<int>(n));

    if(n==0)
    {
        return result;
    }

    convertToSpiralOrder(result, n);

    return result;
}