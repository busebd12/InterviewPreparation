#include <deque>
#include <map>
#include <set>
using namespace std;

/*
Solution 1: std::deque + std::multiset. Note, this solution receives Time Limit Exceeded when executed.
*/

class MKAverage
{
    private:
        deque<int> stream;

        int M;

        int K;
    
    public:
        MKAverage(int m, int k)
        {
            M=m;

            K=k;
        }
        
        void addElement(int num) //O(1)
        {
            stream.push_back(num);

            if(stream.size() > M)
            {
                stream.pop_front();
            }
        }
        
        int calculateMKAverage()
        {
            int mkAverage=-1;

            if(stream.size() < M)
            {
                return mkAverage;
            }

            multiset<int> container;

            int index=stream.size() - 1;

            for(int count=0;count<M;count++) //O(log(M))
            {
                container.emplace(stream[index]);

                index-=1;
            }

            mkAverage=0;

            for(int count=0;count<K and !container.empty();count++) //O(K * log(M))
            {
                container.erase(container.begin());
            }

            for(int count=0;count<K and !container.empty();count++) //O(K * log(M))
            {
                container.erase(prev(container.end()));
            }

            for(int number : container) //O(M - 2*K)
            {
                mkAverage+=number;
            }

            mkAverage=mkAverage / container.size();

            return mkAverage;
        }
};

/*
Solution 2: std::deque + std::map
*/

class MKAverage
{
    private:
        deque<int> stream;

        map<int, int> hashmap;

        int M;

        int K;

        long long int runningSum;
    
    public:
        MKAverage(int m, int k)
        {
            M=m;

            K=k;

            runningSum=0;
        }
        
        void addElement(int num) //O(log(M))
        {   
            stream.push_back(num);

            hashmap[num]+=1;

            runningSum+=num;

            if(stream.size() > M)
            {
                int front=stream.front();
                
                runningSum-=front;

                if(hashmap[front] > 0)
                {
                    hashmap[front]-=1;
                }

                if(hashmap[front]==0)
                {
                    hashmap.erase(front);
                }
                
                stream.pop_front();
            }
        }
        
        int calculateMKAverage()
        {
            int mkAverage=-1;

            if(stream.size() < M)
            {
                return mkAverage;
            }

            long long int sum=runningSum;

            int k=K;

            //Iterate through the hashmap in reverse order to remove the k largest
            for(auto itr=hashmap.rbegin();itr!=hashmap.rend() and k > 0;itr++) //O(K)
            {   
                int frequency=itr->second;

                int removals=min(frequency, k);

                int valueToRemoveFromSum=removals * itr->first;

                sum-=valueToRemoveFromSum;

                k-=removals;
            }

            k=K;

            //Iterate through the hashmap in normal order to remove the k smallest
            for(auto itr=hashmap.begin();itr!=hashmap.end() and k > 0;itr++) //O(K)
            {   
                int frequency=itr->second;

                int removals=min(frequency, k);

                int valueToRemoveFromSum=removals * itr->first;

                sum-=valueToRemoveFromSum;

                k-=removals;
            }

            int totalRemoved=2 * K;

            int leftOver=M - totalRemoved;

            mkAverage=sum / leftOver;

            return mkAverage;
        }
};