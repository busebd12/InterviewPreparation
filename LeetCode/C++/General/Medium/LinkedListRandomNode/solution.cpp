#include <cstdlib>
#include <random>
#include <vector>
using namespace std;

class Solution
{
    private:
        vector<int> hashmap;

        int length;
    
    public:
        Solution(ListNode* head)
        {
            length=0;

            populateHashmap(head);

            srand(time(NULL));
        }

        void populateHashmap(ListNode* head)
        {
            ListNode* current=head;

            while(current!=nullptr)
            {
                length+=1;

                current=current->next;
            }

            hashmap.resize(length, 0);

            current=head;

            int index=0;

            while(current!=nullptr)
            {
                hashmap[index]=current->val;

                current=current->next;

                index+=1;
            }
        }
        
        int getRandom()
        {
            int index=getRandomIndex();

            return hashmap[index];
        }

        int getRandomIndex()
        {
            int randomIndex=rand() % length;

            return randomIndex;
        }
};

class Solution
{
    private:
        vector<int> hashmap;

        int length;
    
    public:
        Solution(ListNode* head)
        {
            length=0;

            populateHashmap(head);
        }

        void populateHashmap(ListNode* head)
        {
            ListNode* current=head;

            while(current!=nullptr)
            {
                length+=1;

                current=current->next;
            }

            hashmap.resize(length, 0);

            current=head;

            int index=0;

            while(current!=nullptr)
            {
                hashmap[index]=current->val;

                current=current->next;

                index+=1;
            }
        }
        
        int getRandom()
        {
            int index=getRandomIndex();

            return hashmap[index];
        }

        int getRandomIndex()
        {
            random_device rd;

            mt19937 generator(rd());

            uniform_int_distribution<int> distribution(0, length-1);

            int randomIndex=distribution(generator);

            return randomIndex;
        }
};