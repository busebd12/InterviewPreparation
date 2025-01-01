#include <deque>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: level order traversal + hashmap (vector<unordered_map<int, int>>)

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(n)
*/

class Solution
{
    public:
        int pathSum(vector<int> & nums)
        {
            int result=0;

            int n=nums.size();

            vector<unordered_map<int, int>> levels(5, unordered_map<int, int>());

            int rootLevel=-1;

            int rootRowPosition=-1;

            int rootValue=-1;

            for(int number : nums)
            {
                int copy=number;

                deque<int> digits;

                while(copy > 0)
                {
                    digits.emplace_front(copy % 10);

                    copy=copy / 10;
                }

                int level=digits[0];

                int rowPosition=digits[1];

                int value=digits[2];

                levels[level].emplace(rowPosition, value);

                if(level==1)
                {
                    rootLevel=level;

                    rootRowPosition=rowPosition;

                    rootValue=value;
                }
            }

            deque<tuple<int, int, int>> queue;

            queue.emplace_back(rootLevel, rootRowPosition, rootValue);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    auto [level, rowPosition, pathSum]=queue.front();

                    queue.pop_front();

                    int nextLevel=level + 1;

                    if(nextLevel < 5)
                    {
                        bool hasChildren=false;

                        int leftChildRowPosition=(rowPosition * 2) - 1;

                        if(levels[nextLevel].find(leftChildRowPosition)!=levels[nextLevel].end())
                        {
                            int leftChildValue=levels[nextLevel][leftChildRowPosition];

                            hasChildren=true;

                            queue.emplace_back(nextLevel, leftChildRowPosition, pathSum + leftChildValue);
                        }

                        int rightChildRowPosition=rowPosition * 2;

                        if(levels[nextLevel].find(rightChildRowPosition)!=levels[nextLevel].end())
                        {
                            int rightChildValue=levels[nextLevel][rightChildRowPosition];

                            hasChildren=true;

                            queue.emplace_back(nextLevel, rightChildRowPosition, pathSum + rightChildValue);
                        }

                        if(hasChildren==false)
                        {
                            result+=pathSum;
                        }
                    }
                    else
                    {
                        result+=pathSum;
                    }
                }
            }

            return result;
        }
};