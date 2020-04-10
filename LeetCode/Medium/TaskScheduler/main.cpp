#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

/*
 * Solution: we use a hashtable (std::unordered_map<char, int>) to count the frequency of each job.
 * Next, we place all the pairs from the hashtable into a maximum heap (priority_queue) so that the
 * job that occurs the most will be on top. Then, while we still have jobs left, we pop off a job from
 * the top of the heap and add the job to our path. Then, we have to put a total of n different things
 * between the current job and the next occurrence of the job, where the things are either idle cycles,
 * different jobs, or a combination of the two. So, we count from 1 to n (inclusive) and while we do,
 * we pop jobs from the heap and add them to our path. When we run out of jobs (the heap is empty),
 * then we have to fill the remaining spaces with idle cycles (represented by the # sign).
 * Then, we re-add all the jobs we removed from the heap back into the heap (if the frequency of the job is greater than zero).
 *
 * Time complexity: O(t + u + (u log n)) [where t is the number of tasks, u is the number of unique tasks, and n
 * is the interval we have to have between two of the same task]
 *
 * Space complexity: O((u * n) + p) [where u is the number of unique tasks, p is the size of the path we create, and n
 * is the interval we have to have between two of the same task]
 *
 *
 * 2. Similar to the first solution except that we don't build the path as we go, we just keep track of the path length.
 *
 * Time complexity: O(t + u + (u log n)) [where t is the number of tasks, u is the number of unique tasks, and n
 * is the interval we have to have between two of the same task]
 *
 * Space complexity: O(u * n) [where u is the number of unique tasks, and n is the interval we have to have between two of the same task]
 *
 */

int leastInterval(std::vector<char> & tasks, int n)
{
    int result=0;

    if(tasks.empty())
    {
        return 0;
    }

    std::unordered_map<char, int> hashtable;

    for(const auto & task : tasks)
    {
        hashtable[task]++;
    }

    auto comparator=[] (const auto & p1, const auto & p2) {return p1.second < p2.second;};

    std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, decltype(comparator)> maxHeap(comparator);

    for(const auto & [key, value] : hashtable)
    {
        maxHeap.emplace(std::make_pair(key, value));
    }

    std::vector<char> path;

    while(!maxHeap.empty())
    {
        std::vector<std::pair<char, int>> jobs;

        auto firstJob=maxHeap.top();

        maxHeap.pop();

        path.emplace_back(firstJob.first);

        firstJob.second--;

        jobs.emplace_back(firstJob);

        int count=1;

        while(!maxHeap.empty() && count <= n)
        {
            auto job=maxHeap.top();

            maxHeap.pop();

            path.emplace_back(job.first);

            job.second--;

            jobs.emplace_back(job);

            count++;
        }

        while(count <= n)
        {
            path.emplace_back('#');

            count++;
        }

        if(!jobs.empty())
        {
            for(const auto & job : jobs)
            {
                if(job.second > 0)
                {
                    maxHeap.emplace(job);
                }
            }
        }
    }

    while(path.back()=='#')
    {
        path.pop_back();
    }

    result=static_cast<int>(path.size());

    return result;
}

int leastInterval(std::vector<char> & tasks, int n)
{
    int result=0;

    if(tasks.empty())
    {
        return 0;
    }

    std::unordered_map<char, int> hashtable;

    for(const auto & task : tasks)
    {
        hashtable[task]++;
    }

    auto comparator=[] (const auto & p1, const auto & p2) {return p1.second < p2.second;};

    std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, decltype(comparator)> maxHeap(comparator);

    for(const auto & [key, value] : hashtable)
    {
        maxHeap.emplace(std::make_pair(key, value));
    }

    while(!maxHeap.empty())
    {
        std::vector<std::pair<char, int>> jobs;

        auto firstJob=maxHeap.top();

        maxHeap.pop();

        result++;

        firstJob.second--;

        jobs.emplace_back(firstJob);

        int count=0;

        while(!maxHeap.empty() && count < n)
        {
            auto job=maxHeap.top();

            maxHeap.pop();

            result++;

            job.second--;

            jobs.emplace_back(job);

            count++;
        }

        if(!jobs.empty())
        {
            for(const auto & job : jobs)
            {
                if(job.second > 0)
                {
                    maxHeap.emplace(job);
                }
            }
        }

        if(maxHeap.empty())
        {
            break;
        }

        if(count < n)
        {
            result+=(n-count);
        }
    }

    return result;
}