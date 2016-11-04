//https://leetcode.com/problems/queue-reconstruction-by-height/
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<pair<int,int>, int>> peopleAug;
        for(auto p:people)
        {
            pair<pair<int,int>,int> pp = make_pair(p, p.second);
            peopleAug.push_back(pp);
        }
        
        vector<pair<int, int>> res;
        pair<int,int> pa = _helper(peopleAug);
        while(pa.second > -1)
        {
            res.push_back(pa);
            pa = _helper(peopleAug);
        }
        return res;
    }
    
    pair<int,int> _helper(vector<pair<pair<int,int>, int>> &peopleAug)
    {
        pair<int,int> res = make_pair(INT_MAX,-1);
        if(peopleAug.size() == 0)
            return res;
        for(auto pp:peopleAug)
        {
            if(pp.second == 0)
            {
                if(pp.first.first < res.first)
                    res = pp.first;
            }
        }
        
        int s = peopleAug.size();
        
        for(int i = 0; i < s; i++)
        {
            if(res == peopleAug[i].first && i != s-1)
            {
                peopleAug[i] = peopleAug[s-1];
            }
            
            if(res.first >= peopleAug[i].first.first )
                peopleAug[i].second--;
        }
        
        peopleAug.pop_back();
        return res;
    }
};