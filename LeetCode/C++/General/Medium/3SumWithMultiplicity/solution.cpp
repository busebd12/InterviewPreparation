#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution 1: see comments

Time complexity: O(n^3) [where n is the length of arr]
Space complexity: O(u) [where u is the number of unique triplets that have sum equal to target]
*/

class Solution
{
    public:
        int threeSumMulti(vector<int> & arr, int target)
        {
            int result=0;
            
            int modulo=1000000007;
            
            //Keep track of the frequencies of each triplet
            unordered_map<string, int> frequencies;
            
            int n=arr.size();
            
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    for(int k=j+1;k<n;k++)
                    {
                        int sum=arr[i] + arr[j] + arr[k];
                        
                        //If the sum equals our target
                        if(sum==target)
                        {
                            //Create unique key for the sum
                            string key=to_string(arr[i]) + "$" + to_string(arr[j]) + "$" + to_string(arr[k]);
                            //Increment the frequency of the key
                            frequencies[key]++;
                        }
                    }
                }
            }
            
            for(auto & [key, frequency] : frequencies)
            {
                //Add the frequency of each key to the result
                result+=frequency;
                
                //Mod the result
                result=result % modulo;
            }
            
            return result;
        }
};

/*
Solution 2: see comments.

Time complexity: O(n^2) [where n is the length of arr]
Space complexity: O(u) [where u is the number of unique numbers in arr]
*/

class Solution
{
    public:
        int threeSumMulti(vector<int> & arr, int target)
        {
            int result=0;
            
            int modulo=1000000007;
            
            unordered_map<int, int> frequencies;
            
            int n=arr.size();
            
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    //Value we are looking for in the array
                    int value=target - arr[i] - arr[j];
                    
                    //If we find the value in the array
                    if(frequencies.count(value))
                    {
                        //Add the frequency of the value to the result   
                        result+=frequencies[value];
                    }
                }
                
                frequencies[arr[i]]++;
                
                result=result % modulo;
            }
            
            return result;
        }
};