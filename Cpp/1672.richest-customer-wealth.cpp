class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for (auto &person : accounts) {
            int wealth = accumulate(person.begin(), person.end(), 0);
            if (res < wealth) res = wealth;
        }
        return res;
    }
};