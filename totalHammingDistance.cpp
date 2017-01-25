class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int max_msb = 0;
        for(int i:nums)
        {
            int msb = log2(i);
            max_msb = msb > max_msb ? msb : max_msb;
        }
        int result = 0;
        for(int i = 0; i <= max_msb; i++)
        {
            int c0 = 0, c1 = 0;
            for(int j:nums)
            {
                if(j & (1 << i))
                    c1++;
                else
                    c0++;
            }
            result += c1*c0;
        }
        return result;
    }
};