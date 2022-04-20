#include <queue>
#include <string>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O((n * p) + (p * n) + (l * log(l)) + (l * log(l)))
[where n is the length of votes, p is the number of possible places, and l is the number of unique teams (letters)]

Space complexity: O(l) [where l is the number of unique teams (letters)]
*/

class Solution
{
    public:
        string rankTeams(vector<string> & votes)
        {
            string result{};
            
            int n=votes.size();
            
            if(n==1)
            {
                return votes[0];
            }
            
            //Keep track of which letters are used
            vector<int> letters(26, 0);
            
            //Calculate the frequency of each letter
            for(auto & vote : votes) //O(n)
            {
                for(auto & letter : vote) //O(p)
                {
                    int index=letter - 'A';
                    
                    letters[index]+=1;
                }
            }
            
            //Number of places a team can get votes in (1st place, 2nd place, 3rd place, etc.)
            int places=votes[0].size();
            
            //Map each team (letter) to "places" number of buckets
            //The first places-1 buckets keep track of how many votes for that particular place the team got
            //The last bucket stores the ASCII value for each team (letter)
            vector<vector<int>> hashtable(26, vector<int>(places, 0));
            
            //Calculate the number of votes for each place that each time received
            for(int place=0;place<places;place++) //O(p)
            {
                for(int i=0;i<n;i++) //O(n)
                {
                    char letter=votes[i][place];
                    
                    int index=letter - 'A';
                    
                    hashtable[index][place]+=1;
                }
            }
            
            //Add the ASCII value for each letter to the last bucket
            for(int index=0;index<26;index++)
            {
                if(letters[index] > 0)
                {
                    hashtable[index][places-1]=index;
                }
            }
            
            //Custom sorting comparator for the max heap
            //This is the crux of the solution
            auto comparator=[&places] (vector<int> & lhs, vector<int> & rhs)
            {
                int i=0;
                
                //We iterate through all the places for two teams while the number of votes each teamed received for each place is the same (comparing the votes for 1st place, 2nd place, 3rd place, etc. for two teams)
                while(i < places && lhs[i]==rhs[i])
                {
                    i++;
                }
                
                //If i reaches the last bucket for each team, that means that both teams received the same amount of votes for all possible places:
                //1st place, 2nd place, 3rd place, etc.
                if(i==places-1)
                {
                    //So, since the last bucket contains the ASCII representation for each letter, we can just return whichever ASCII value is smaller
                    //Note: since letters earlier in the alphabet will have smaller ASCII values compared to letters that appear later in the alphabet,
                    //in the case of a tie, we want the letters with the smaller ASCII values to come before letters with larger ASCII values in the heap.
                    //In other words, we want to minimize this comparison, that's why we use the > instead of the <
                    return lhs[i] > rhs[i];
                }
                
                //If i doesn't reach the last bucket for both teams, then one team had more votes for a certain place than the other team
                //For example, team 'A' had 5 votes for 1st place and team 'B' also had 5 votes for 1st place, but team 'A' had 3 votes
                //for 2nd place and team 'B' only had 2 votes for 2nd place
                //So, in this case, we want the team with more tie breaking votes to come before the team with less tie breaking votes in the heap
                //In other words, we want to maximize this comparison
                return lhs[i] < rhs[i];
            };
            
            priority_queue<vector<int>, vector<vector<int>>, decltype(comparator)> heap(comparator);
            
            //Loop through all letters
            for(int i=0;i<26;i++) //O(l)
            {
                //If the team received votes
                if(letters[i] > 0)
                {   
                    //Add the team's buckets to the heap
                    heap.emplace(hashtable[i]); //O(log(l))
                }
            }
            
            while(!heap.empty()) //O(l * log(l))
            {
                auto current=heap.top();
                
                heap.pop();
                
                //Calculate the letter sitting at the top of the heap
                char c=('A' - 0) + current[places-1];
                
                //Add the letter to the result
                result.push_back(c);
            }
            
            return result;
        }
};