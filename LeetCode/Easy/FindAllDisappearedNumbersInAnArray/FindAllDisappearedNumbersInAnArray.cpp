#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums)
{
	vector<int> result;

	int n=(int)nums.size();

	unordered_set<int> numbers;

	for(const auto & number : nums)
	{
		numbers.insert(number);
	}

	for(int number=1;number<=n;++number)
	{
		if(numbers.find(number)==end(numbers))
		{
			result.emplace_back(number);
		}
	}

	return result;
}