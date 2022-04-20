#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<string> getFolderNames(vector<string> & names)
        {
            int n=names.size();
            
            vector<string> result(n, "");
            
            //Cache to hold already seen file names
            unordered_set<string> cache;
            
            for(int i=0;i<n;i++)
            {
                string name=names[i];
                
                //If the cache doesn't have the name, add it to the cache
                if(!cache.count(name))
                {
                    cache.insert(name);
                    
                    result[i]=name;
                }
                //Else, we've seen the file name before
                else
                {   
                    //Create the initial suffix
                    int k=1;
                    
                    string suffix="(" + to_string(k) + ")";
                    
                    //Add the suffix to the file name
                    name+=suffix;
                    
                    //While we've seen the file name already
                    while(cache.count(name))
                    {
                        //Remove the suffix
                        while(!name.empty() && name.back()!='(')
                        {
                            name.pop_back();
                        }
                        
                        name.pop_back();
                        
                        //Create and add the next suffix
                        k++;
                        
                        suffix="(" + to_string(k) + ")";
                        
                        name+=suffix;
                    }
                    
                    //Add the new file name to the cache
                    cache.insert(name);
                    
                    result[i]=name;
                }
            }
            
            return result;
        }
};

class Solution
{
    public:
        vector<string> getFolderNames(vector<string> & names)
        {
            int n=names.size();
            
            vector<string> result(n, "");
            
            //Cache to hold already seen file names
            unordered_map<string, int> cache;
            
            for(int i=0;i<n;i++)
            {
                string name=names[i];
                
                //If the cache doesn't have the name, add it to the cache
                if(!cache.count(name))
                {
                    cache[name]=0;
                    
                    result[i]=name;
                }
                //Else, we've seen the file name before
                else
                {   
                    //Increment the number of times we've seen the filename
                    cache[name]+=1;
                    
                    //Create the initial suffix
                    int k=cache[name];
                    
                    string suffix="(" + to_string(k) + ")";
                    
                    //Add the suffix to the current file name
                    name+=suffix;
                    
                    //While we've seen the file name already
                    while(cache.count(name))
                    {
                        //Remove the current suffix from the file name
                        while(!name.empty() && name.back()!='(')
                        {
                            name.pop_back();
                        }
                        
                        name.pop_back();
                        
                        //Create the next suffix
                        k++;
                        
                        suffix="(" + to_string(k) + ")";
                        
                        //Add the next suffix to the file name
                        name+=suffix;
                    }
                    
                    //Add the new file name to the cache
                    cache[name]=0;
                    
                    result[i]=name;
                }
            }
            
            return result;
        }
};