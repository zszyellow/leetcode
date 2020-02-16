/*
 * @lc app=leetcode id=1353 lang=cpp
 *
 * [1353] Maximum Number of Events That Can Be Attended
 */

// @lc code=start
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 0;
        int i = 0;
        int n = events.size();
        int maxD = 0;
        
        for (auto event : events) {
            maxD = max(maxD, event[1]);
        }
        
        sort(events.begin(), events.end());
        for (int d = 1; d <= maxD; d ++) {
            while (i < n && events[i][0] == d) {
                pq.push(events[i][1]);
                i ++;
            }
            while (!pq.empty() && pq.top() < d) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                res ++;
            }
        }
        return res;
    }
};
// @lc code=end

