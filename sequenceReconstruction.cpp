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
	bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
		map<int, set<int>> edgelist;
		map<int, bool> visited;
		map<int, bool> processed;
		for (auto seq : seqs)
		{
			if (seq.size() == 1)
				edgelist[seq[0]];
			for (int i = 0; i < (int)seq.size() - 1; i++)
			{
				edgelist[seq[i]].insert(seq[i + 1]);
			}
		}

		stack<int> result;

		for (auto node : edgelist)
		{
			if (!visited[node.first])
				if (!dfs(node.first, edgelist, visited, processed, result))
					return false;
		}

		if (result.size() != org.size())
			return false;
		for (int i : org)
		{
			int t = result.top();
			result.pop();
			if (i != t)
				return false;
		}
		return true;
	}

	bool dfs(int s, map<int, set<int>>& edgelist, map<int, bool>& visited, map<int, bool>& processed, stack<int>& result)
	{
		visited[s] = true;
		for (int i : edgelist[s])
		{
			if (!visited[i])
			{
				if (!dfs(i, edgelist, visited, processed, result))
					return false;
			}
			else if (!processed[i])
				return false;
		}
		if (!result.empty() && edgelist[s].find(result.top()) == edgelist[s].end())
			return false;
		processed[s] = true;
		result.push(s);
		return true;
	}
};
void main()
{
	vector<int> org = { 1 };
	vector<vector<int>> seqs = { {1, -9999},{-9999, -9998},{-9998, -9999} };
	Solution s;
	bool r = s.sequenceReconstruction(org, seqs);
}