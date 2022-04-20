#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: see comments.
*/

class FreqStack
{
    public:
        unordered_map<int, vector<list<int>::iterator>> valueToIteratorMap;
    
        unordered_map<int, int> valueToFrequencyMap;
    
        map<int, unordered_set<int>> frequencyToValuesMap;
    
        list<int> stack;
    
        FreqStack()
        {
        }

        void push(int val)
        {
            //Increase the frequency of val
            valueToFrequencyMap[val]++;
            
            //Group the value by its frequency
            frequencyToValuesMap[valueToFrequencyMap[val]].insert(val);
            
            //Push the value onto the stack
            auto itr=stack.insert(end(stack), val);
            
            //Add the iterator to the list of iterators associated with the value
            valueToIteratorMap[val].emplace_back(itr);
        }

        int pop()
        {
            //Frequency of the most frequent element in the stack
            int highestFrequency=rbegin(frequencyToValuesMap)->first;
            
            //Iterator pointing to the last element in the map
            auto itr=rbegin(frequencyToValuesMap);
    
            //Pair that will store the most frequent value we will be removing from the stack and the index of the iterator pointing to that value within the associated vector of iterators
            pair<int, int> p=make_pair(-1, -1);
            
            int distanceFromTopOfStack=numeric_limits<int>::max();
            
            //Iterate through list of most frequent elements
            for(auto value : itr->second)
            {
                int n=valueToIteratorMap[value].size();
                
                //Iterate through all list<int>::iterator associated with the value
                for(int index=0;index<n;index++)
                {
                    //Distance between the top of the stack and the current iterator
                    int currentDistance=distance(valueToIteratorMap[value][index], prev(end(stack), 1));
                    
                    //If the distance between the top of the stack and the current iterator is less than the previous distance
                    if(currentDistance < distanceFromTopOfStack)
                    {
                        distanceFromTopOfStack=currentDistance;
                        
                        p.first=value;
                        
                        p.second=index;
                    }
                }
            }
            
            //Decrease the frequency of the most frequent element that is closest to the top of the stack
            valueToFrequencyMap[p.first]--;
            
            //Since we've decreased the frequency of the most frequent element that is closest to the top of the stack, we need to remove it from collection of values associated with the highest frequency
            
            itr->second.erase(p.first);
            
            //If there are no more values associated with the current highest frequency, erase the entry from the map
            if(itr->second.empty())
            {
                frequencyToValuesMap.erase(highestFrequency);
            }
            
            //Remove the most frequent element that is closest to the top of the stack from the stack
            stack.erase(valueToIteratorMap[p.first][p.second]);
            
            int n=valueToIteratorMap[p.first].size();
            
            //Swap the iterator pointing to the most frequent element that is closest to the top of the stack with the last iterator in the vector
            swap(valueToIteratorMap[p.first][p.second], valueToIteratorMap[p.first][n-1]);
            
            //Remove the iterator pointing to the most frequent element that is closest to the top of the stack now that it is at the end of the vector
            valueToIteratorMap[p.first].pop_back();
            
            return p.first;
        }
};


class FreqStack
{
    public:
    
        //Map each value to its frequency
        unordered_map<int, int> valueToFrequencyMap;
    
        //Group values in the stack by their frequency
        //Key: frequecy; value: stack of numbers in the order they were pushed onto the stack
        //Since std::map stores keys in ascending order, the last key in the map points to all the elements in the stack that have max frequency
        map<int, stack<int>> frequencyToValuesMap;
    
        FreqStack()
        {
        }

        void push(int val)
        {
            //Increase the frequency of val
            valueToFrequencyMap[val]++;
            
            //Group the value by its frequency
            frequencyToValuesMap[valueToFrequencyMap[val]].push(val);
        }

        int pop()
        {
            //Iterator to last key,value pair in the map
            auto itr=rbegin(frequencyToValuesMap);
            
            int maxFrequency=itr->first;
            
            //Result is simply the top of the stack of most frequent elements
            int result=itr->second.top();
            
            //Remove the top most number
            itr->second.pop();
            
            //If the stack associated with the highest frequency is empty, then erase the entry from the map
            if(itr->second.empty())
            {
                frequencyToValuesMap.erase(maxFrequency);
            }
            
            //Decrement the frequency of the result
            valueToFrequencyMap[result]--;
            
            return result;
        }
};