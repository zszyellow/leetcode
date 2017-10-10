class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int tmp = nums[0];
        int res = 1;
        int times = 1;
        
        for (int i = 1; i < nums.size(); i ++)
        {
            if (tmp == nums[i] && times == 1)
            {
                times ++;
                res ++;
            }
            else if (tmp == nums[i] && times > 1)
            {
                nums.erase(nums.begin()+i);
                i --;
            }
            else if (tmp != nums[i])
            {
                tmp = nums[i];
                times = 1;
                res ++;
            }
        }
        return res;
    }
};