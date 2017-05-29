class Solution {
private:
    set<int> s;
public:
    int arrayNesting(vector<int>& nums) {
        int max = 0;
        for (int i = 0; i < nums.size(); i ++)
        {
            int tmp = check(nums, i);
            max = max > tmp ? max : tmp;
        }
        return max;
    }

    int check(vector<int> nums, int k)
    {
        int res = 0, tmp = k;
        while (s.find(tmp) == s.end()) 
        {
            s.insert(tmp);
            tmp = nums[tmp];
            res ++;
        }
        return res;
    }
};