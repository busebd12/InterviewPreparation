#include <string>
#include <unordered_map>
using namespace std;

class FileSystem
{
    private:
        unordered_map<string, int> pathToValue;
    
    public:
        FileSystem()
        {
            
        }

        //Time complexity: O(p) [where p is the length of path]
        //Space complexity: O(t) [where t is the total number of paths]
        bool createPath(string path, int value)
        {
            if(pathToValue.find(path)!=end(pathToValue))
            {
                return false;
            }
            
            //Count the number of / characters in the path
            int slashes=count(begin(path), end(path), '/');
            
            //If there are more than one / characters, then we have to check to make sure that the parent part of the path exists
            if(slashes > 1)
            {
                auto lastSlashIndex=path.find_last_of('/');
            
                string parent=path.substr(0, lastSlashIndex);

                if(pathToValue.find(parent)==end(pathToValue))
                {
                    return false;
                }
            }
            
            pathToValue[path]=value;
            
            return true;
        }

        int get(string path)
        {   
            if(pathToValue.find(path)==end(pathToValue))
            {
                return -1;
            }
            
            return pathToValue[path];
        }
};
