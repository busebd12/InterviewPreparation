#include <set>
using namespace std;

class SmallestInfiniteSet
{
    private:
        set<int> infiniteSet;

        int limit;
    
    public:
        SmallestInfiniteSet()
        {
            limit=1001;
            
            for(int number=1;number<limit;number++)
            {
                infiniteSet.insert(number);
            }
        }
        
        int popSmallest()
        {   
            int smallest=*(infiniteSet.begin());

            infiniteSet.erase(infiniteSet.begin());

            return smallest;
        }
        
        void addBack(int num)
        {
            if(infiniteSet.find(num)!=infiniteSet.end())
            {
                return;
            }

            infiniteSet.insert(num);
        }
};