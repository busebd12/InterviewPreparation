#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n));
    
    if(n==0)
    {
        return matrix;
    }
    
    int rowStart=0;
    
    int rowEnd=n-1;
    
    int columnStart=0;
    
    int columnEnd=n-1;
    
    int number=1;
    
    while(rowStart <= rowEnd && columnStart <= columnEnd)
    {
        //traverse the top row
        for(int i=columnStart;i<=columnEnd;++i)
        {
            matrix[rowStart][i]=number++;
        }
        
        ++rowStart;
        
        //traverse down the right-side
        for(int i=rowStart;i<=rowEnd;++i)
        {
            matrix[i][columnEnd]=number++;
        }
        
        --columnEnd;
        
        //traverse the bottom row
        for(int i=columnEnd;i>=columnStart;--i)
        {
           matrix[rowEnd][i]=number++; 
        }
        
        --rowEnd;
        
        //traverse up the left-side
        for(int i=rowEnd;i>=rowStart;--i)
        {
            matrix[i][columnStart]=number++;
        }
        
        ++columnStart;
    }
    
    return matrix;
}