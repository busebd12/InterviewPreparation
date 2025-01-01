#include <vector>
using namespace std;

/*
Time complexity: O(n log n) [where n=length of nums1 and nums2]
Space complexity: O(n)
*/

class Solution
{
    public:
        long long numberOfPairs(vector<int> & nums1, vector<int> & nums2, int diff)
        {
            long long result=0;

            int n=nums1.size();

            /*
            The inequality nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff can be re-arranged like so:

            1) Start with nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff

            2) Group like terms to get nums1[i] - nums2[i] <= nums1[j] - nums2[j] + diff

            3) Let A[i]=nums1[i] - nums2[i] and A[j]=nums1[j] - nums2[j]. The inequality then becomes A[i] <= A[j] + diff

            So, we need to compare the differences between A[i] and A[j]

            The question also stipulates that, for each pair, index i must be strictly less than j (aka i comes before j)

            Okay, well, what's an algorithm that specializes in comparing pairs of numbers while also guaranteeing that one index will
            always come before the other? The answer is merge sort.

            Great, how do we apply merge sort here?

            We do the following:

            1) Create a vector called differences that will store the difference between nums1[i] and nums2[i] for all i from 0 to n-1

            2) Sort the differences array/vector using merge sort. As part of the this process, we will recursively divide the differences array/vector in half each time until we have two halves of size 1.

            Then, we will merge each of these sorted halves into a single sorted list.

            Awesome, where do we actually count the pairs? We do the counting right before we merge the two sorted halves.

            After the counting, we proceed to merge the sorted halves like normal.

            3) After doing mergeSort, we simply return the result
            */

            //vector of differences as discussed above
            vector<int> differences;

            //Create the differences like discussed above
            for(int i=0;i<n;i++)
            {
                int difference=nums1[i] - nums2[i];

                differences.push_back(difference);
            }

            int low=0;

            int high=n-1;

            mergeSort(differences, result, diff, low, high);

            return result;
        }

        void mergeSort(vector<int> & differences, long long & result, int diff, int low, int high)
        {
            if(low >= high)
            {
                return;
            }

            int middle=(low + (high - low)/2);

            mergeSort(differences, result, diff, low, middle);

            mergeSort(differences, result, diff, middle + 1, high);

            mergeTwoHalves(differences, result, diff, low, middle, high);
        }

        void mergeTwoHalves(vector<int> & differences, long long & result, int diff, int low, int middle, int high)
        {
            int extraSpace=(high - low) + 1;

            vector<int> lounge(extraSpace);

            int i=low;

            int j=middle + 1;

            int loungeIndex=0;

            //Here's where we will actually count the pairs while iterating through both of the sorted halves
            while(i <= middle and j <= high)
            {
                //This is the condition satisfying the inequality we talked about before
                if(differences[i] <= differences[j] + diff)
                {
                    //Since the two halves are in sorted order, all differences differences[j] that come
                    //after the current differences[j] will be greater than or equal to the current differences[j]
                    //So, if differences[i] is already less than or equal to the differences[j] + diff,
                    //then it will definitely be less than or equal to the remaining differences that come after differences[j].
                    //How many total pairs is that? Since j is iterating from middle + 1 to high, the number of values in that range is (high - j) + 1
                    long long pairs=(high - j) + 1;

                    //Add the number of pairs to the result
                    result+=pairs;

                    i+=1;
                }
                //Else, differences[i] is too big to satisfy the inequality condition and we need to increase the value for differences[j]
                else
                {
                    j+=1;
                }
            }

            //At this point, we have finished counting the pairs, all that's left is to perform normal merging of the two sorted halves
            i=low;

            j=middle + 1;

            while(i <= middle and j <= high)
            {
                if(differences[i] <= differences[j])
                {
                    lounge[loungeIndex]=differences[i];

                    i+=1;
                }
                else
                {
                    lounge[loungeIndex]=differences[j];

                    j+=1;
                }

                loungeIndex+=1;
            }

            while(i <= middle)
            {
                lounge[loungeIndex]=differences[i];

                i+=1;

                loungeIndex+=1;
            }

            while(j <= high)
            {
                lounge[loungeIndex]=differences[j];

                j+=1;

                loungeIndex+=1;
            }

            loungeIndex=0;

            for(int k=low;k<=high;k++)
            {
                differences[k]=lounge[loungeIndex];

                loungeIndex+=1;
            }
        }
};