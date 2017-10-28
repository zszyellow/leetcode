class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (int val : nums)
        {
            if (m[val]) continue;
            else
            {
                int sum = m[val-1] + m[val+1] + 1;
                m[val] = sum;
                res = std::max(res, sum);
                m[val-m[val-1]] = sum;
                m[val+m[val+1]] = sum;
            }
        }
        return res;
    }
};