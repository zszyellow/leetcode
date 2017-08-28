class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        
        sort(nums.begin(), nums.end());
        int cur = nums[0];
        for (int i = 0; i < nums.size() - 2; i ++)
        {
            // avoid repeating
            if (i != 0 && cur == nums[i]) continue;
            int tmp = 0 - nums[i];
            int m = i + 1, n = nums.size() - 1;
            while (m < n)
            {
                if (nums[m] + nums[n] == tmp) 
                {
                    vector<int> newVec{nums[i], nums[m], nums[n]};
                    res.push_back(newVec);
                    m++;
                    n --;
                }
                else if (nums[m] + nums[n] < tmp) m ++;
                else n --;
            }
            cur = nums[i];
        }
        
        auto it = unique(res.begin(), res.end());
        res.resize(distance(res.begin(), it));
        
        return res;
    }
};