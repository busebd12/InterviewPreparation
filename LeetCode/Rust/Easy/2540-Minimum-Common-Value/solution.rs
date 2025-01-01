impl Solution
{
    pub fn get_common(nums1: Vec<i32>, nums2: Vec<i32>) -> i32
    {
        let mut result: i32=-1;

        let n: usize=nums1.len();

        let m: usize=nums2.len();

        let mut i: usize=0;

        let mut j: usize=0;

        while i < n && j < m
        {
            if nums1[i] < nums2[j]
            {
                i+=1;
            }
            else if nums1[i] > nums2[j]
            {
                j+=1;
            }
            else
            {
                result=nums1[i];

                break;
            }
        }

        result
    }
}