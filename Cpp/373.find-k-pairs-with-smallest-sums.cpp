class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto comp = [&](const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return nums1[lhs.first] + nums2[lhs.second] > nums1[rhs.first] + nums2[rhs.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        pq.push({0, 0});
        
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty()) return res;
        while (k > 0 && !pq.empty()) {
            auto idx_pair = pq.top();
            pq.pop();
            int i = idx_pair.first, j = idx_pair.second;
            res.push_back({nums1[i], nums2[j]});
            if (i+1 < nums1.size()) pq.push({i+1, j});
            if (i == 0 && j+1 < nums2.size()) pq.push({i, j+1});
            k--;
        }
        return res;
    }
};