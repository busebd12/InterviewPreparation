#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
    public:
        ListNode* frequenciesOfElements(ListNode* head)
        {
            ListNode* result=nullptr;

            ListNode node(-1);

            int max_value=pow(10, 5);

            vector<int> frequencies(max_value + 1, 0);

            ListNode* current=head;

            while(current!=nullptr)
            {
                frequencies[current->val]+=1;

                current=current->next;
            }

            current=&node;

            for(int number=1;number<=max_value;number+=1)
            {
                int frequency=frequencies[number];

                if(frequency > 0)
                {
                    current->next=new ListNode(frequency);

                    current=current->next;
                }
            }

            result=&node;

            return result->next;
        }
};

class Solution
{
    public:
        ListNode* frequenciesOfElements(ListNode* head)
        {
            ListNode* result=nullptr;

            ListNode node(-1);

            unordered_map<int, int> frequencies;

            ListNode* current=head;

            while(current!=nullptr)
            {
                if(frequencies.find(current->val)==frequencies.end())
                {
                    frequencies.insert(make_pair(current->val, 0));
                }
                
                frequencies[current->val]+=1;

                current=current->next;
            }

            current=&node;

            for(auto [number, frequency] : frequencies)
            {
                current->next=new ListNode(frequency);

                current=current->next;
            }

            result=&node;

            return result->next;
        }
};