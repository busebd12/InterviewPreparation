#include <algorithm>
#include <cmath>
#include <vector>

/*
Solutions: inspired by this post --> https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/discuss/693835/C%2B%2B-Thinking-process-and-implementation-from-brute-force-to-binary-search
*/

class Solution
{
    public:
        bool canShip(vector<int> & weights, int days, int capacity)
        {
            int numberOfDays=1;
            
            int currentWeight=0;
            
            for(auto & weight : weights)
            {
                currentWeight+=weight;
                
                if(currentWeight > capacity)
                {
                    numberOfDays+=1;
                    
                    if(numberOfDays > days)
                    {
                        return false;
                    }
                    
                    currentWeight=weight;
                }
            }
            
            return true;
        }
    
        int shipWithinDays(vector<int> & weights, int days)
        {   
            int w=weights.size();
            
            int totalWeight=accumulate(begin(weights), end(weights), 0);
            
            int maxWeight=*(max_element(begin(weights), end(weights)));
            
            int minCapacity=max(maxWeight, (int)ceil(double(totalWeight) / days));
            
            while(canShip(weights, days, minCapacity)==false)
            {
                minCapacity+=1;
            }
            
            return minCapacity;
        }
};

class Solution
{
    public:
        bool canShip(vector<int> & weights, int days, int capacity)
        {
            int numberOfDays=1;
            
            int currentWeight=0;
            
            for(auto & weight : weights)
            {
                currentWeight+=weight;
                
                if(currentWeight > capacity)
                {
                    numberOfDays+=1;
                    
                    if(numberOfDays > days)
                    {
                        return false;
                    }
                    
                    currentWeight=weight;
                }
            }
            
            return true;
        }
    
        int shipWithinDays(vector<int> & weights, int days)
        {
            int result=0;
            
            int w=weights.size();
            
            int totalWeight=accumulate(begin(weights), end(weights), 0);
            
            int maxWeight=*(max_element(begin(weights), end(weights)));
                            
            int minCapacity=max(maxWeight, (int)ceil(double(totalWeight) / days));
            
            int left=minCapacity;
            
            int right=totalWeight;
            
            while(left <= right)
            {
                int middle=(left + (right - left)/2);
                
                if(canShip(weights, days, middle))
                {
                    result=middle;
                    
                    right=middle - 1;
                }
                else
                {
                    left=middle + 1;
                }
            }
            
            return result;
        }
};