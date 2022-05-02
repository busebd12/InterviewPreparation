#include <set>
#include <unordered_map>
#include <utility>
using namespace std;

class Leaderboard
{
    private:
        unordered_map<int, pair<multiset<int>::iterator, int>> hashtable;
    
        multiset<int> scores;
    
    public:
        Leaderboard()
        {
            
        }

        void addScore(int playerId, int score)
        {
            if(hashtable.find(playerId)==end(hashtable))
            {
                auto itr=scores.insert(score);
                
                hashtable[playerId]=make_pair(itr, score);
            }
            else
            {
                scores.erase(hashtable[playerId].first);
                
                hashtable[playerId].second+=score;
                
                auto itr=scores.insert(hashtable[playerId].second);
                
                hashtable[playerId].first=itr;
            }
        }

        int top(int K)
        {
            int sum=0;
            
            auto itr=rbegin(scores);
            
            while(itr!=rend(scores) && K > 0)
            {
                sum+=*itr;
                
                itr++;
                
                K--;
            }
            
            return sum;
        }

        void reset(int playerId)
        {
            scores.erase(hashtable[playerId].first);
            
            hashtable.erase(playerId);
        }
};