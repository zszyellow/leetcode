class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur_max_reach = 0;
        int last_max_reach = 0;
        
        for (int i = 0; i < nums.size(); i ++)
        {
            cur_max_reach = std::max(cur_max_reach, i + nums[i]);
            if (i == last_max_reach)
                last_max_reach = cur_max_reach;
            else if (i > last_max_reach)
                return false;
        }
        
        return true;
    }
};