class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        unordered_map<int, bool> intmap;
        for(int i:nums)
            intmap[i] = true;
        int result = 0;
        for(int i : nums)
        {
            long long p = pow(2, (int)log2(i)+1);
            p--;
            for(int j = p; j >= 0; j--)
            {
                if(intmap.find(i^j) != intmap.end())
                {
                    result = j > result?j:result;
                    break;
                }
            }
        }
        return result;
    }
};