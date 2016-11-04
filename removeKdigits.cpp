https://leetcode.com/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string num, int k) {
        string t = _helper(num, k);
        int i = 0;
        while(t[i] == '0')
            i++;
        t = t.substr(i);
        if(t == "")
            return "0";
        return t;
    }
    
    string _helper(string num, int k)
    {
        if(k == 0)
            return num;
        if(num.size() == k)
            return "";
        int min = num[0]-'0';
        int minI = 0;
        for(int i = 1; i < k+1; i++)
        {
            int n = num[i] - '0';
            if(n < min)
            {
                min = n;
                minI = i;
            }
        }
        string s = string(1,num[minI]);
        string t = _helper(num.substr(minI+1), k-minI);
        s = s + t;
        return s;
    }
};