class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[0] < rhs[0];
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (auto &interval : intervals) {
            if (pq.empty()) pq.push(interval[1]);
            else {
                if (interval[0] >= pq.top()) pq.pop();
                pq.push(interval[1]);
            }
        }
        return pq.size();
    }
};