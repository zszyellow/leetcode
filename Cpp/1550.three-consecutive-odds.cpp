class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if (arr.size() <= 2) return false;
        bool prev1 = arr[1] % 2, prev2 = arr[0] % 2, cur = false;
        for (int i = 2; i < arr.size(); ++ i) {
            cur = arr[i] % 2;
            if (cur && prev1 && prev2) return true;
            prev2 = prev1;
            prev1 = cur;
        }
        return false;
    }
};