#include <algorithm>
#include <string>
using namespace std;

/*
Solution 1: see comments.

Time complexity: O(v1 + v2) [where v1 is length of version1 and v2 is the length of version2]
Space complexity: O(v1 + v2);
*/

class Solution
{
    public:
        int compareVersion(string version1, string version2)
        {
            int result=0;
            
            int version1Periods=count(begin(version1), end(version1), '.');
            
            int version2Periods=count(begin(version2), end(version2), '.');
            
            //If version1 has less . than version2, keep adding .0 to the end of version1 until it has the same number of . as version2
            while(version1Periods < version2Periods)
            {
                version1.push_back('.');
                
                version1.push_back('0');
                
                version1Periods=count(begin(version1), end(version1), '.');
            }
            
            //If version2 has less . than version1, keep adding .0 to the end of version2 until it has the same number of . as version1
            while(version2Periods < version1Periods)
            {
                version2.push_back('.');
                
                version2.push_back('0');
                
                version2Periods=count(begin(version2), end(version2), '.');
            }
            
            //Stringstream objects to assist in tokenizing version1 and version2 by the . character
            stringstream version1SS(version1);
            
            stringstream version2SS(version2);
            
            char delimiter='.';
            
            string version1Revision{};
            
            string version2Revision{};
            
            while(getline(version1SS, version1Revision, delimiter) && getline(version2SS, version2Revision, delimiter))
            {
                if(!version1Revision.empty() && !version2Revision.empty())
                {
                    int n=version1Revision.size();
                    
                    int m=version2Revision.size();
                    
                    int i=0;
                    
                    int j=0;
                    
                    //If an individual revision of version1 has leading zeros
                    if(n > 1 && version1Revision[0]=='0')
                    {
                        //Skip leading zeros
                        while(i < n && version1Revision[i]=='0')
                        {
                            i++;
                        }
                    }
                    
                    //if an individual revision of version2 has leading zeros
                    if(m > 1 && version2Revision[0]=='0')
                    {
                        //Skip leading zeros
                        while(j < m && version2Revision[j]=='0')
                        {
                            j++;
                        }
                    }
                    
                    //If the version1 and version2 revisions have other digits than just leading zeros
                    if(i < n && j < m)
                    {
                        int version1Part=stoi(version1Revision.substr(i, string::npos));
                    
                        int version2Part=stoi(version2Revision.substr(j, string::npos));

                        if(version1Part > version2Part)
                        {
                            return 1;
                        }
                        else if(version1Part < version2Part)
                        {
                            return -1;
                        }
                    }
                }
            }
            
            return result;
        }
};

/*
Solution 2: similar to the first solution but without the use of stringstream objects.

Time complexity: O(v1 + v2)
Space complexity: O(1)
*/

class Solution
{
    public:
        int compareVersion(string version1, string version2)
        {
            int result=0;
            
            int version1Periods=count(begin(version1), end(version1), '.');
            
            int version2Periods=count(begin(version2), end(version2), '.');
            
            while(version1Periods < version2Periods)
            {
                version1.push_back('.');
                
                version1.push_back('0');
                
                version1Periods=count(begin(version1), end(version1), '.');
            }
            
            while(version2Periods < version1Periods)
            {
                version2.push_back('.');
                
                version2.push_back('0');
                
                version2Periods=count(begin(version2), end(version2), '.');
            }
            
            int n=version1.size();
            
            int m=version2.size();
            
            int i=0;
            
            int j=0;
            
            while(i < n && j < m)
            {
                long version1Revision=0;
                
                long version2Revision=0;
                
                while(i < n && version1[i]!='.')
                {
                    version1Revision=(version1Revision * 10) + version1[i] - '0';
                    
                    i++;
                }
                
                while(j < m && version2[j]!='.')
                {
                    version2Revision=(version2Revision * 10) + version2[j] - '0';
                    
                    j++;
                }
                
                if(version1Revision > version2Revision)
                {
                    return 1;
                }
                else if(version1Revision < version2Revision)
                {
                    return -1;
                }
                
                i++;
                
                j++;
            }
            
            return 0;
        }
};