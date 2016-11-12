/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 struct comparator
 {
     bool operator()(Interval  i, Interval j)
     {
         return (i.start < j.start);
     }
 } intervalComp;
 
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        auto i = lower_bound(intervals.begin(), intervals.end(), newInterval, intervalComp);
        Interval& temp = newInterval;
        if(i != intervals.begin())
        {
            auto j = i-1;
            for(auto vi=intervals.begin(); vi < j; vi++)
            {
                result.push_back(*vi);
            }
            if(temp.start <= j->end)
            {
                temp.end = max(j->end, temp.end);
                temp.start = j->start;
            }
            else
            {
                result.push_back(*j);
            }
        }
        while(i != intervals.end() && i->start <= temp.end)
        {
            temp.end = max(temp.end, i->end);
            i++;
        }
        result.push_back(temp);
        while(i != intervals.end())
        {
            result.push_back(*i);
            i++;
        }
        return result;
    }
};