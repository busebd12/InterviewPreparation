#include "../ListNode.h"
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

/*
 * Solutions:
 *
 * 1. For each linked list, we copy the contents into a std::vector<int> and then put the vector into a vector
 * of vectors. Then, we use a hashtable (std::unordered_map<int, int>) to map the index of each vector to the
 * size of each vector. Next, we calculate the length of the longest vector. We then iterate from 0 up to the
 * length of the longest vector and add the number at the current index from each vector, if that index is in
 * the range [0, size of the current vector], into a minimum heap. This way, the numbers in the heap will be in
 * sorted order. Then, we create the resulting linked list from the contents of the minimum heap.
 *
 * Time complexity: O((n * a) + n + (l * (k * log(t))) + t^2)
 * [n=length of input lists vector; a=average length of linked list within lists; l=length of the longest linked list;
 * k=number of unique keys in the hashtable; t=total number of element from all the linked lists]
 *
 * Space complexity: O(t + k)
 *
 * 2. Instead of placing the contents of each linked list into its own vector, we simply iterate over all the linked
 * lists in lists and add every number of a minimum heap. This way, the numbers in the heap will be in
 * sorted order. Then, we create the resulting linked list from the contents of the minimum heap.
 *
 * Time complexity: O((n * a * log(t)) + t^2)
 * [where n=length of input lists vector; a=average length of linked list within lists; l=length of the longest linked list; t=total number of element from all the linked lists]
 *
 * Space complexity: O(t)
 *
 * 3. We put all the lists into a minimum heap. Since the lists are sorted, the lists with the smallest elements at
 * the start of the lists will be higher up in the heap. Then, while the heap is not empty, we pop the top pointer
 * from the heap and add it to the result linked list. If the next pointer in the linked list is not nullptr, we
 * add it back in the heap. By doing this, we will move through all the lists from beginning to end. Thus, because
 * all the input linked lists were sorted, our output linked list will also be sorted.
 *
 * Time complexity: O((n * log(n)) + (t * log(t)) [where n is the number of linked lists and t is the total number of elements from all the linekd lists]
 * Space complexity: O(t)
 */

void addToEnd(ListNode* & head, const int & value)
{
    if(head==nullptr)
    {
        head=new ListNode(value);
    }
    else
    {
        ListNode* current=head;

        while(current->next!=nullptr)
        {
            current=current->next;
        }

        current->next=new ListNode(value);
    }
}

std::vector<int> listToVector(ListNode* & head)
{
    std::vector<int> numbers;

    ListNode* current=head;

    while(current!=nullptr)
    {
        numbers.emplace_back(current->val);

        current=current->next;
    }

    return numbers;
}

ListNode* mergeKLists(std::vector<ListNode*> & lists)
{
    ListNode* result=nullptr;

    if(lists.empty())
    {
        return result;
    }

    std::vector<std::vector<int>> listsCopy;

    for(auto & list : lists)
    {
        listsCopy.emplace_back(listToVector(list));
    }

    std::unordered_map<int, int> hashtable;

    auto n=int(listsCopy.size());

    auto maxLength=std::numeric_limits<int>::min();

    for(auto i=0;i<n;++i)
    {
        auto size=int(listsCopy[i].size());

        hashtable[i]=size;

        maxLength=std::max(maxLength, size);
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for(auto i=0;i<maxLength;++i)
    {
        for(const auto & [key, value] : hashtable)
        {
            if(i < value)
            {
                minHeap.emplace(listsCopy[key][i]);
            }
        }
    }

    while(!minHeap.empty())
    {
        addToEnd(result, minHeap.top());

        minHeap.pop();
    }

    return result;
}

void addToEnd(ListNode* & head, const int & value)
{
    if(head==nullptr)
    {
        head=new ListNode(value);
    }
    else
    {
        ListNode* current=head;

        while(current->next!=nullptr)
        {
            current=current->next;
        }

        current->next=new ListNode(value);
    }
}

ListNode* mergeKLists(std::vector<ListNode*> & lists)
{
    ListNode* result=nullptr;

    if(lists.empty())
    {
        return result;
    }

    ListNode* dummy=new ListNode(-1);

    result=dummy;

    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for(auto & list : lists) //O(n)
    {
        ListNode* walker=list;

        while(walker!=nullptr) //O(a)
        {
            minHeap.emplace(walker->val); //log(t)

            walker=walker->next;
        }
    }

    while(!minHeap.empty()) //O(t)
    {
        addToEnd(result, minHeap.top()); //O(t)

        minHeap.pop();
    }

    return result->next;
}

ListNode* mergeKLists(std::vector<ListNode*> & lists)
{
    ListNode* result=nullptr;

    if(lists.empty())
    {
        return result;
    }

    ListNode* dummy=new ListNode(-1);

    result=dummy;

    auto comparator=[] (ListNode* & l1, ListNode* & l2) {return l1->val > l2->val;};

    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(comparator)> minHeap(comparator);

    for(auto & list : lists)
    {
        if(list!=nullptr)
        {
            minHeap.emplace(list);
        }
    }

    while(!minHeap.empty())
    {
        auto current=minHeap.top();

        minHeap.pop();

        dummy->next=new ListNode(current->val);

        dummy=dummy->next;

        if(current!=nullptr)
        {
            current=current->next;
        }

        if(current!=nullptr)
        {
            minHeap.emplace(current);
        }
    }

    return result->next;
}