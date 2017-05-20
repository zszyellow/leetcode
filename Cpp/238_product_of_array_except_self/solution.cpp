class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 1);
        for (int i = len - 1; i > 0; i --)
            res[i-1] = res[i] * nums[i];
        int tmp = 1;
        for (int i = 1; i < len; i ++)
        {
            tmp *= nums[i - 1];
            res[i] *= tmp; 
        }
        return res;
    }
};