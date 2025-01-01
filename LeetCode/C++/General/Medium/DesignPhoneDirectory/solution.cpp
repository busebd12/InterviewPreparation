#include <iterator>
#include <list>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class PhoneDirectory
{
    private:
        list<int> numbers;

        unordered_map<int, pair<list<int>::iterator, bool>> hashmap;
    
    public:
        PhoneDirectory(int maxNumbers)
        {
            for(int number=0;number<maxNumbers;number++)
            {
                auto itr=numbers.insert(numbers.end(), number);

                hashmap.emplace(number, make_pair(itr, true));
            }
        }
        
        int get()
        {
            if(numbers.empty())
            {
                return -1;
            }

            int number=numbers.front();

            hashmap[number].second=false;

            numbers.pop_front();

            return number;
        }
        
        bool check(int number)
        {
            return hashmap[number].second;
        }
        
        void release(int number)
        {
            if(check(number)==true)
            {
                return;
            }
            
            auto itr=numbers.insert(numbers.end(), number);

            hashmap[number].first=itr;

            hashmap[number].second=true;
        }
};


class PhoneDirectory
{
    private:
        int MAX;

        int current;
        
        unordered_set<int> numbers;
    
    public:
        PhoneDirectory(int maxNumbers)
        {
            MAX=maxNumbers;

            current=-1;
        }
        
        int get()
        {
            int number=-1;

            if(!numbers.empty())
            {
                number=*(numbers.begin());

                numbers.erase(numbers.begin());
            }
            else if(current + 1 < MAX)
            {
                current+=1;

                number=current;
            }

            return number;
        }
        
        bool check(int number)
        {
            if(numbers.count(number)==1)
            {
                return true;
            }

            return current < number and number < MAX;
        }
        
        void release(int number)
        {
            if(0 <= number and number <= current)
            {
                numbers.insert(number);
            }
        }
};