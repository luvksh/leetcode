//https://leetcode.com/problems/longest-valid-parentheses/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int>> stck;
        int max = 0;
        int n = 0;
        for(char ch:s)
        {
            if(ch == '(')
            {
                stck.push(make_pair(ch, n+2));
                n = 0;
            }
            if(ch == ')')
            {
                if(stck.empty())
                    n = 0;
                else
                {
                    n += stck.top().second;
                    stck.pop();
                    if(n > max)
                        max = n;
                }
            }
        }
        return max;
    }
};
};