class Solution {
public:
    int rob(vector<int>& nums) {
        // a represents not able to choose next house, b represents able to choose next house
        int a = 0, b = 0;
        for (auto it = nums.begin(); it != nums.end(); it ++)
        {
            int tmp = b + *it;
            b = a;
            a = max(tmp, a);
        }
        
        return max(a, b);
    }
};