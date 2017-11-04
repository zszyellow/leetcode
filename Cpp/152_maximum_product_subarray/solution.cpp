class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int res(nums[0]);
        for (int i = 1, cmax = res, cmin = res; i < nums.size(); ++ i)
        {
            if (nums[i] < 0) std::swap(cmin, cmax);
            cmax = std::max(nums[i], cmax*nums[i]);
            cmin = std::min(nums[i], cmin*nums[i]);
            res = std::max(res, cmax);
        }
        
        return res;
    }
};