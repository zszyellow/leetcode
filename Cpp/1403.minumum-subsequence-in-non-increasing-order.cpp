class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int cur = 0;
        vector<int> res;
        for (int &num : nums) {
            res.push_back(num);
            cur += num;
            if (cur > sum / 2) break;
        }
        return res;
    }
};