class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int res = 0, cur_weight = 0, max_weight = 5000;
        for (int i = 0; i < arr.size(); ++ i) {
            cur_weight += arr[i];
            if (cur_weight > max_weight) break;
            else res ++;
        }
        return res;
    }
};