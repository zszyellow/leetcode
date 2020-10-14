class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int biggest = INT_MIN, second_biggest = INT_MIN;
        for (int& num : nums) {
            if (num > biggest) {
                second_biggest = biggest;
                biggest = num;
            } else if (num > second_biggest) {
                second_biggest = num;
            }
        }
        return (biggest - 1) * (second_biggest - 1);
    }
};