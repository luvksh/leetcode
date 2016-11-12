#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_set>
#include<queue>
#include<time.h>
#include<iterator>
#include<iostream>
#include<stack>
#include<set>
#include<unordered_map>
using namespace std;
using namespace std;
class Solution {
public:
	int LCS(string a, string b)
	{
		int m = a.size();
		int n = b.size();
		vector<vector<int>> l(m + 1);
		vector<vector<string>> c(m + 1);
		for (int i = 0; i < m + 1; i++)
		{
			l[i].resize(n + 1, 0);
			c[i].resize(n + 1, "");
		}
		for (int i = 0; i < m + 1; i++)
		{
			for (int j = 0; j < n + 1; j++)
			{
				if (i == 0 || j == 0)
				{
					l[i][j] = 0;
					continue;
				}
				if (a[i - 1] == b[j - 1])
				{
					l[i][j] = l[i - 1][j - 1] + 1;
					c[i][j] = c[i-1][j-1] + a[i-1];
				}
				if (l[i - 1][j] > l[i][j])
				{
					l[i][j] = l[i - 1][j];
					c[i][j] = c[i - 1][j];
				}
				if (l[i][j - 1] > l[i][j])
				{
					l[i][j] = l[i][j - 1];
					c[i][j] = c[i][j-1];
				}
			}
		}
		cout << c[m][n] << endl;
		int s = m;
		int t = n;
		string res = "";
		while (t != 0 && s != 0)
		{
			if (l[s][t] == l[s - 1][t - 1] + 1)
			{
				res = string(1, a[s - 1]) + res;
				s = s - 1;
				t = t - 1;
			}
			else if (l[s][t] == l[s - 1][t])
				s = s - 1;
			else
				t = t - 1;
		}
		cout << res;
		return l[m][n];
	}
};
void main()
{
	Solution s;
	cout << s.LCS("ACCGGTCGAGTGCGCGGAAGCCGGCCGAA", "GTCGTTCGGAATGCCGTTGCTCTGTAAA");
}