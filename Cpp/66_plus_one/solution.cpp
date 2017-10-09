class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return digits;
        int over = 1;
        int index = digits.size() - 1;
        
        while (over != 0 && index >= 0)
        {
            int temp = digits[index] + over;
            digits[index] = temp % 10;
            over = temp / 10;
            index --;
        }
        
        if (over) digits.insert(digits.begin(), 1);
        return digits;
    }
};