class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // Kadane Algorithm
        vector<int> cp(nums.begin()+1, nums.end());
        int max_ending_here = nums[0];
        int max_so_far = nums[0];

        for (int x : cp)
        {
            max_ending_here = std::max(x, max_ending_here + x);
            max_so_far = std::max(max_so_far, max_ending_here);
        }
        
        return max_so_far;
    }
};