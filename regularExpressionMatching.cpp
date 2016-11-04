https://leetcode.com/problems/regular-expression-matching/
class Solution {
public:
	bool isMatch(string s, string p) {
		string normP = normalize(p);
		int n = s.size();
		int m = getNumOfTokens(normP);
		vector<vector<bool>> dp;
		dp.resize(n+1);
		for (int i = 0; i <= n; i++)
		{
			dp[i].resize(m+1);
		}

		dp[0][0] = true;
		int nextPos = 0;
		for (int j = 1; j <= m; j++)
		{
		    int t = getSymbol(p, nextPos);
			if (t==1||t==3)
				dp[0][j] = dp[0][j-1];
			else
				dp[0][j] = false;
		}
		for (int i = 1; i <= n; i++)
		{
			dp[i][0] = false;
		}

		for (int i = 1; i <= n; i++)
		{
			int nextPos = 0;
			for (int j = 1; j <= m; j++)
			{

				int t = getSymbol(p, nextPos);
				switch (t)
				{
				case 1:
					dp[i][j] = dp[i - 1][j - 1] || dp[i][j - 1]|| dp[i-1][j];
					break;
				case 2:
					dp[i][j] = dp[i - 1][j - 1];
					break;
				case 3:
					if (s[i-1] == p[nextPos - 2])
					{
						dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j];
					}
					dp[i][j] = dp[i][j] || dp[i][j - 1];
					break;
				case 4:
					if (s[i-1] == p[nextPos - 1])
					{
						dp[i][j] = dp[i - 1][j - 1];
					}
					else
					{
						dp[i][j] = false;
					}
				}
				//dp(i,j) = dp(i-1, j-1) || d(i, j-1) if p[j] == '.*'
				//          || dp(i-1,j-1) if j is char* && s[i] matches char
				//          || dp(i, j-1) if j is char* && s[i] does not match char
				//          || dp(i-1, j-1) if j is dot
				//          || dp(i-1,j-1) if s[i] == p[j]
				//
			}
		}
		return dp[n][m];

	}
private:

	string normalize(string p)
	{
		string r = "";
		if (p == "")
			return p;
		//assert(p[0] != '*');
		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] == '*' && p[i - 1] == '*')
			{

			}
			else
			{
				r.append(1, p[i]);
			}
		}
		return r;
	}

	int getNumOfTokens(string p)
	{
		int r = 0;
		for (char ch : p)
		{
			if (ch != '*')
				r++;
		}
		return r;
	}

	int getSymbol(string p, int &ip)
	{
		if (p[ip] == '.' && (ip + 1) < p.size() && p[ip + 1] == '*')
		{
			ip += 2;

			return 1;
		}
		else if (p[ip] == '.')
		{
			ip += 1;
			return 2;
		}
		else if ((ip + 1) < p.size() && p[ip + 1] == '*')
		{
			ip += 2;
			return 3;
		}
		else
		{
			ip += 1;
			return 4;
		}
	}
};