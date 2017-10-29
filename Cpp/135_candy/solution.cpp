class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        int len(ratings.size());
        int res(0);
        vector<int> nums(len, 1);
        
        for (int i = 1; i < len; ++ i) 
        {
            if (ratings[i-1] < ratings[i]) nums[i] = nums[i-1] + 1;
        }
        for (int i = len-1; i > 0; -- i)
        {
            if (ratings[i-1] > ratings[i]) nums[i-1] = std::max(nums[i-1], nums[i]+1);
        }
        for (int val : nums) res += val;
        return res;
    }
};