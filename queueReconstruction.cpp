//https://leetcode.com/problems/queue-reconstruction-by-height/
struct comparator
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		if (a.first == b.first) return a.second > b.second;
		else return a.first < b.first;
	}
}mycomparator;
class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		sort(people.begin(), people.end(), mycomparator);
		vector<pair<int, int>> temp(people.begin(), people.end());
		vector<pair<int, int>> result;
		vector<bool> flag(people.size(), false);
		for (int i = 0; i < people.size(); i++)
		{
			for (int j = 0; j < people.size(); j++)
			{
				if (flag[j] == true)
					continue;
				if (temp[j].second == 0)
				{
					result.push_back(people[j]);
					flag[j] = true;
					break;
				}
				else
				{
					temp[j].second--;
				}
			}
		}
		return result;
	}
};