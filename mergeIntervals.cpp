/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Comparator
{
    bool operator()(Interval i, Interval j)
    {
        return i.start < j.start;
    }
} comparator;
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.size() < 2)
            return intervals;
        sort(intervals.begin(), intervals.end(), comparator);
        result.push_back(intervals[0]);
        int ctr = 0;
        int maxOfLast = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i].start <= maxOfLast)
            {
                result[ctr].end = max(maxOfLast, intervals[i].end);
                maxOfLast = max(maxOfLast, intervals[i].end);
            }
            else
            {
                result.push_back(intervals[i]);
                maxOfLast = intervals[i].end;
                ctr++;
            }
        }
        return result;
    }
};