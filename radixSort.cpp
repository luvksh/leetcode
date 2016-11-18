struct functor
{
	int i;
	functor(int d)
	{
		i = d;
	}
	int operator ()(int v)
	{
		int result;
		for (int j = 0; j <= i; j++)
		{
			result = v % 10;
			v = v / 10;
		}
		return result;
	}
};

//int (*func)(int a, int b);
vector<int> CountingSort(vector<int>& v, int k,  functor f)
{
	vector<int> bucket(k, 0);
	for (int i : v)
	{
		bucket[f(i)]++;
	}
	int runningtotal = 0;
	for (int& i : bucket)
	{
		runningtotal += i;
		i = runningtotal;
	}

	vector<int> result(v.size());
	for (int i = v.size()-1; i >= 0; i--)
	{
		result[bucket[f(v[i])]-1] = v[i];
		bucket[f(v[i])]--;
	}
	return result;
}

vector<int> radixSort(vector<int>& v)
{
	int max = v[0];
	for (int i = 0; i < v.size(); i++)
		if (v[i] > max)
			max = v[i];
	int k = 0;
	while (max != 0)
	{
		max = max / 10;
		k++;
	}
	vector<int> res = v;
	for (int i = 0; i < k; i++)
	{
		res = CountingSort(res, 10, functor(i));
	}
	return res;
}

void main()
{
	vector<int> v = {99893, 21291831, 8812, 1912891, 419219, 791291, 319291};
	vector<int> r = radixSort(v);
	//Solution s;
	//string r = s.frequencySort("tree");
}