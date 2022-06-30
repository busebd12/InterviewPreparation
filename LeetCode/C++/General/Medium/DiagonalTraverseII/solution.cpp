#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <utility>
#include <vector>
using namespace std;

/*
Solution 1: see comments. Note: this solution receives Time Limit Exceeded when executed.

Time complexity: O(rows * largest number of columns)
Space complexity: O(rows * largest number of columns)
*/

class Solution
{
    public:
        vector<int> findDiagonalOrder(vector<vector<int>> & nums)
        {
            vector<int> result;
            
            int rows=nums.size();
            
            int columns=0;
            
            //Since all the rows of the grid are not the same size,
            //let's find the row with the longest length and add 0s
            //to the ends of the other rows until all rows have the same length
            for(vector<int> & row : nums)
            {
                columns=max(columns, int(row.size()));
            }
            
            //Iterate through the rows
            for(vector<int> & row : nums)
            {
                //Add 0s to the current row until it is the same length as the longest row
                while(row.size() < columns)
                {
                    row.emplace_back(0);
                }
            }
            
            //Iterate through all the rows
            for(int row=0;row<rows;row++)
            {
                int r=row;
                
                int column=0;
                
                //Traverse diagonally starting from the number in the first column in each row
                while(r >= 0 && column < columns)
                {
                    //Since we padded all the rows with 0s, only add numbers that are greater than zero
                    if(nums[r][column] > 0)
                    {
                        result.push_back(nums[r][column]);
                    }
                    
                    r-=1;
                    
                    column+=1;
                }
            }
            
            //Iterate through all the columns, starting with the second one, in the last row
            for(int column=1;column<columns;column++)
            {
                int row=rows - 1;
                
                int c=column;
                
                //Traverse diagonally starting from the last number in each column 
                while(row >= 0 && c < columns)
                {
                    //Since we padded all the rows with 0s, only add numbers that are greater than zero
                    if(nums[row][c] > 0)
                    {
                        result.push_back(nums[row][c]);
                    }
                    
                    row-=1;
                    
                    c+=1;
                }
            }
            
            return result;
        }
};

/*
Solution 2: see comments.
*/

class Solution
{
    public:
        vector<int> findDiagonalOrder(vector<vector<int>> & nums)
        {
            vector<int> result;
            
            int rows=nums.size();
            
            //Map the sum composed of (row + column) to all pairs of (row, column) which add up to that sum
            //All (row, column) pairs that share a common sum will all be on the same diagonal
            //Note: since we are traversing diagonally from the lower left-hand corner to the upper right-hand corner, we need to
            //use std::greater<pair<int, int>> (instead of the default std::less<pair<int, int>>) so that the (row, column) pairs
            //will be sorted in increasing order based on the row
            map<int, set<pair<int, int>, greater<pair<int, int>>>> hashtable;
            
            //Populate the hashtable
            for(int row=0;row<rows;row++) //O(rows)
            {
                hashtable.emplace(row, set<pair<int, int>, greater<pair<int, int>>>()); //O(log(row))
            }
            
            for(int row=0;row<rows;row++) //O(rows)
            {
                for(int column=0;column<nums[row].size();column++) //O(column) [where column is the average number of columns]
                {
                    int rowColumnSum=row + column;
                    
                    //Add create the row + column sum to (row, column) mapping
                    hashtable[rowColumnSum].emplace(row, column); //O(log(t))
                }
            }
            
            //For each row + column sum
            for(auto & [rowColumnSum, coordinates] : hashtable) //O(rows)
            {
                //For each (row, column) coordinate
                for(auto & [row, column] : coordinates) //O(column)
                {
                    //Add the value to the result
                    result.push_back(nums[row][column]);
                }
            }
            
            return result;
        }
};