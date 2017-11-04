class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        int l(0);
        int r(nums.size()-1);
        while (l + 1 < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r]) l = mid;
            else if (nums[mid] < nums[r]) r = mid;
        }
        return std::min(nums[l], nums[r]);
    }
};