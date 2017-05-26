#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;

class IncrementAndDoubling
{
    public:
        int getMinHelper(vector<int> DesiredArray, int Moves)
        {
            if(all_of(begin(DesiredArray), end(DesiredArray), [] (const int & element) {return element==0;}))
            {   
                return Moves;
            }
            
            if(all_of(begin(DesiredArray), end(DesiredArray), [] (int & element) {return element%2==0;}))
            {   
                for(auto & element : DesiredArray)
                {
                    element/=2;
                }
                
                Moves++;
            }
            else
            {   
                for(auto & element : DesiredArray)
                {
                    if(element%2==1)
                    {
                        element--;
                        
                        Moves++;
                    }
                }
            }
            
            return getMinHelper(DesiredArray, Moves);
        }

        int getMin(vector<int> DesiredArray)
        {   
            int moves{};
            
            int result=getMinHelper(DesiredArray, moves);
            
            return result;
        }
};