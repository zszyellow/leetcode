class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto it = nums.begin();
        int res = nums.size();
        
        while(it != nums.end())
        {
            if (*it == val) {
                it = nums.erase(it);
                res --;
            }
            else it ++;
        }
        
        return res;
    }
};