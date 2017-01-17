class Solution {
    unordered_map<int, bool> cache;
public:
    bool canWinNim(int n) {
        if(cache.find(n) != cache.end())
            return cache[n];
        if(n <= 3)
        {
            cache[n] = true;
            return true;
        }
        for(int i = 1; i <= 3; i++)
        {
            if(!canWinNim(n-i))
            {
                cache[n] = true;
                return true;
            }
        }
        cache[n] = false;
        return false;
    }
};