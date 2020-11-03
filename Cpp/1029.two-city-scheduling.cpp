class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res = 0, cnt1 = 0, cnt2 = 0, n = costs.size()/2;
        sort(costs.begin(), costs.end(), [](const vector<int> &cost1, const vector<int> &cost2) -> bool {
            return abs(cost1[0] - cost1[1]) < abs(cost2[0] - cost2[1]);
        });
        
        for (auto &&cost : costs) {
            if (cost[0] < cost[1]) {
                res += cost[0];
                cnt1 ++;
            } 
            else {
                res += cost[1];
                cnt2 ++;
            }
        }
    
        for (int i = 0; cnt1 < n && i < 2*n; ++i) {
            if (costs[i][0] >= costs[i][1]) {
                res += (costs[i][0] - costs[i][1]);        
                cnt1 ++;
            }
        }
        for (int i = 0; cnt2 < n && i < 2*n; ++i) {
            if (costs[i][0] < costs[i][1]) {
                res += (costs[i][1] - costs[i][0]);
                cnt2 ++;
            }
        }
        
        return res;
    }
};