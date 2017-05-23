class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size(), _k = k % len;
        reverse(nums.begin(), nums.begin()+len-_k);
        reverse(nums.begin()+len-_k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};