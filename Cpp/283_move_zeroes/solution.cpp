class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size(), count = 0;
        for (int i = 0; i < len; i ++)
        {
            if (nums[i] == 0) 
            {
                count ++;
                nums.push_back(0);
            }
        }
        auto it = nums.begin();
        for (int j = 0; j < count;)
        {
            if (*it == 0) 
            {
                it = nums.erase(it);
                j ++;
            }
            else it ++;
        }
    }
};