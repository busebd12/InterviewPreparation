#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class SnapshotArray
{
    public:
        //Map each snap id to an unordered_map<int, int> that holds an index, value pair
    `   //snap id --> {{index, value}, {index, value}}
        vector<unordered_map<int, int>> maps;
    
        int snapId;
    
        SnapshotArray(int length)
        {
            //Add empty map to account for the zero-th snap id
            maps.emplace_back(unordered_map<int, int>());
            
            snapId=0;
        }

        void set(int index, int val)
        {
            //Create the snap id --> {index, val} mapping
            maps[snapId][index]=val;
        }

        int snap()
        {
            snapId++;
            
            //Each time we increment the snap id, we have to add a new map to the vector to account for the increase
            maps.emplace_back(unordered_map<int, int>());
            
            return snapId-1;
        }

        int get(int index, int snap_id)
        {
            int result=0;
            
            //Iterate through the snap ids
            for(int snapid=snap_id;snapid>=0;snapid--)
            {
                //If the map pointed to by the snap id has the index as a key
                if(maps[snapid].count(index))
                {
                    //The result will be the value of that key
                    result=maps[snapid][index];
                    
                    break;
                }
            }
            
            return result;
        }
};