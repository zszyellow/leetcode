class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int to_add = 1;
        std::for_each(nums.begin(), nums.end(), [&](int &num) {
            num += to_add;
            to_add = num;
        });
        int min_val = *min_element(nums.begin(), nums.end());
        return min_val >= 1 ? 1 : 2 - min_val;
    }
};