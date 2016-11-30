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
	vector<int> maxksubarray(vector<int> arr, int k) {
		int right = 0;
		int left = 0;
		vector<int> result;
		deque<int> q;
		while (right < arr.size())
		{
			while (!q.empty() && arr[right] > q.back())
				q.pop_back();
			q.push_back(arr[right]);

			right++;
			if (right >= k)
			{
				result.push_back(q.front());
				if (arr[left] == q.front())
				{
					q.pop_front();
				}
				left++;
			}
		}
		return result;
	}
};
void main()
{
	Solution s;
	vector<int> a = { 1,2,3, 1, 1, 1, 4, 8, 7, 6, 5, 4, 3, 2, 1 };
	vector<int> r = s.maxksubarray(a, 3);
}