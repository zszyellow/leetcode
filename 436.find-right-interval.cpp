/*
 * @lc app=leetcode id=436 lang=cpp
 *
 * [436] Find Right Interval
 */
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> start_index;
        for (int i = 0; i < intervals.size(); i ++) start_index[intervals[i].front()] = i;
        
        vector<int> res;
        for (auto interval : intervals) {
            auto it = start_index.lower_bound(interval.back());
            int tmp = it == start_index.end() ? -1 : it->second;
            res.push_back(tmp);
        }

        return res;
    }
};

