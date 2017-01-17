class Solution {
	bool _canIWin(int a, int desiredTotal, unordered_map<int, bool>& cache)
	{
		int m = log2(a) + 1;
		if (m >= desiredTotal)
		{
			return true;
		}
		if (cache.find(a) != cache.end())
			return cache[a];
		for (int i = 0; i < m; i++)
		{
			if (!(a&(1 << i)))
				continue;
			bool r = _canIWin(a&~(1 << i), desiredTotal - i - 1, cache);
			if (!r)
			{
				cache[a] = true;
				return true;
			}
		}
		cache[a] = false;
		return false;
	}
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		unordered_map<int, bool> cache;
		if(desiredTotal > maxChoosableInteger*(maxChoosableInteger+1)/2)
		    return false;
		int a = pow(2, maxChoosableInteger) - 1;
		return _canIWin(a, desiredTotal, cache);
	}
};