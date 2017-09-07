class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        if (nums.empty() || nums[0] > target || nums[nums.size()-1] < target) return res;
        
        int l = 0, r = nums.size() - 1, mid = 0;
        int start = -1, end = -1;
        while (l < r)
        {
            mid = (l + r) / 2 + 1;
            if (nums[mid] == target)
            {
                vector<int> ltmp(nums.begin() + l, nums.begin() + mid);
                vector<int> rtmp(nums.begin()+mid+1, nums.begin()+r+1);
                auto lvec = searchRange(ltmp, target), rvec = searchRange(rtmp, target);
                if (lvec != res) start = lvec[0] + l;
                else start = mid;
                if (rvec != res) end = rvec[1] + mid + 1;
                else end = mid;
                break;
            }
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1; 
        }
        if (start == -1 && end == -1 && nums[l] == target && l == r) start = end = l;
        res[0] = start;
        res[1] = end;
        return res;
    }
};