https://leetcode.com/problems/rotate-function/
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
        if(n == 0) return 0;
        int max = INT_MIN;
        int totalSum = 0;
        int prevf = 0;
        int lastNum;
        for(int i = 0; i < n; i++)
        {
            totalSum += A[i];
            prevf += i*A[i];
        }
        
        lastNum = A[n-1];
        max = prevf;
        
        for(int i = 1; i < n; i++)
        {
            int sum = prevf;
            sum -= (lastNum *(n-1));
            sum += (totalSum - lastNum);
            lastNum = A[n-i-1];
            if(sum > max)
                max = sum;
            prevf = sum;
        }
        return max;
    }
};