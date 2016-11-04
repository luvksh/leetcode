//http://www.geeksforgeeks.org/dynamic-programming-set-32-word-break-problem/
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
class Solution {
public:
	bool wordBreak(unordered_set<string> dict, string a)
	{
		vector<vector<bool>> arr;
		arr.resize(a.size());
		for (int i = 0; i < a.size(); i++)
			arr[i].resize(a.size() + 1, false);
		for (int i = 0; i < a.size(); i++)
			arr[i][i] = dict.find(string(1, a[i])) != dict.end();
		for (int p = a.size()-1; p > 0; p--)
		{
			for (int i = 0; i < p; i++)
			{
				for (int q = i; q < i + a.size() - p; q++)
					arr[i][i + a.size() - p] = arr[i][i + a.size() - p] || (arr[i][q] && arr[q + 1][i + a.size() - p]);
				arr[i][i + a.size() - p] = arr[i][i + a.size() - p] || (dict.find(a.substr(i, a.size() - p + 1)) != dict.end());
			}
		}
		return arr[0][a.size()-1];
	}
};

void main()
{
	Solution s;
	unordered_set<string> dict = { "i", "like", "sam", "sung", "samsung", "mobile", "ice",
		"cream", "icecream", "man", "go", "mango" };
	bool r = s.wordBreak(dict, "ilikesamsunga");
}