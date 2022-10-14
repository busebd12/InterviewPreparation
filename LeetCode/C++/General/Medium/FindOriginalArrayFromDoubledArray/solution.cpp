#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Time complexity: O(n + (n log n) + n)
Space complexity: O(u) [where u is the number of unique values in changed]
*/

class Solution
{
    public:
        vector<int> findOriginalArray(vector<int> & changed)
        {
            vector<int> result;
            
            int n=changed.size();
            
            if((n % 2)==1)
            {
                return result;
            }
            
            unordered_map<int, int> frequencies;
            
            for(int & number : changed)
            {
                frequencies[number]+=1;
            }
            
            sort(begin(changed), end(changed));
            
            for(int & number : changed)
            {   
                int halved=number / 2;
                
                int doubled=number * 2;
                
                //If the current number has already been matched with either its doubled or halved value
                if(frequencies.find(number)==end(frequencies))
                {
                    continue;
                }
                
                //Special case: 0
                //0 * 2 and 0 / 2 will be zero, so there needs to be at least two of them left at this point
                if(number==halved or number==doubled)
                {
                    if(frequencies[number] >= 2)
                    {   
                        result.push_back(number);
                        
                        frequencies[number]-=2;
                        
                        if(frequencies[number]==0)
                        {
                            frequencies.erase(number);
                        }
                    }
                }
                else
                {
                    //Assume current number is the doubled value and try to find the corresponding half value
                    if(frequencies.find(halved)!=end(frequencies) and (halved * 2)==number)
                    {   
                        result.push_back(halved);

                        frequencies[halved]-=1;

                        if(frequencies[halved]==0)
                        {
                            frequencies.erase(halved);
                        }

                        frequencies[number]-=1;
                        
                        if(frequencies[number]==0)
                        {
                            frequencies.erase(number);
                        }
                    }
                    //Assume value is the original and check to make sure the doubled version is available
                    else if(frequencies.find(doubled)!=end(frequencies))
                    {   
                        result.push_back(number);
                        
                        frequencies[number]-=1;

                        if(frequencies[number]==0)
                        {
                            frequencies.erase(number);
                        }

                        frequencies[doubled]-=1;
                        
                        if(frequencies[doubled]==0)
                        {
                            frequencies.erase(doubled);
                        }
                    }
                }
            }
            
            //YAY, result is exactly half the size of the original array, just what we want!
            if(result.size()==n/2)
            {
                return result;
            }
            
            //Womp womp, invalid result, so remove all elements
            result.clear();
            
            return result;
        }
};