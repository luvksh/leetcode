class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0;
        int i = 0;
        int max = 0;
        while(i < nums.size()-1)
        {
            jump++;max = 0;
            for(int j = i+1; j <= nums[i] + i; j++)
            {
                if(j >= nums.size() - 1)
                {
                    max = nums.size() - 1;
                    break;
                }
                else if(j+nums[j] > max+nums[max])
                    max = j;
            }
            i = max;
        }
        return jump;
    }
};