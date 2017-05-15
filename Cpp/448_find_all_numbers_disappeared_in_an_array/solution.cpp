class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        
        for (int i = 0; i < len; i++)
        {
            int tmp = abs(nums[i]) - 1;
            if (nums[tmp] > 0) nums[tmp] *= -1;
        }
    
        for (int i = 0; i < len; i ++)
            if (nums[i] > 0) res.push_back(i + 1);
        
        return res;
    }
};