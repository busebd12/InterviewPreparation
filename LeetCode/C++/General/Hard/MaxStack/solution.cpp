#include <iterator>
#include <list>
#include <map>
#include <vector>
using namespace std;

class MaxStack
{
    private:
        list<int> stack;

        map<int, vector<list<int>::iterator>> hashmap;
    
    public:
        MaxStack()
        {
            
        }
        
        void push(int x)
        {
            auto itr=stack.insert(stack.begin(), x);

            if(hashmap.find(x)==hashmap.end())
            {
                hashmap.emplace(x, vector<list<int>::iterator>());
            }

            hashmap[x].push_back(itr);
        }
        
        int pop()
        {
            int value=stack.front();

            stack.pop_front();

            hashmap[value].pop_back();

            if(hashmap[value].empty())
            {
                hashmap.erase(value);
            }

            return value;
        }
        
        int top()
        {
            return stack.front();
        }
        
        int peekMax()
        {
            return hashmap.rbegin()->first;
        }
        
        int popMax()
        {
            int value=peekMax();

            stack.erase(hashmap[value].back());

            hashmap[value].pop_back();

            if(hashmap[value].empty())
            {
                hashmap.erase(value);
            }

            return value;
        }
};