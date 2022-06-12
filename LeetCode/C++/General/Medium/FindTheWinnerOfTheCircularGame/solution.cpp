#include <iterator>
#include <list>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n * k)
Space complexity: O(n)
*/

class Solution
{
    public:
        int findTheWinner(int n, int k)
        {
            //List to represent the circle of friends
            list<int> circle;
            
            //Populate the list
            for(int number=1;number<=n;number++)
            {
                circle.push_back(number);
            }
            
            //Start with the first friend
            auto itr=begin(circle);
            
            //While there's at least two people in the circle
            while(circle.size() > 1)
            {   
                //Iterate through k friends
                for(int count=1;count<k;count++)
                {
                    itr++;
                    
                    //IMPORTANT: if the iterator reaches the end of the list, it needs to be reset to the beginning
                    if(itr==end(circle))
                    {
                        itr=begin(circle);
                    }
                }
                
                //Erase the friend
                //The erase function returns an iterator pointing to the element after the one that was just erased
                itr=circle.erase(itr);
                
                //If the element that was just erased was the last element in the list, we need to reset the iterator back to the beginning of the list
                if(itr==end(circle))
                {
                    itr=begin(circle);
                }
            }
            
            //Return the winner
            return circle.front();
        }
};