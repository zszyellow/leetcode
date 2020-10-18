class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if (arr.empty() || arr.size() == 1) return true;
        std::sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); ++ i) {
            int cur_diff = arr[i] - arr[i-1];
            if (cur_diff != diff) return false;
        }
        return true;
    }
};