#include <vector>
using namespace std;

/*
See this post for more details --> https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/discuss/656213/O(1)-solution-with-COMPLETE-analysis

Time complexity: O(1)
Space complexity: O(1)
*/

class Solution
{
    public:
        vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices)
        {
            vector<int> result;
            
            /*
            The key is to re-frame the problem as solving a system of equations.
            
            First, let J denote a jumbo burger and S denote a small burger
            
            Then, since a jumbo burger needs 4 tomato slices and a small burger needs 2 tomato slices, the equation for the total tomato slices needed for both burger types is => 4J + 2S = tomatoSlices.
            
            Similarly, since both a jumbo burger and a small burger need 1 cheese slice, the equation for the total number of cheese slices required is J + S = cheeseSlices
            
            Now, let's solve J + S = cheeseSlices for J => J=cheeseSlices - S.
            
            Ok, next, let's substitute the result we just got in the previous step into the equation 4J + 2S = tomatoSlices and solve for S
            
            4J + 2S = tomatoSlices
            
            => 4(cheeseSlices - S) + 2S = tomatoSlices
            
            => 4cheeseSlices - 4S + 2S = tomatoSlices
            
            => 4cheeseSlices - 2S = tomatoSlices
            
            => 4cheeseSlices = tomatoSlices + 2S
            
            => 4cheeseSlices - tomatoSlices = 2S
            
            => (4cheeseSlices - tomatoSlices)/2 = S
            
            So, now we have these two equations
            
            S=(4cheeseSlices - tomatoSlices)/2
            
            J=cheeseSlices - S
            */
            
            int smallBurgerEquation=((4 * cheeseSlices) - tomatoSlices)/2;
            
            int jumboBurgerEquation=cheeseSlices - smallBurgerEquation;
            
            int jumboBurgerEquationNumerator=(4 * cheeseSlices) - tomatoSlices;
            
            if(jumboBurgerEquationNumerator < 0 or (jumboBurgerEquationNumerator % 2)!=0)
            {
                return result;
            }
            
            if(jumboBurgerEquation >= 0)
            {
                result.push_back(jumboBurgerEquation);
                
                result.push_back(smallBurgerEquation);
            }
            
            return result;
        }
};