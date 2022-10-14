#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class ATM
{
    private:
        vector<pair<long long, long long>> hashmap={{20, 0}, {50, 0}, {100, 0}, {200, 0}, {500, 0}};
    
    public:
        ATM()
        {

        }

        void deposit(vector<int> banknotesCount)
        {
            int twenties=banknotesCount[0];
            
            int fifties=banknotesCount[1];
            
            int hundreds=banknotesCount[2];
            
            int twoHundreds=banknotesCount[3];
            
            int fiveHundreds=banknotesCount[4];
            
            hashmap[0].second+=twenties;
            
            hashmap[1].second+=fifties;
            
            hashmap[2].second+=hundreds;
            
            hashmap[3].second+=twoHundreds;
            
            hashmap[4].second+=fiveHundreds;
        }

        vector<int> withdraw(int amount)
        {
            vector<int> bills;
            
            unordered_map<long long, int> frequencies;
            
            for(int i=hashmap.size()-1;i>=0 and amount>0;i--)
            {
                int bill=hashmap[i].first;

                if(frequencies.find(bill)==end(frequencies))
                {
                    frequencies.emplace(bill, 0);
                }

                if(amount >= bill and hashmap[i].second > 0)
                {
                    long long availableAmount=hashmap[i].first * hashmap[i].second;

                    int billsWithdrawn=min(static_cast<long long>(amount) / hashmap[i].first, hashmap[i].second);

                    if(billsWithdrawn > 0)
                    {
                        int decrement=billsWithdrawn * hashmap[i].first;

                        amount-=decrement;

                        frequencies[bill]+=billsWithdrawn;

                        hashmap[i].second-=billsWithdrawn;
                    }
                }
            }
            
            if(amount > 0)
            {
                bills.emplace_back(-1);
                
                hashmap[0].second+=frequencies[20];
                
                hashmap[1].second+=frequencies[50];
                
                hashmap[2].second+=frequencies[100];
                
                hashmap[3].second+=frequencies[200];
                
                hashmap[4].second+=frequencies[500];
                
                return bills;
            }
            
            bills.emplace_back(frequencies[20]);
            
            bills.emplace_back(frequencies[50]);
            
            bills.emplace_back(frequencies[100]);
            
            bills.emplace_back(frequencies[200]);
            
            bills.emplace_back(frequencies[500]);
            
            return bills;
        }      
};

class ATM
{
    private:
        vector<pair<long long, long long>> hashmap={{20, 0}, {50, 0}, {100, 0}, {200, 0}, {500, 0}};
    
    public:
        ATM()
        {

        }

        void deposit(vector<int> banknotesCount)
        {
            int twenties=banknotesCount[0];
            
            int fifties=banknotesCount[1];
            
            int hundreds=banknotesCount[2];
            
            int twoHundreds=banknotesCount[3];
            
            int fiveHundreds=banknotesCount[4];
            
            hashmap[0].second+=twenties;
            
            hashmap[1].second+=fifties;
            
            hashmap[2].second+=hundreds;
            
            hashmap[3].second+=twoHundreds;
            
            hashmap[4].second+=fiveHundreds;
        }

        vector<int> withdraw(int amount)
        {
            vector<int> bills;
            
            vector<pair<long long, int>> frequencies={{20, 0}, {50, 0}, {100, 0}, {200, 0}, {500, 0}};
            
            for(int i=hashmap.size()-1;i>=0 and amount>0;i--)
            {
                int bill=hashmap[i].first;

                if(amount >= bill and hashmap[i].second > 0)
                {
                    long long availableAmount=hashmap[i].first * hashmap[i].second;

                    int billsWithdrawn=min(static_cast<long long>(amount) / hashmap[i].first, hashmap[i].second);

                    if(billsWithdrawn > 0)
                    {
                        int decrement=billsWithdrawn * hashmap[i].first;

                        amount-=decrement;

                        frequencies[i].second+=billsWithdrawn;

                        hashmap[i].second-=billsWithdrawn;
                    }
                }
            }
            
            if(amount > 0)
            {
                bills.emplace_back(-1);
                
                for(int i=frequencies.size()-1;i>=0;i--)
                {
                    hashmap[i].second+=frequencies[i].second;
                }
                
                return bills;
            }
            
            for(int i=0;i<frequencies.size();i++)
            {
                bills.emplace_back(frequencies[i].second);
            }
            
            return bills;
        }      
};