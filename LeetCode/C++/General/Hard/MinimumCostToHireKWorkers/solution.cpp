#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

/*
Solution 1: inspired by this resource --> https://www.youtube.com/watch?v=FhEbfSRuNNA

Time complexity: O(n log n)
Space complexity: O(n)
*/

class Solution
{
    public:
        double mincostToHireWorkers(vector<int> & quality, vector<int> & wage, int k)
        {
            double result=0;

            int n=quality.size();

            vector<pair<double, int>> workers;

            for(int i=0;i<n;i++) //O(n)
            {
                //How much we pay this worker for each quality unit they produce
                //Each worker has a minimum wage per quality unit expectation ratio of wage[worker] / quality[worker]
                double minWagePerQualityUnitRatio=(double)wage[i] / (double)quality[i];

                int workerQuality=quality[i];

                workers.emplace_back(minWagePerQualityUnitRatio, workerQuality);
            }

            //Sort the workers in increasing order by their minWagePerQualityUnitRatio
            //For a group of k paid workers, the amount of money we have to pay them is
            //the sum of the quality of each worker multiplied by the wage per quality
            //unit expectation ratio of the highest paid worker in order to satisfy all workers
            sort(workers.begin(), workers.end()); //O(n log n)

            //Sum of the qualities of each worker from our k paid group
            int sumOfWorkerQualities=0;

            //Store worker qualities in a maximum heap so we always have access to the highest worker quality in O(1) time
            //This will also help us keep the sum of the qualities of our k-paid workers at a minimum at all times
            priority_queue<int, vector<int>, less<int>> maxHeap;

            //Form the first group of k paid workers
            for(int worker=0;worker<k;worker++) //O(k)
            {
                int workerQuality=workers[worker].second;

                sumOfWorkerQualities+=workerQuality;

                maxHeap.push(workerQuality);
            }

            //Calculate the cost for first group of k paid workers
            //workers[k - 1] is the worker with the highest minimum wage per quality unit expectation ratio
            result=sumOfWorkerQualities * workers[k - 1].first;

            for(int worker=k;worker<n;worker++) //O(n)
            {
                int currentWorkerQuality=workers[worker].second;

                int maxWorkerQualitySoFar=maxHeap.top();

                //If the quality of the current worker is less than the quality of the worker in the k group with the highest quality
                if(maxWorkerQualitySoFar > currentWorkerQuality)
                {
                    //Remove the worker with the highest quality from the k group
                    maxHeap.pop();

                    //Add the current worker's quality to the maximum heap
                    maxHeap.push(currentWorkerQuality); //O(log(n - k))

                    //Update the sumOfWorkerQualities to reflect removing the worker with the highest quality and the new worker we just added
                    sumOfWorkerQualities-=maxWorkerQualitySoFar;

                    sumOfWorkerQualities+=currentWorkerQuality;
                }

                //Calculate a possible new minimum cost
                double nextMinCost=sumOfWorkerQualities * workers[worker].first;

                //If the cost for the k group is less than the previous
                if(nextMinCost < result)
                {
                    result=nextMinCost;
                }
            }

            return result;
        }
};

/*
Solution 2:

Time complexity: O(n log n)
Space complexity: O(n)
*/

class Solution
{
    public:
        double mincostToHireWorkers(vector<int> & quality, vector<int> & wage, int k)
        {
            double result=numeric_limits<double>::max();

            int n=quality.size();

            vector<pair<double, int>> workers;

            for(int i=0;i<n;i++) //O(n)
            {
                //How much we pay this worker for each quality unit they produce
                //Each worker has a minimum wage per quality unit expectation ratio of wage[worker] / quality[worker]
                double minWagePerQualityUnitRatio=(double)wage[i] / (double)quality[i];

                int workerQuality=quality[i];

                workers.emplace_back(minWagePerQualityUnitRatio, workerQuality);
            }

            //Sort the workers in increasing order by their minWagePerQualityUnitRatio
            //For a group of k paid workers, the amount of money we have to pay them is
            //the sum of the quality of each worker multiplied by the wage per quality unit
            //expectation ratio of the highest paid worker in order to satisfy all workers
            sort(workers.begin(), workers.end()); //O(n log n)

            //Sum of the qualities of each worker from our k paid group
            int sumOfWorkerQualities=0;

            //Store worker qualities in a maximum heap of max size k so we always have the qualities of our k paid group of workers
            priority_queue<int, vector<int>, less<int>> maxHeap;

            for(int worker=0;worker<n;worker++) //O(n)
            {
                int currentWorkerQuality=workers[worker].second;
                
                sumOfWorkerQualities+=currentWorkerQuality;

                maxHeap.push(currentWorkerQuality);

                //If the heap size becomes greater than k, then we need to remove the worker with the maximum quality from our k group
                if(maxHeap.size() > k) //O(log(k))
                {
                    int maxWorkerQualitySoFar=maxHeap.top();
                    
                    maxHeap.pop();

                    //Update the sum of our k group worker qualities
                    sumOfWorkerQualities-=maxWorkerQualitySoFar;
                }

                //If the max heap size is k, we have found a k paid group
                if(maxHeap.size()==k)
                {
                    double currentWorkerMinWagePerQualityUnitRatio=workers[worker].first;

                    //Calculate the cost of this k paid group
                    double kGroupCost=sumOfWorkerQualities * currentWorkerMinWagePerQualityUnitRatio;

                    //If this cost is less than the previous cost, then update the minimum cost
                    if(kGroupCost < result)
                    {
                        result=kGroupCost;
                    }
                }
            }

            return result;
        }
};