class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        vector<int> count(32, 0);
        
        for (int num : nums) {
            int i = 0;
            while (num) {
                count[i] += (num & 1);
                num >>= 1;
                i ++;
            }
        }
        
        int res = 0, n = nums.size();
        for (int c : count) {
            res += c * (n-c);
        }
        return res;
    }
};