#include <iostream>
using namespace std;

int findMaxScore(long long int a[], int Start, int End, int Counter)
{
	long long int sum=0;

	int spot;

	//get the sum of the array
	for(int index=Start;index<=End;++index)
	{
		sum+=a[index];
	}

	//if the sum is odd the very first time, we can't split it
	if(sum%2==1 && Counter==0)
	{
		return 0;
	}

	//if we've reached the end of the array
	if(Start==End)
	{
		return Counter;
	}

	long long int increasingSum=0;

	//loop through the numbers, adding to our increasing sum as we subtract from our original sum
	for(spot=Start;spot<=End;++spot)
	{
		increasingSum+=a[spot];

		sum-=a[spot];

		//if we reach a point when the increasing sum is equal to the original sum,  then we have our split point in the array
		if(increasingSum==sum)
		{
			break;
		}
	}

	//if the two sums are not equal, then we have just one number left in each sub-array
	if(increasingSum!=sum)
	{
		return Counter;
	}

	//return the max of the two sub-arrays since we want the highest possible score
	//one array goes from the spot+1 to the end since we dont' want to include the split point
	//the other goes from the start to the split point
	return max(findMaxScore(a, spot+1, End, Counter+1), findMaxScore(a, Start, spot, Counter+1));
}

int main()
{
	int t;

	cin >> t;

	while(t--)
	{
		int n;

		cin >> n;

		long long int a[n];

		for(int i=0;i<n;i++)
		{
			cin >> a[i];
		}

		int counter=0;

		cout << findMaxScore(a, 0, n-1, counter) << endl;
	}

	return 0;
}