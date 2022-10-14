#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
    public:
        int equalDigitFrequency(string s)
        {
            int result=0;
            
            int n=s.size();
            
            unordered_set<string> substrings;
            
            for(int i=0;i<n;i++)
            {   
                vector<int> hashtable(10, 0);
                
                for(int j=i;j<n;j++)
                {   
                    int digit=s[j] - '0';
                    
                    hashtable[digit]+=1;
                    
                    if(everyDigitAppearsTheSameNumberOfTimes(hashtable)==true)
                    {
                        string substring=s.substr(i, j - i + 1);
                        
                        substrings.insert(substring);
                    }
                }
            }
            
            result=substrings.size();
            
            return result;
        }
    
        bool everyDigitAppearsTheSameNumberOfTimes(vector<int> & hashtable)
        {
            int times=0;
            
            for(int index=0;index<10;index++)
            {
                if(hashtable[index] > 0)
                {
                    times=hashtable[index];
                    
                    break;
                }
            }
            
            for(int index=0;index<10;index++)
            {
                if(hashtable[index] > 0 and hashtable[index]!=times)
                {
                    return false;
                }
            }
            
            return true;
        }
};