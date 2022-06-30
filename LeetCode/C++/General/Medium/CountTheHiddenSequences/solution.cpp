#include <algorithm>
#include <vector>
using namespace std;

/*
Solution 1: brute force. Note, this solution receives Time Limit Exceeded when executed.
*/

class Solution
{
    public:
        int numberOfArrays(vector<int> & differences, int lower, int upper)
        {
            int result=0;
            
            int d=differences.size();
            
            vector<vector<int>> arrays=getArrays(differences[0], lower, upper);
            
            for(vector<int> & arr : arrays)
            {
                if(isValidHiddenSequence(differences, arr, d, lower, upper)==true)
                {
                    result+=1;
                }
            }
            
            return result;
        }
    
        vector<vector<int>> getArrays(int difference, int lower, int upper)
        {
            vector<vector<int>> arrays;
            
            for(int number=lower;number<=upper;number++)
            {   
                int next=number + difference;
                
                if(lower <= next && next <= upper)
                {
                    vector<int> arr;
                
                    arr.push_back(number);

                    arr.push_back(next);
                    
                    arrays.push_back(arr);
                }
            }
            
            return arrays;
        }
    
        bool isValidHiddenSequence(vector<int> & differences, vector<int> & arr, int d, int lower, int upper)
        {
            for(int index=1;index<d;index++)
            {
                int difference=differences[index];
                
                int next=arr.back() + difference;
                
                if(lower <= next && next <= upper)
                {
                    arr.push_back(next);
                }
                else
                {
                    return false;
                }
            }
            
            return true;
        }
};

/*
Solution 2: inspired by this post --> https://leetcode.com/problems/count-the-hidden-sequences/discuss/1709790/C%2B%2B-Java-Dry-run-steps-for-easy-understanding-observational-type
*/

class Solution
{
    public:
        int numberOfArrays(vector<int> & differences, int lower, int upper)
        {
            long long int result=0;
            
            int d=differences.size();
            
            vector<long long int> sequence={lower};
            
            long long int minValue=lower;
            
            for(int index=0;index<d;index++)
            {
                long long int next=sequence.back() + differences[index];
                
                sequence.push_back(next);
                
                minValue=min(minValue, next);
            }
            
            int add=lower - minValue;
            
            for(long long int & number : sequence)
            {
                number+=add;
            }
            
            for(long long int & number : sequence)
            {
                if(number < lower || number > upper)
                {
                    return result;
                }
            }
            
            long long int maxValue=*(max_element(begin(sequence), end(sequence)));
            
            long long int numberOfOtherArrays=upper - maxValue;
            
            result=numberOfOtherArrays + 1;
            
            return result;
        }
};