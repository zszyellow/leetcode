class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < groupSizes.size(); ++ i) {
            if (m.find(groupSizes[i]) == m.end()) m[groupSizes[i]] = vector<int>{i};
            else m[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        for (auto&& [size, indices] : m) {
            int to_add = indices.size() / size;
            for (int i = 0; i < to_add; ++ i) {
                int start = i * size, end = start + size;
                res.push_back(vector<int>(indices.begin()+start, indices.begin()+end));
            }
        }
        return res;
    }
};