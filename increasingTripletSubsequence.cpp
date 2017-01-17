class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i = -1, j= -1;
        for(int p = 1; p < nums.size(); p++)
        {
            if(nums[p] <= nums[p-1])
            {
                if(i != -1 && nums[p] > nums[i])
                    j = p;
            }
            else
            {
                if(j != -1 && nums[p] > nums[j])
                    return true;
                else
                {
                    i = p - 1;
                    j = p;
                }
            }
        }
        return false;
    }
};