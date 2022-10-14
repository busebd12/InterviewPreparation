#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of milestones]
Space complexity: O(1)
*/

class Solution
{
    public:
        long long numberOfWeeks(vector<int> & milestones)
        {
            long long result=0;
            
            long long maxMilestones=static_cast<long long>(*(max_element(begin(milestones), end(milestones))));
            
            long long totalMilestones=(accumulate(begin(milestones), end(milestones), static_cast<long long>(0)));
            
            long long remaining=totalMilestones - maxMilestones;
            
            //If we can create pairs of the form {milestone from the project with the most milestones, milestone from a differnet project} in such a way that we are left with one milestone from the project with the most milestones, then the number of weeks we can work will be the total number of milestones
            if(maxMilestones <= remaining + 1)
            {
                result=totalMilestones;
            }
            //Else, there are not enough other projects to create pairs of the form {milestone from the project with the most milestones, milestone from a differnet project}, so we just create as many pairs as we can with the other projects.
            //We add one to account for working on a milestone from the project with the most milestones one last time.
            else
            {
                result=(2 * remaining) + 1;
            }
            
            return result;
        }
};