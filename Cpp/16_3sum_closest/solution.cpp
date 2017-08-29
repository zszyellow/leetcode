class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX, gap = INT_MAX;
        for (int i = 0; i < nums.size() - 2; i ++)
        {
            int m = i + 1, n = nums.size() - 1;
            while (m < n)
            {
                int tmp = nums[i] + nums[m] + nums[n] - target;
                if (abs(tmp) < gap)
                {
                    gap = abs(tmp);
                    res = nums[i] + nums[m] + nums[n];
                }
                if (tmp < 0) m ++;
                else n --;
            }
        }
        
        return res;
    }
};