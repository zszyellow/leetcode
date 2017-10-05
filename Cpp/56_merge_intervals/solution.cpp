/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval a, Interval b)
    {
        return a.start < b.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 1 || intervals.empty()) return intervals;
        std::sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res(1, intervals[0]);
        int start, end;

        for (int i = 1; i < intervals.size(); i ++)
        {
            start = res.back().start;
            end = res.back().end;
            if (intervals[i].start <= end && intervals[i].start >= start)
            {
                if (intervals[i].end <= end) 
                    continue;
                else 
                {
                    res.pop_back();
                    Interval temp = Interval(start, intervals[i].end);
                    res.push_back(temp);
                }
            }
            else 
                res.push_back(intervals[i]);
        }
        
        return res;
        
    }
};