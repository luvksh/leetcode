https://leetcode.com/problems/longest-repeating-character-replacement/
class Solution {
    int calculateMaxOneChar(list<int>& l, int k)
    {
        queue<int> q;
        auto li = l.begin();
        int maxlen = 0;
        int currlen;
        int currentk;
        while(li != l.end())
        {
            if(q.empty())
            {
                q.push(*li);
                currlen = 1;
                currentk = 0;
            }
            else
            {
                int b = q.back();
                q.push(*li);
                currlen += (*li - b);
                currentk += (*li - b - 1);
                while(currentk > k && !q.empty())
                {
                    int f = q.front();
                    q.pop();
                    currentk -= (q.front() - f -1);
                    currlen -= (q.front() - f);
                }
            }
            if(currlen > maxlen)
                maxlen = currlen;
            li++;
        }
        return maxlen;
    }
public:
    int characterReplacement(string s, int k) {
        int result = 0;
        unordered_map<char, list<int>> mymap;
        for(int i = 0; i < s.size(); i++)
            mymap[s[i]].push_back(i);
        for(auto e:mymap)
        {
            int r = calculateMaxOneChar(e.second, k);
            result =  r > result ? r:result;
        }
        return result;
    }
};