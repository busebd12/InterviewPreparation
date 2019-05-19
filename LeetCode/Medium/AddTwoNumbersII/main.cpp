#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct ListNode
{
    int val;

    ListNode *next;

    ListNode(int x):val(x), next(NULL){}
};

void addToEnd(ListNode* head, const int value)
{
    ListNode* tail=new ListNode(value);

    if(head->next==nullptr)
    {
        head->next=tail;
    }
    else
    {
        ListNode* current=head;

        while(true)
        {
            if(current->next==nullptr)
            {
                current->next=tail;

                break;
            }

            current=current->next;
        }
    }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* current=l1;

    vector<int> firstNumber;

    while(true)
    {
        firstNumber.emplace_back(current->val);

        if(current->next==nullptr)
        {
            break;
        }

        current=current->next;
    }

    current=l2;

    vector<int> secondNumber;

    while(true)
    {
        secondNumber.emplace_back(current->val);

        if(current->next==nullptr)
        {
            break;
        }

        current=current->next;
    }

    int n=int(max(firstNumber.size(), secondNumber.size()));

    deque<int> result;

    int i=int(firstNumber.size())-1;

    int j=int(secondNumber.size())-1;

    int carry=0;

    while(i >= 0 && j >= 0)
    {
        int number=firstNumber[i] + secondNumber[j] + carry;

        if(number >= 10)
        {
            int lastDigit=number%10;

            int firstDigit=number/10;

            carry=firstDigit;

            result.emplace_front(lastDigit);
        }
        else
        {
            result.emplace_front(number);

            carry=0;
        }

        --i;

        --j;
    }

    if(i >= 0)
    {
        for(int x=i;x>=0;--x)
        {
            int number=firstNumber[x] + carry;

            if(number >= 10)
            {
                int lastDigit=number%10;

                int firstDigit=number/10;

                carry=firstDigit;

                result.emplace_front(lastDigit);
            }
            else
            {
                result.emplace_front(number);

                carry=0;
            }
        }
    }

    if(j >= 0)
    {
        for(int x=j;x>=0;--x)
        {
            int number=secondNumber[x] + carry;

            if(number >= 10)
            {
                int lastDigit=number%10;

                int firstDigit=number/10;

                carry=firstDigit;

                result.emplace_front(lastDigit);
            }
            else
            {
                result.emplace_front(number);

                carry=0;
            }
        }
    }

    if(carry > 0)
    {
        result.emplace_front(carry);
    }

    ListNode* answer=new ListNode(-1);

    for(auto & number : result)
    {
        if(number >= 10)
        {
            int firstNumber=number/10;

            addToEnd(answer, firstNumber);

            int secondNumber=number%10;

            addToEnd(answer, secondNumber);
        }
        else
        {
            addToEnd(answer, number);
        }
    }

    return answer->next;
}