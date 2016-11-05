https://leetcode.com/problems/rotate-function/
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int total = 0;
        int fprev = 0;
        for(int i = 0; i < A.size(); i++)
        {
            total += A[i];
            fprev += i*A[i];
        }
        
        int sum = 0;
        int max = fprev;
        for(int i = 0; i < A.size(); i++)
        {
            sum = fprev;
            sum -= (A.size()-1) * A[A.size()-1-i];
            sum += (total - A[A.size()-1-i]);
            if(sum > max)
                max = sum;
            fprev = sum;
        }
        return max;
    }
};