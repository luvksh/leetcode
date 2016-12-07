https://leetcode.com/problems/binary-watch/
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        set<string> res;
        vector<string> result;
        int x = 0;
        _dfs(x, num, res);
        for(string s:res)
            result.push_back(s);
        return result;
    }
    
    void _dfs(int x, int num, set<string>& res)
    {
        if(num == 0)
        {
            string s = to_time(x);
            if(s != "")
                res.insert(s);
            return;
        }
        int b = 0x1;
        for(int i=0; i < 10; i++)
        {
            int y;
            if(!(x&(b<<i)))
            {
                y = x | (b<<i);
                _dfs(y, num-1, res);
            }
        }
    }
    
    string to_time(int x)
    {
        int min = x & 0x3f;
        int hr = x >> 6;
        if(min > 59)
            return "";
        if(hr > 11)
            return "";
        string m = to_string(min);
        if(m.size() == 1)
            m = "0" + m;
        return to_string(hr) + ":" + m;
    }
};