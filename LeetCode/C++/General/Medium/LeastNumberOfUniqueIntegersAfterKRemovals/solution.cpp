#include <map>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n + (u log u) + O(fk))
[where n is the length of arr, u is the number of unique values in arr, f is the total number of frequencies]

Space complexity: O(u + f)
*/

class Solution
{
    public:
        int findLeastNumOfUniqueInts(vector<int> & arr, int k)
        {
            int result=0;
            
            //Map each number in arr to its frequency
            unordered_map<int, int> frequencies;
            
            //Create the frequency mappings
            for(int number : arr) //O(n)
            {
                frequencies[number]+=1;
            }
            
            //Map each frequency to all the numbers that have that frequency
            map<int, vector<int>> frequenciesToValues;
            
            //Create the mappings
            for(auto & [value, frequency] : frequencies) //O(u)
            {   
                frequenciesToValues[frequency].emplace_back(value); //O(log(u))
            }
            
            //Since std::map keeps its keys sorted in ascending order, we want to loop from the beginning of the map to ensure that we are targeting
            //values that have the lowest frequency possible and then move on to numbers with higher frequencies
            for(auto itr=begin(frequenciesToValues);itr!=end(frequenciesToValues);itr++) //O(f)
            {
                //Iterate through the numbers with the current frequency
                for(int number : itr->second)
                {
                    //While k is greater than zero and the frequency of the current number is greater than zero
                    while(k > 0 && frequencies[number] > 0) //O(k)
                    {
                        frequencies[number]-=1;
                        
                        k-=1;
                    }
                    
                    if(k==0)
                    {
                        //If the frequency of the current number is zero
                        if(frequencies[number]==0)
                        {
                            //Erase it from the frequencies map (representing erasing it from the input array)
                            frequencies.erase(number);
                        }
                        
                        break;
                    }
                    //Else, k is greater than zero but the frequency of the current number is zero
                    else
                    {
                        //Erase it from the frequencies map (representing erasing it from the input array)
                        frequencies.erase(number);
                    }
                }
                
                if(k==0)
                {
                    break;
                }
            }
            
            //Since std::unordered_map only allows unique keys, and we are using the array values as keys, all the remaining
            //keys in the frequencies map represent the remaining unique elements in the array
            result+=frequencies.size();
            
            return result;
        }
};

/*
Solution: see comments.

Time complexity: O(n + (u log u) + O(fk))
[where n is the length of arr, u is the number of unique values in arr, f is the total number of frequencies]

Space complexity: O(u + f)
*/

class Solution
{
    public:
        int findLeastNumOfUniqueInts(vector<int> & arr, int k)
        {
            int result=0;
            
            //Map each number in arr to its frequency
            unordered_map<int, int> frequencies;
            
            //Create the frequency mappings
            for(int number : arr)
            {
                frequencies[number]+=1;
            }
            
            //Custom comparison for the min heap
            auto compareLikeThis=[] (pair<int, int> & lhs, pair<int, int> & rhs)
            {
                if(lhs.first==rhs.first)
                {
                    return lhs.second > rhs.second;
                }
                else
                {
                    return lhs.first > rhs.first;
                }
            };
            
            //Minimum heap of pairs - where each pair represents {frequency, value}
            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compareLikeThis)> minHeap(compareLikeThis);
            
            //Populate the min heap
            for(auto & [value, frequency] : frequencies)
            {
                minHeap.emplace(frequency, value);
            }
            
            while(!minHeap.empty())
            {
                auto [frequency, value]=minHeap.top();
                
                minHeap.pop();
                
                //While k is greater than zero and the frequency of the current number is greater than zero
                while(k > 0 && frequency > 0)
                {
                    k-=1;
                    
                    //Decrement the frequency of the current number
                    frequency-=1;
                }
                
                if(k==0)
                {
                    //Only add the number back into the heap if its frequency is greater than zero
                    if(frequency > 0)
                    {
                        minHeap.emplace(frequency, value);
                    }
                    
                    break;
                }
            }
            
            //The remaining elements in the heap represent the remaining unique elements in the array
            result+=minHeap.size();
            
            return result;
        }
};