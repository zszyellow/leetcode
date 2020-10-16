class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int min_num = INT_MAX;
        for (int &a : A) min_num = std::min(min_num, a);
        
        int sum = 0;
        for (char c : std::to_string(min_num)) sum += (c - '0');
        
        return sum % 2 == 0;
    }
};