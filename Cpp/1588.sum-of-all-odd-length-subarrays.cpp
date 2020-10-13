class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;
        for (int i = 0; i < arr.size(); i ++) {
            int times = ((i + 1) * (arr.size() - i) + 1) / 2;
            res += arr[i] * times;
        }
        
        return res;
    }
};