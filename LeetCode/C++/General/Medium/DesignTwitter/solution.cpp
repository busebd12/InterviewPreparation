#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Twitter
{
    private:
        unordered_map<int, vector<pair<int, int>>> tweets;
    
        unordered_map<int, unordered_set<int>> following;
    
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> maxHeap;
    
        long long time;
    
    public:
        Twitter()
        {
            this->time=0;
        }

        void postTweet(int userId, int tweetId)
        {
            if(tweets.find(userId)==end(tweets))
            {
                tweets.emplace(userId, vector<pair<int, int>>());
            }
            
            tweets[userId].emplace_back(time, tweetId);
            
            time+=1;
        }

        vector<int> getNewsFeed(int userId)
        {   
            vector<int> newsFeed;
            
            for(pair<int, int> & tweet : tweets[userId])
            {   
                maxHeap.emplace(tweet);
            }
            
            for(int id : following[userId])
            {
                for(pair<int, int> & tweet : tweets[id])
                {
                    maxHeap.emplace(tweet);
                }
            }
            
            for(int count=0;count<10 and !maxHeap.empty();count++)
            {
                auto tweet=maxHeap.top();
                
                maxHeap.pop();
                
                newsFeed.emplace_back(tweet.second);
            }
            
            while(!maxHeap.empty())
            {
                maxHeap.pop();
            }
            
            return newsFeed;
        }
    
        void follow(int followerId, int followeeId)
        {
            if(followerId!=followeeId)
            {
                if(following.find(followerId)==end(following))
                {
                    following.emplace(followerId, unordered_set<int>());
                }

                following[followerId].insert(followeeId);
            }
        }

        void unfollow(int followerId, int followeeId)
        {
            if(following.find(followerId)!=end(following))
            {
                auto itr=following[followerId].find(followeeId);
                
                if(itr!=end(following[followerId]))
                {
                    following[followerId].erase(itr);
                }
            }
        }
};