#include <deque>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Solution 1: move from "0000" to the desired end lock state.
*/

class Solution
{
    public:
        char getDecrementCharacter(string lock, size_t index)
        {
            char c=lock[index];
            
            int digit=c - '0';
            
            digit-=1;
            
            if(digit < 0)
            {
                digit=9;
            }
            
            char decrementCharacter=(digit + '0');
            
            return decrementCharacter;
        }
    
        char getIncrementCharacter(string lock, size_t index)
        {
            char c=lock[index];
            
            int digit=c - '0';
            
            digit+=1;
            
            if(digit > 9)
            {
                digit=0;
            }
            
            char incrementCharacter=(digit + '0');
            
            return incrementCharacter;
        }
    
        int openLock(vector<string> & deadends, string target)
        {
            int result=0;
            
            int n=target.size();
            
            unordered_set<string> cache(begin(deadends), end(deadends));
            
            if(cache.find("0000")!=end(cache))
            {
                return -1;
            }
            
            deque<string> queue;
            
            cache.insert("0000");
            
            queue.emplace_back("0000");
            
            while(!queue.empty())
            {
                size_t qSize=queue.size();
                
                for(size_t count=0;count<qSize;count++)
                {
                    string lock=queue.front();
                    
                    queue.pop_front();
                    
                    if(lock==target)
                    {
                        return result;
                    }
                    
                    for(size_t index=0;index<lock.size();index++)
                    {
                        char original=lock[index];
                        
                        char upByOne=getIncrementCharacter(lock, index);
                        
                        lock[index]=upByOne;
                        
                        if(cache.find(lock)==end(cache))
                        {
                            cache.insert(lock);
                            
                            queue.push_back(lock);
                        }
                        
                        lock[index]=original;
                        
                        char downByOne=getDecrementCharacter(lock, index);
                        
                        lock[index]=downByOne;
                        
                        if(cache.find(lock)==end(cache))
                        {
                            cache.insert(lock);
                            
                            queue.push_back(lock);
                        }
                        
                        lock[index]=original;
                    }
                }
                
                result+=1;
            }
            
            return -1;
        }
};

/*
Solution 2: move from the desired end lock state backwards to "0000"
*/

class Solution
{
    public:
        char getDecrementCharacter(string lock, size_t index)
        {
            char c=lock[index];
            
            int digit=c - '0';
            
            digit-=1;
            
            if(digit < 0)
            {
                digit=9;
            }
            
            char decrementCharacter=(digit + '0');
            
            return decrementCharacter;
        }
    
        char getIncrementCharacter(string lock, size_t index)
        {
            char c=lock[index];
            
            int digit=c - '0';
            
            digit+=1;
            
            if(digit > 9)
            {
                digit=0;
            }
            
            char incrementCharacter=(digit + '0');
            
            return incrementCharacter;
        }
    
        int openLock(vector<string> & deadends, string target)
        {
            int result=0;
            
            int n=target.size();
            
            unordered_set<string> cache(begin(deadends), end(deadends));
            
            if(cache.find("0000")!=end(cache))
            {
                return -1;
            }
            
            deque<string> queue;
            
            cache.insert(target);
            
            queue.push_back(target);
            
            while(!queue.empty())
            {
                size_t qSize=queue.size();
                
                for(size_t count=0;count<qSize;count++)
                {
                    string lock=queue.front();
                    
                    queue.pop_front();
                    
                    if(lock=="0000")
                    {
                        return result;
                    }
                    
                    for(size_t index=0;index<lock.size();index++)
                    {
                        if(lock[index]!='0')
                        {
                            char original=lock[index];
                        
                            char upByOne=getIncrementCharacter(lock, index);

                            lock[index]=upByOne;

                            if(cache.find(lock)==end(cache))
                            {
                                seen.insert(lock);

                                queue.push_back(lock);
                            }

                            lock[index]=original;

                            char downByOne=getDecrementCharacter(lock, index);

                            lock[index]=downByOne;

                            if(cache.find(lock)==end(cache))
                            {
                                seen.insert(lock);

                                queue.push_back(lock);
                            }

                            lock[index]=original;
                        }
                    }
                }
                
                result+=1;
            }
            
            return -1;
        }
};