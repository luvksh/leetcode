class Solution {
    int _findKthLargest(vector<int>& nums, int l, int r, int k)
    {
        if(r == l)
            return nums[r];
        int i = l;
        int j = r - 1;

        while(1)
        {
            while(i < r && nums[i] > nums[r])
                i++;

            while(j >= l && nums[j] <= nums[r])
                j--;
            if(i > j)
                break;
            swap(nums[i], nums[j]);
        }
        j++;
        swap(nums[r], nums[j]);
        if(j+1-l == k)
            return nums[j];
        else if(k < j+1-l)
            return  _findKthLargest(nums, l, j-1, k);
        else
            return _findKthLargest(nums, j+1, r, k-(j+1-l));
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return _findKthLargest(nums, 0, nums.size()-1, k);
    }
};