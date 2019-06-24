#include <vector>
using namespace std;
int* merge(int arr_left[],int sz_left, int arr_right[], int sz_right)
{
    int* arr_merged = new int [sz_left+sz_right];
 
    int n=sz_left;
    
    int m=sz_right;
    
    int i=0;
    
    int j=0;
    
    vector<int> merged;
    
    while(i < n && j < m)
    {
        int first=arr_left[i];
        
        int second=arr_right[j];
        
        if(first==second)
        {
            merged.push_back(first);
            
            merged.push_back(second);
            
            i++;
            
            j++;
        }
        else if(first < second)
        {
            if(i==n-1 && j==m-1)
            {
                merged.push_back(first);
                
                merged.push_back(second);
                
                i++;
                
                j++;
            }
            else
            {
                merged.push_back(first);
            
                i++;
            }
        }
        else
        {
            if(i==n-1 && j==m-1)
            {
                merged.push_back(second);
                
                merged.push_back(first);
                
                i++;
                
                j++;
            }
            
            merged.push_back(second);
            
            j++;
        }
    }
    
    if(i < n)
    {
        for(int index=i;index<n;++index)
        {
            merged.push_back(arr_left[index]);
        }
    }
    
    if(j < m)
    {
        for(int index=j;index<m;++index)
        {
            merged.push_back(arr_right[index]);
        }
    }
    
    int mergedSize=int(merged.size());
    
    for(int x=0;x<mergedSize;++x)
    {
        arr_merged[x]=merged[x];
    }

    return arr_merged;
}
