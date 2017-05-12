class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        int len = nums.size();
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i ++)
        {
            if (i % 2 == 0) res += nums[i];
        }
        return res;
    }
};