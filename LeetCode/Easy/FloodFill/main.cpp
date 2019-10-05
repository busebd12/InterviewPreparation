#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

/*
 * Approaches:
 *
 * 1) Recursive depth-first search. If the current pixel of the image (image[row][column])
 * has the color we want to replace, replace the old color with the new color. Then, for each pixel
 * above, below, to the left, and to the right of the current pixel, we check a couple of things:
 *
 * a) Is the pixel still in the image?
 * b) Does this pixel have the color we want to replace and its color is not the new color
 *
 * If both of these conditions are true, then we recursively Flood Fill for this pixel.
 *
 * Time complexity: O(n * m) [where n is the number of rows in our image and m is the number of columns in our image]
 * Space complexity: O(n * m) recursive stack space
 *
 *
 * 2) Iterative depth-first search using a stack and the same logic.
 *
 * Time complexity: O(n * m) [where n is the number of rows in our image and m is the number of columns in our image]
 * Space complexity: O(n * m)
 */

bool isValid(int row, int column, int rows, int columns)
{
    return ((row >= 0 && row < rows) && (column >= 0 && column < columns));
}

void dfs(vector<vector<int>> & image, int rows, int columns, int row, int column, int oldColor, int newColor)
{
    if(image[row][column]==oldColor)
    {
        image[row][column]=newColor;
    }

    if(isValid(row-1, column, rows, columns))
    {
        if(image[row-1][column]==oldColor && image[row-1][column]!=newColor)
        {
            dfs(image, rows, columns, row-1, column, oldColor, newColor);
        }
    }

    if(isValid(row+1, column, rows, columns))
    {
        if(image[row+1][column]==oldColor && image[row+1][column]!=newColor)
        {
            dfs(image, rows, columns, row+1, column, oldColor, newColor);
        }
    }

    if(isValid(row, column-1, rows, columns))
    {
        if(image[row][column-1]==oldColor && image[row][column-1]!=newColor)
        {
            dfs(image, rows, columns, row, column-1, oldColor, newColor);
        }
    }

    if(isValid(row, column+1, rows, columns))
    {
        if(image[row][column+1]==oldColor && image[row][column+1]!=newColor)
        {
            dfs(image, rows, columns, row, column+1, oldColor, newColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> & image, int sr, int sc, int newColor)
{
    if(image.empty())
    {
        return image;
    }

    int oldColor=image[sr][sc];

    int rows=int(image.size());

    int columns=int(image[0].size());

    dfs(image, rows, columns, sr, sc, oldColor, newColor);

    return image;
}

vector<vector<int>> floodFill(vector<vector<int>> & image, int sr, int sc, int newColor)
{
    if(image.empty())
    {
        return image;
    }

    int oldColor=image[sr][sc];

    int rows=int(image.size());

    int columns=int(image[0].size());

    stack<pair<int, int>> stk;

    stk.push(make_pair(sr, sc));

    while(!stk.empty())
    {
        auto current=stk.top();

        int row=current.first;

        int column=current.second;

        stk.pop();

        if(image[row][column]==oldColor)
        {
            image[row][column]=newColor;
        }

        if(isValid(row-1, column, rows, columns))
        {
            if(image[row-1][column]==oldColor && image[row-1][column]!=newColor)
            {
                stk.push(make_pair(row-1, column));
            }
        }

        if(isValid(row+1, column, rows, columns))
        {
            if(image[row+1][column]==oldColor && image[row+1][column]!=newColor)
            {
                stk.push(make_pair(row+1, column));
            }
        }

        if(isValid(row, column-1, rows, columns))
        {
            if(image[row][column-1]==oldColor && image[row][column-1]!=newColor)
            {
                stk.push(make_pair(row, column-1));
            }
        }

        if(isValid(row, column+1, rows, columns))
        {
            if(image[row][column+1]==oldColor && image[row][column+1]!=newColor)
            {
                stk.push(make_pair(row, column+1));
            }
        }
    }

    return image;
}