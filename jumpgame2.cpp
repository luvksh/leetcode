class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0;
        int maxrange = 0;
        int index;
        int counter = 0;
        while(i < nums.size() - 1 )
        {
            if(nums[i]+i >= nums.size()-1)
            {
                counter++;
                break;
            }
            maxrange = 0;
            for(int j = 1; j <= nums[i]; j++)
            {
                if(nums[j+i]+j+i > maxrange)
                {
                    maxrange = nums[j+i]+j+i;
                    index = j+i; 
                }
            }
            i = index;
            counter++;
        }
        return counter;
    }
};