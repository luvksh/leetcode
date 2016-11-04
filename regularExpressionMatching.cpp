https://leetcode.com/problems/regular-expression-matching/
class Solution {
public:
	bool isMatch(string s, string p) { // TODO test when s and/or are empty or single chars
	    vector<vector<bool>> arr (s.size() + 1);
	    for(int i = 0; i <= s.size(); i++)
	    {
	        arr[i].resize(p.size()+1, false);
	    }
	    arr[0][0] = true;
	    
	    for(int i = 0; i <= s.size(); i++)
	    {
	        for(int j = 1; j <= p.size() ; j++)
	        {
	            if(i > 0)
	            {
	                arr[i][j] = arr[i][j] | (arr[i-1][j-1] && s[i-1]==p[j-1]);
	                arr[i][j] = arr[i][j] | (arr[i-1][j-1] && p[j-1]=='.' && (j < p.size() ? p[j] != '*' : true)); 
	                if(j > 1)
	                {
	                    arr[i][j] = arr[i][j] | (arr[i-1][j] && p[j-1]=='*' && s[i-1] == p[j-2]);	
	                    arr[i][j] = arr[i][j] | (arr[i-1][j] && p[j-1]=='*' && p[j-2] == '.');		 
	                }
	            }
                if(j > 1)
	                arr[i][j] = arr[i][j] | (arr[i][j-2] && p[j-1]=='*');	            
	        }
	    }
	    return arr[s.size()][p.size()];
	}
};