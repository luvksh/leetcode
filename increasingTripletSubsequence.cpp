class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        pair<int, int> two = make_pair(-1,-1);
        int one = -1;
        for(int i=0; i <nums.size(); i++)
        {
            if(two.first != -1 && nums[i] > nums[two.second])
                return true;
            if(one != -1)
            {
                if(nums[i] > nums[one])
                {
                    two.first = one;
                    two.second = i;
                    one = -1;
                }
                else
                {
                    one = i;
                }
            }
            else if(two.first != -1 && nums[i] > nums[two.first])
                two.second = i;
            else if(one == -1)
            {
                one = i;
            }
        }
        return false;
    }
};