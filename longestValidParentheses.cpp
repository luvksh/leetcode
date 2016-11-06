//https://leetcode.com/problems/longest-valid-parentheses/
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<pair<char,int>> stack;
        int counter = 0;
        int max = 0;
        for(char ch:s)
        {
            if(ch == ')')
            {
                if(stack.empty())
                {
                    if(counter > max)
                    {
                        max = counter;
                    }
                    counter = 0;
                }
                else
                {
                    pair<char,int> t = stack.back();
                    stack.pop_back();
                    counter+=2;
                    counter += t.second;
                }
            }
            else
            {
                stack.push_back(make_pair(ch,counter));
                if(counter>max)
                    max = counter;
                counter = 0;
            }
        }
        if(counter>max)
            max = counter;
        return max;
    }
};