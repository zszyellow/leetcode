class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            int num_digits = 0;
            while (num > 0) {
                num_digits ++;
                num = num / 10;
            }
            if (num_digits % 2 == 0) res ++;
        }
        return res;
    }
};