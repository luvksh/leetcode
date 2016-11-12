class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum;
        int carry  = 1;
        vector<int> result(digits.begin(), digits.end());
        for(int i = digits.size() - 1; i >= 0 && carry > 0; i--)
        {
            sum = digits[i] + carry;
            carry = sum/10;
            result[i] = sum%10;
        }
        if(carry > 0)
            result.insert(result.begin(), carry);
        return result;
    }
};