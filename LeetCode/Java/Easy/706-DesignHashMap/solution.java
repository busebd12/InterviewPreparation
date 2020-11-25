import java.util.Arrays;

/*
	Solution: we use an int[] that has size 1000001 (since keys and values will in the range [0, 1000000]) to represent the HashMap.
	The key is the index and the value is whatever value is stored in the array at that index.

	Time complexity: O(10000) => O(1)
	Space complexity: O(10000) => O(1)
*/

class MyHashMap
{
    int[] hashtable;

    public MyHashMap()
    {
        hashtable=new int[1000001];
        
        Arrays.fill(hashtable, -1);
    }
    
    public void put(int key, int value)
    {   
        hashtable[key]=value;
    }
    
    public int get(int key)
    {
        return hashtable[key];
    }
    
    public void remove(int key)
    {
        hashtable[key]=-1;
    }
}