#include <list>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class TopVotedCandidate
{
    private:
        unordered_map<int, int> frequencies;
    
        map<int, list<int>> hashmap;
    
        map<int, int> leaderboard;
    
    public:
        TopVotedCandidate(vector<int> & persons, vector<int> & times)
        {
            int n=persons.size();
            
            for(int i=0;i<n;i++)
            {
                int person=persons[i];
                
                int time=times[i];
                
                //If this is the first time a vote for person is being cast
                if(frequencies.find(person)==end(frequencies))
                {
                    frequencies.emplace(person, 0);
                }
                
                //Otherwise, increment the number of votes for the person
                frequencies[person]+=1;
                
                int newFrequency=frequencies[person];
                
                //If the hashmap doesn't have the new vote frequency
                if(hashmap.find(newFrequency)==end(hashmap))
                {
                    //Insert the new vote frequency
                    hashmap.emplace(newFrequency, list<int>());
                }
                
                //Insert the person at the front of the list so that the top vote is the most recent
                hashmap[newFrequency].push_front(person);
                
                //Get the leading vote at the current timestmap
                int leadingVote=rbegin(hashmap)->second.front();
                
                //Add the timestamp and leading vote pair to the leaderboard hashmap
                leaderboard.emplace(time, leadingVote);
            }
        }

        int q(int t)
        {
            int electionLeader=-1;
            
            //Binary search within the leaderboard hashmap for the closest timestamp
            auto itr=leaderboard.lower_bound(t);
            
            //If the result of binary search does not match the desired timestamp and the returned iterator is not pointing to the beginning of the leaderboard hashmap
            if(itr->first!=t and itr!=begin(leaderboard))
            {
                //Decrement the iterator to point to the closest timestamp
                itr--;
            }
            
            //Get the election leader
            electionLeader=itr->second;
            
            return electionLeader;
        }
};
