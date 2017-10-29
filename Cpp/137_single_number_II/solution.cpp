class Solution {
public:
    // First time -> save it in "ones"
    // Second time -> clear "ones" but save it in "twos" for later check
    // Third time -> try to save in "ones" but value saved in "twos" clear it.
    int singleNumber(vector<int>& nums) 
    {
        int ones(0);
        int twos(0);
        for(int i = 0; i < nums.size(); ++ i)
        {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};