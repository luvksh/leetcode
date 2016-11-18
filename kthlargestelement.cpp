class Solution {
    int partition(vector<int>& nums, int l, int r)
    {
        int i = l-1;
        for(int j = l; j < r; j++)
        {
            if(nums[j] > nums[r])
            {
                i++;
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[r], nums[i+1]);
        return i+1;
    }
    int randomized_partition(vector<int>& nums, int l, int r)
    {
        int a = rand()%(r-l+1) + l;
        swap(nums[a], nums[r]);
        return partition(nums, l, r);
    }
    int _findKthLargest(vector<int>& nums, int l, int r, int k)
    {
        if(l==r)
            return nums[l];
        int p = randomized_partition(nums, l, r);
        if(k == p-l+1)
            return nums[p];
        else if(k < p-l+1)
            return _findKthLargest(nums, l, p-1, k);
        else
            return _findKthLargest(nums, p+1, r, k-(p+1-l));
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return _findKthLargest(nums, 0, nums.size()-1, k);
    }
};