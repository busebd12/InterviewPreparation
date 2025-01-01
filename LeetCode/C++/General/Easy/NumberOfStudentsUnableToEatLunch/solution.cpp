#include <algorithm>
#include <deque>
#include <vector>
using namespace std;


class Solution
{
    public:
        int countStudents(vector<int> & students, vector<int> & sandwiches)
        {
            reverse(sandwiches.begin(), sandwiches.end());

            vector<int> stack(sandwiches.begin(), sandwiches.end());

            deque<int> queue(students.begin(), students.end());

            while(!stack.empty())
            {
                bool students_ate=false;

                int q_size=queue.size();

                for(int iteration=0;iteration<q_size;iteration+=1)
                {
                    int student=queue.front();

                    queue.pop_front();

                    if(student==stack.back())
                    {
                        students_ate=true;

                        stack.pop_back();
                    }
                    else
                    {
                        queue.push_back(student);
                    }
                }

                if(students_ate==false)
                {
                    break;
                }
            }

            return queue.size();
        }
};