#include <unordered_set>
using namespace std;
int find_missing_number(int arr[], int n) 
{
    unordered_set<int> numbers;
    
    for(int number=1;number<=n;++number)
    {
        numbers.insert(number);
    }
    
    for(int i=0;i<n;++i)
    {
        int number=arr[i];
        
        if(numbers.count(number))
        {
            numbers.erase(number);
        }
    }
    
    return *(numbers.begin());
}
