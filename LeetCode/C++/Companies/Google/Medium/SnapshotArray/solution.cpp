#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class SnapshotArray
{
    public:
        vector<unordered_map<int, int>> vec;
        
        int snapId;
        
        SnapshotArray(int length)
        {
            //initialise vec vector with an empty map so this map at the 0th index of of vec can have changes added to it in set()
            vec.push_back(unordered_map<int, int>());
            
            snapId=0;
        }
        
        void set(int index, int val)
        {
            //create a key value pair in the vc[snaps] map showing: value at <index> was set to <val>
            vec[snapId][index]=val;
        }
        
        int snap()
        {
            snapId++;
            
            //every time a new snap is created, we push an empty map into our vc vector to add key value pairs to it later in set()
            vec.push_back(unordered_map<int, int>());
            
            return snapId-1;
        }
        
        int get(int index, int snap_id)
        {
            int value=0;
            
            /*traverse the map backwards from the given snap_id and look for the latest change to the value at <index>
            for example if we have { {0: 15}, {}, {0: 12}, {1 : 10} } and index = 0, snap_id = 3. 
            we would check {1: 10} and notice no changes to the 0th index then we would go to {0: 12} and notice a change.
            this is our latest change so we can immidiately return this value*/

            for(int snapid=snap_id;snapid>=0;snapid--)
            {
                if(vec[snapid].count(index))
                {
                    value=vec[snapid][index];
                    
                    break;
                }
            }
            
            return value;
        }
};