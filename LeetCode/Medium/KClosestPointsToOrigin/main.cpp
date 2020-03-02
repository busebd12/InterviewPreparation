#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

/*
 * Solutions:
 *
 * 1. Use a multimap to map the euclidean distance for each point to the point itself. Since we are calculating the
 * distance from the origin, we can just use the squared euclidean distance. The multimap will order its elements in
 * ascending order. Thus, the first K elements in the multimap will be the closest from the origin. So, we just iterate
 * over the multimap and add the first K points to our result vector. Return our result vector.
 *
 * Time complexity: O(n log n) [where n is the number of points]
 * Space complexity: O(n)
 *
 *
 * 2. We can also use a min heap. A min heap has the smallest element in the root. We add all the points to the heap,
 * and then pop the first K ones, which are the closest ones.
 *
 * Time complexity: O(n + Klogn) [where n is the number of points]
 * Space complexity: O(n)
 *
 *
 * 3. We can use a max heap to maintain the K closest points. A max heap has its largest element in the root.
 * Each time we add a point to the heap, if its size exceeds K, we pop the root, which means we get rid of the farthest point and keep the closest ones.
 *
 * Time complexity: O(n * log(K)) [where n is the number of points]
 * Space complexity: O(K)
 *
 *
 * 4. We can use partial_sort algorithm provided by the STL to order the K closest points at the beginning of the vector of points.
 * Here, we need a custom comparator to compare the closeness of points. This custom comparator will compute the squared Euclidean distance.
 *
 * Time complexity: O(n * log(K))
 * Space complexity: O(1) [not counting the output std::vector<std::vector<int>> as extra space]
 *
 *
 * 5. We can use the nth_element algorithm provided by the STL to order the K closest points at the beginning of the vector of points.
 * Here, we need a custom comparator to compare the closeness of points. This custom comparator will compute the squared Euclidean distance.
 *
 * Time complexity: O(n * log(K))
 * Space complexity: O(1) [not counting the output std::vector<std::vector<int>> as extra space]
 */

int getSquaredEuclideanDistance(std::vector<int> & point)
{
    return (point[0] * point[0]) + (point[1] * point[1]);
}

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> & points, int K)
{
    std::vector<std::vector<int>> result;

    if(points.empty() || K <= 0)
    {
        return result;
    }

    std::multimap<int, std::vector<int>> hashtable;

    for(auto & point : points)
    {
        int squaredEuclideanDistance=getSquaredEuclideanDistance(point);

        hashtable.insert(std::make_pair(squaredEuclideanDistance, point));
    }

    for(const auto & element : hashtable)
    {
        if(K==0)
        {
            break;
        }

        result.push_back(element.second);

        K--;
    }

    return result;
}

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> & points, int K)
{
    std::vector<std::vector<int>> result;

    if(points.empty() || K <= 0)
    {
        return result;
    }

    auto comparator=[] (std::vector<int> & p1, std::vector<int> & p2) -> bool {return (p1[0] * p1[0] + p1[1] * p1[1]) > (p2[0] * p2[0] + p2[1] * p2[1]);};

    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(comparator)> minHeap(comparator);

    for(auto & point : points)
    {
        minHeap.push(point);
    }

    while(K > 0)
    {
        result.push_back(minHeap.top());

        minHeap.pop();

        K--;
    }

    return result;
}

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> & points, int K)
{
    std::vector<std::vector<int>> result;

    if(points.empty() || K <= 0)
    {
        return result;
    }

    auto comparator=[] (std::vector<int> & p1, std::vector<int> & p2) -> bool {return (p1[0] * p1[0] + p1[1] * p1[1]) < (p2[0] * p2[0] + p2[1] * p2[1]);};

    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(comparator)> maxHeap(comparator);

    for(auto & point : points)
    {
        maxHeap.push(point);

        if(maxHeap.size() > K)
        {
            maxHeap.pop();
        }
    }

    while(!maxHeap.empty())
    {
        result.push_back(maxHeap.top());

        maxHeap.pop();
    }

    return result;
}

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> & points, int K)
{
    std::partial_sort(points.begin(), points.begin() + K, points.end(), [] (std::vector<int> & p1, std::vector<int> & p2) -> bool {return (p1[0] * p1[0] + p1[1] * p1[1]) < (p2[0] * p2[0] + p2[1] * p2[1]);});

    std::vector<std::vector<int>> result(points.begin(), points.begin() + K);

    return result;
}

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> & points, int K)
{
    std::nth_element(points.begin(), points.begin() + K-1, points.end(), [] (std::vector<int> & p1, std::vector<int> & p2) -> bool {return (p1[0] * p1[0] + p1[1] * p1[1]) < (p2[0] * p2[0] + p2[1] * p2[1]);});

    std::vector<std::vector<int>> result(points.begin(), points.begin() + K);

    return result;
}