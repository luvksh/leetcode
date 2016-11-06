class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charmap;
        int max = 0;
        int start = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(charmap.find(s[i]) != charmap.end() && charmap[s[i]] >= start)
            {
                if(i - start > max)
                    max = i - start;
                start = charmap[s[i]] + 1;
            }
            charmap[s[i]] = i;
        }
        if(s.size() - start > max)
            max = s.size() - start;
        return max;
    }
};