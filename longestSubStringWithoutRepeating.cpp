class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int prevResult = 0;
        int result = 0;
        string resS = "";
        map<char,bool> m;
        for(char c:s)
        {
            if(m.find(c) == m.end())
            {
                resS.append(1, c);
                m[c] = true;
                result++;
            }
            else
            {
                if(result>prevResult)
                    prevResult = result;
                size_t pos = resS.find(c);
                for(int i = 0; i < pos; i++)
                {
                    m.erase(resS[i]);
                }
                resS = resS.substr(pos+1);
                resS.append(1,c);
                result = resS.size();
            }
        }
        return result > prevResult ? result:prevResult;
    }
};