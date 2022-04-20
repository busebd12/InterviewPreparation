#include <string>
#include <stringstream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n * l) [where n is the number of paths and l is the average length of a path]
Space complexity: O(n)

*/

class Solution
{
    public:
        vector<vector<string>> findDuplicate(vector<string> & paths)
        {
            vector<vector<string>> result;
            
            //Map contents of files to list of pairs
            //Each pair is composed of the directory path to the file and the file name
            unordered_map<string, vector<pair<string, string>>> hashtable;
            
            for(auto path : paths)
            {
                stringstream ss(path);
                
                string token{};
                
                char delimiter=' ';
                
                string directoryPath{};
                
                while(getline(ss, token, delimiter))
                {   
                    if(!token.empty())
                    {
                        //Directory path part
                        if(token.find('.')==string::npos)
                        {
                            directoryPath=token;
                        }
                        //File name and contents part
                        else
                        {
                            auto openParenIndex=token.find('(');
                            
                            auto closingParenIndex=token.find(')');
                            
                            //Stuff between the parenthesis
                            string contents=token.substr(openParenIndex + 1, (closingParenIndex - openParenIndex) - 1);

                            string fileName=token.substr(0, openParenIndex);
                            
                            //If the hashtable doesn't have the file contents as a key yet
                            if(hashtable.find(contents)==end(hashtable))
                            {
                                hashtable[contents]=vector<pair<string, string>>();
                            }
                            
                            //Map the file contents to its directory path and file name
                            hashtable[contents].emplace_back(directoryPath, fileName);
                        }
                    }
                }
            }
            
            for(auto & [contents, pairs] : hashtable)
            {
                //The file contents appeared in more than one file, so duplicate files
                if(pairs.size() > 1)
                {   
                    vector<string> paths;
                    
                    for(auto & [directoryPath, filename] : pairs)
                    {
                        string fullpath=directoryPath + "/" + filename;
                        
                        paths.emplace_back(fullpath);
                    }
                    
                    result.emplace_back(paths);
                }
            }
            
            return result;
        }
};