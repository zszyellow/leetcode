class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for (int &num : nums) cnts[num] ++;
        sort(nums.begin(), nums.end(), [&](const int &lhs, const int &rhs) {
            return cnts[lhs] < cnts[rhs] || (cnts[lhs] == cnts[rhs] && lhs > rhs);
        });
        return nums;
    }
};