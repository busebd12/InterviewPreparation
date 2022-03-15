#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: see comments for details

Time complexity: O(n log n) [where n is the number of values in the changed array]
Space complexity: O(u) [where u is the number of unique elements in the changed array]
*/

class Solution
{
    public:
        vector<int> findOriginalArray(vector<int> & changed)
        {
            vector<int> original;
            
            int c=changed.size();
            
            //If the changed array has odd size, then it can't be a valid changed array because the original array's size was doubled,
            //making the changed array's size always even
            if((c % 2)==1)
            {
                return original;
            }

            //Hashtable used to keep track of the frequency for each element in the changed array
            unordered_map<int, int> hashtable;
            
            //Calculate the frequencies
            for(int number : changed)
            {
                hashtable[number]++;
            }
            
            //Need to sort so that we start from the smallest number and work our way up to the largest
            sort(begin(changed), end(changed));
            
            //Iterate through each number in the changed array
            for(int number : changed)
            {
                //If the hashtable contains the number, the frequency of the number is not zero, and the frequency of its doubled value is not zero,
                //then we know that the current number was one of the numbers from the original array
                if(hashtable.count(number) && hashtable[number]!=0 && hashtable[number * 2]!=0)
                {
                    hashtable[number]--;
                    
                    hashtable[number * 2]--;
                    
                    original.emplace_back(number);
                }
            }
            
            //Iterate through the hashtable
            for(const auto & element : hashtable)
            {
                //If we find a number that has a frequency not equal to zero, then we know that this array is not a valid changed array
                //since we could form pairs of numbers from the changed array: <original number, original number doubled>
                //So, this number doesn't belong to a pair
                if(element.second!=0)
                {
                    return vector<int>();
                }
            }
            
            return original;
        }
};