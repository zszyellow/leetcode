class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res, len = nums.size();
        bool flag = false;
        for (int i = 0; i < len - 1; i ++)
        {
            if (flag) break;
            for (int j = i + 1; j < len ; j ++)
            {
                if (nums[i] == nums[j]) {
                    flag = true;
                    res = nums[i];
                }
            }
        }
        
        return res;
    }
};