#include <iostream>
#include <unordered_set>

/*
 * Solutions:
 *
 * 1. Brute force. For each person, if everyone knows this person and this person does not know anyone else, then
 * they are a celebrity and we add them to our list (std::unordered_set<int>) of celebrities. After checking each
 * person, if our list is empty, then we return -1 (there must be at least one celebrity). If the list has more than
 * one person, then we return -1 (there must only be only one celebrity). Otherwise, return the only person on the list.
 *
 * Time complexity: O(n^2) [where n is the number of people]
 * Space complexity: O(n)
 *
 * 2. The algorithm is as follows
 *
 * a. We assume that person 0 is the celebrity. We then loop through the rest of the people and if the current celebrity
 * knows the current person, then the current celebrity cannot be a celebrity since a celebrity does not know anyone else.
 * So, we choose the current person as the next celebrity candidate. Since there is, at max, only one celebrity, at the
 * end of this first loop we will have our celebrity candidate. You can think of this as finding the person who knows the
 * least amount of people or the person who is known by the maximum number of people.
 *
 * b. Then, in the second for loop, we check to make sure that our chosen candidate is indeed the celebrity. If the
 * chosen candidate knows someone else or another person does not now them, then the candidate cannot be the celebrity
 * and we return -1. After completing the for loop, if the candidate was not disqualified, then they are the celebrity.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

class Solution
{
    public:

        bool everyoneKnowsThisPerson(int person, int n)
        {
            for(int otherPerson=0;otherPerson<n;otherPerson++)
            {
                if(otherPerson==person)
                {
                    continue;
                }

                if(!knows(otherPerson, person))
                {
                    return false;
                }
            }

            return true;
        }

        bool thisPersonDoesNotKnowAnyoneElse(int person, int n)
        {
            for(int otherPerson=0;otherPerson<n;otherPerson++)
            {
                if(otherPerson==person)
                {
                    continue;
                }

                if(knows(person, otherPerson))
                {
                    return false;
                }
            }

            return true;
        }

        int findCelebrity(int n)
        {
            if(n <= 0)
            {
                return -1;
            }

            if(n==1)
            {
                return n-1;
            }

            std::unordered_set<int> celebrities;

            for(int person=0;person<n;person++)
            {
                if(everyoneKnowsThisPerson(person, n) && thisPersonDoesNotKnowAnyoneElse(person, n))
                {
                    celebrities.insert(person);
                }
            }

            if(celebrities.empty())
            {
                return -1;
            }

            return (celebrities.size() > 1) ? -1 : *(celebrities.begin());
        }
};

class Solution
{
    public:

        int findCelebrity(int n)
        {
            if(n <= 0)
            {
                return -1;
            }

            if(n==1)
            {
                return n-1;
            }

            int celebrity=0;

            for(int person=1;person<n;person++)
            {
                if(knows(celebrity, person))
                {
                    celebrity=person;
                }
            }

            for(int person=0;person<n;person++)
            {
                if(person==celebrity)
                {
                    continue;
                }

                if(knows(celebrity, person) || !knows(person, celebrity))
                {
                    return -1;
                }
            }

            return celebrity;
        }
};