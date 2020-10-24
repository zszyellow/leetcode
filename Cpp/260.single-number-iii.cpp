class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bitmask = 0;
        for (int num : nums) {
            bitmask ^= num;
        }
        
        int rightmost_diff = bitmask & (-bitmask);
        int x = 0;
        for (int num : nums) {
            if (rightmost_diff & num) {
                x ^= num;
            }
        }
        return vector<int>{x, bitmask^x};
    }
};