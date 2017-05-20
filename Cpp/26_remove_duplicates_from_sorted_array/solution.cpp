class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = nums.size();
        for (auto it = nums.begin(); it != nums.end();)
        {
            if (it != nums.begin() && *it == *(it - 1))
            {
                it = nums.erase(it);
                res --;
            }
            else it ++;
        }
        return res;
    }
};