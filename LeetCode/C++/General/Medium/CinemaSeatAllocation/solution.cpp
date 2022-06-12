#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(r) [where r is the size of reservedSeats]
Space complexity: O(r)
*/

class Solution
{
    public:
        int getNumberOfGroups(vector<int> & row)
        {
            int numberOfGroups=0;
            
            //Calculate the sum of the row
            int rowSum=accumulate(begin(row), end(row), 0);
            
            //If the sum is zero, then the vector only contains zeros and we can fit two groups of four in the row
            if(rowSum==0)
            {
                numberOfGroups+=2;
            }
            //Else, some seats are taken
            else
            {
                bool canSitInFirstSection=false;
            
                bool canSitInLastSection=false;

                //Calculate the sum of seats 2-5
                int firstSectionSum=accumulate(begin(row) + 1, begin(row) + 5, 0);

                //If the sum is zero, then we can fit a group of four in those seats
                if(firstSectionSum==0)
                {
                    numberOfGroups+=1;

                    canSitInFirstSection=true;
                }

                //Calculate the sum of seats 6-9
                int lastSectionSum=accumulate(begin(row) + 5, begin(row) + 9, 0);
                
                //If the sum is zero, then we can fit a group of four in those seats
                if(lastSectionSum==0)
                {
                    numberOfGroups+=1;

                    canSitInLastSection=true;
                }

                //ONLY if we can use seats 2-5 and seats 6-9 do we consider using seats 4-7
                if(canSitInFirstSection==false && canSitInLastSection==false)
                {
                    //Calculate the sum of the middle section seats
                    int middleSectionSum=accumulate(begin(row) + 3, begin(row) + 7, 0);

                    //If the sum is zero, then we can fit a group of four in the middle section
                    if(middleSectionSum==0)
                    {
                        numberOfGroups+=1;
                    }
                }
            }
            
            return numberOfGroups;
        }
    
        int maxNumberOfFamilies(int n, vector<vector<int>> & reservedSeats)
        {
            int result=0;
            
            //Since the test case with n=one million exceeds the memory allocation limit for c++, we will take the maximmum row from reservedSeats to be the number of rows
            int rows=-1;
            
            for(vector<int> & seat : reservedSeats)
            {
                int row=seat[0];
                
                rows=max(row, rows);
            }
            
            //Total seats in the theater
            //Each vector is a row
            vector<vector<int>> seats(rows, vector<int>(10, 0));
            
            for(vector<int> & seat : reservedSeats)
            {
                int row=seat[0] - 1;
                
                int column=seat[1] - 1;
                
                seats[row][column]=1;
            }
            
            for(vector<int> & row : seats)
            {
                int numberOfGroups=getNumberOfGroups(row);
                
                result+=numberOfGroups;
            }
            
            //IMPORTANT: if the number of rows is less than n, then you need to account for how many groups of four can sit in all those empty rows
            int difference=n - rows;
            
            int groupsFromEmptyRows=difference * 2;
            
            result+=groupsFromEmptyRows;
            
            return result;
        }
};

/*
Solution: see comments.

Time complexity: O(r) [where r is the size of reservedSeats]
Space complexity: O(r)
*/

class Solution
{
    public:
        int maxNumberOfFamilies(int n, vector<vector<int>> & reservedSeats)
        {
            int result=0;
            
            unordered_map<int, unordered_set<int>> rows;
            
            int maxReservedSeatsRow=-1;
            
            for(vector<int> & seat : reservedSeats)
            {
                int row=seat[0];
                
                int column=seat[1];
                
                rows[row].insert(column);
                
                maxReservedSeatsRow=max(maxReservedSeatsRow, row);
            }
            
            for(auto & [row, takenSeats] : rows)
            {
                bool canSitInFirstSection=true;

                //If seat 2 or 3 or 4 or 5 is taken, then a group of four can't sit in the first section
                if(takenSeats.find(2)!=end(takenSeats) || takenSeats.find(3)!=end(takenSeats) || takenSeats.find(4)!=end(takenSeats) || takenSeats.find(5)!=end(takenSeats))
                {
                    canSitInFirstSection=false;
                }

                if(canSitInFirstSection==true)
                {
                    result+=1;
                }

                bool canSitInThirdSection=true;

                //If seat 6 or 7 or 8 or 9 is taken, then a group of four can't sit in the third section
                if(takenSeats.find(6)!=end(takenSeats) || takenSeats.find(7)!=end(takenSeats) || takenSeats.find(8)!=end(takenSeats) || takenSeats.find(9)!=end(takenSeats))
                {
                    canSitInThirdSection=false;
                }

                if(canSitInThirdSection==true)
                {
                    result+=1;
                }

                //ONLY if the first and third section are not available do we check the middle section
                if(canSitInFirstSection==false && canSitInThirdSection==false)
                {
                    bool canSitInMiddleSection=true;

                    //If seat 4 or 5 or 6 or 7 is taken, then a group of four can't sit in the middle section
                    if(takenSeats.find(4)!=end(takenSeats) || takenSeats.find(5)!=end(takenSeats) || takenSeats.find(6)!=end(takenSeats) || takenSeats.find(7)!=end(takenSeats))
                    {
                        canSitInMiddleSection=false;
                    }

                    if(canSitInMiddleSection==true)
                    {
                        result+=1;
                    }
                }
            }
            
            //IMPORTANT: if the number of rows is less than n, then you need to account for how many groups of four can sit in the remaining, empty rows
            int leftOverRows=n - rows.size();
            
            int groupsFromEmptyRows=leftOverRows * 2;
            
            result+=groupsFromEmptyRows;
            
            return result;
        }
};