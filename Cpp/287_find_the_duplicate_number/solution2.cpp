class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 0, h = nums.size()-1, len = nums.size();
        while (l < h)
        {
            int mid = (l + h) / 2;
            int count = 0;
            for (int i = 0; i < len; i ++)
                if (nums[i] <= mid) count ++;
            if (count > mid) h = mid;
            else l = mid + 1;
        }
        return l;
    }
};