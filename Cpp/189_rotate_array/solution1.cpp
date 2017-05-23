class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size(), _k = k % len;
        for (int i = 1; i <= _k; i ++)
        {
            nums.insert(nums.begin(), nums[len-1]);
            nums.pop_back();
        }
    }
};