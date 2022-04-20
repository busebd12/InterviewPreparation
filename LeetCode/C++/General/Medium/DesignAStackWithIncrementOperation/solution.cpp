#include <deque>
#include <unordered_map>
using namespace std;

class CustomStack
{
    public:
        //Use a deque for stack because we can access elements from the bottom and top of the stack since std::deque is a double-ended queue
        deque<int> stack;
    
        int limit;

        CustomStack(int maxSize)
        {
            limit=maxSize;
        }

        void push(int x)
        {
            if(stack.size() < limit)
            {
                stack.emplace_back(x);
            }
        }

        int pop()
        {
            int result=-1;
            
            if(!stack.empty())
            {
                result=stack.back();
                
                stack.pop_back();
            }
            
            return result;
        }

        void increment(int k, int val)
        {
            if(stack.size() < k)
            {
                //Add increment to all numbers in the stack
                for_each(begin(stack), end(stack), [val] (auto & number) {number+=val;});
            }
            else
            {
                //Apply the increment to the bottom k numbers only
                for(int count=0;count<k;count++)
                {
                    stack[count]+=val;
                }
            }
        }
};

class CustomStack
{
    public:
        deque<int> stack;
    
        //Mapping an index i to a increment amount means that the increment value is applied to elements in the stack from index 0 to i (inclusive)
        unordered_map<int, int> indexToIncrementMap;
    
        int limit;

        CustomStack(int maxSize)
        {
            limit=maxSize;
        }

        void push(int x)
        {
            if(stack.size() < limit)
            {
                stack.emplace_back(x);
            }
        }

        int pop()
        {
            int result=-1;
            
            if(!stack.empty())
            {
                //Index of the top number in the stack
                int index=stack.size()-1;
                
                //Incrememt value associated with the top element in the stack
                int increment=indexToIncrementMap[index];
                
                //Since we are removing the top element we need to "pass" the increment value associated with it to the next top element in the stack so we don't lose it
                indexToIncrementMap[index - 1]+=increment;
                
                //Erase index of the top of the stack
                indexToIncrementMap.erase(index);
                
                result=stack.back();
                
                stack.pop_back();
                
                //Increment the top value in the stack
                result+=increment;
            }
            
            return result;
        }

        void increment(int k, int val)
        {
            int index=-1;
            
            //Stack has less than k elements
            if(stack.size() < k)
            {
                index=stack.size()-1;
            }
            //Else, stack has more than at least k elements
            else
            {
                index=k - 1;
            }
            
            //Hashtable doesn't contain this index yet
            if(!indexToIncrementMap.count(index))
            {
                indexToIncrementMap[index]=val;
            }
            //Hashtable already contains this index
            else
            {
                indexToIncrementMap[index]+=val;
            }
        }
};
