class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        
        for (int i = 0; i < len; i ++)
        {
            int tmp = abs(nums[i]) - 1;
            if (nums[tmp] > 0) nums[tmp] *= -1;
            else res.push_back(abs(nums[i]));
        }
        
        return res;
    }
};