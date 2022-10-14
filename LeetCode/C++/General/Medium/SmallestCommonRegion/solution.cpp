#include <deque>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(r + h) [where r is the total number of regions and h is the height of the n-ary tree formed by the regions]
Space complexity: O(r)
*/

class Solution
{
    public:
        string findSmallestRegion(vector<vector<string>> & regions, string region1, string region2)
        {
            string result="";
            
            //If you notice, the regions can be viewed as a graph.
            //Specifically, a N-ary tree (a directed acyclic graph).
            //So, we map each child region to its parent region
            unordered_map<string, string> childToParent;
            
            for(vector<string> & region : regions)
            {
                for(int i=1;i<region.size();i++)
                {
                    childToParent.emplace(region[i], region[0]);
                }
            }
            
            //Map the root region to a fictitious parent
            childToParent.emplace(regions[0][0], "nullptr");
            
            //Path from the first region to the root of the N-ary tree
            deque<string> region1Path;
            
            //The region we start at in the N-ary tree
            string region=region1;
            
            //While the region's parent can be found in the childToParent map
            while(childToParent.find(region)!=end(childToParent))
            {
                //Add the region to the path
                region1Path.push_front(region);
                
                //Move "up" in the tree to the current region's parent
                region=childToParent[region];
            }
            
            //Path from the second region to the root of the N-ary tree
            deque<string> region2Path;
            
            //The region we start at in the N-ary tree
            region=region2;
            
            //While the region's parent can be found in the childToParent map
            while(childToParent.find(region)!=end(childToParent))
            {
                //Add the region to the path
                region2Path.push_front(region);
                
                //Move "up" in the tree to the current region's parent
                region=childToParent[region];
            }
            
            //Now, we start at the root node in the N-ary tree and walk along both paths until we reach the last common ancestor for both regions
            while(!region1Path.empty() and !region2Path.empty() and region1Path.front()==region2Path.front())
            {
                result=region1Path.front();
                
                region1Path.pop_front();
                
                region2Path.pop_front();
            }
            
            return result;
    }
};