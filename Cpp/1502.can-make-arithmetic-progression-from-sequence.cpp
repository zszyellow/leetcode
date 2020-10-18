class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        /* sort and compare, TC: O(NlogN), SC: O(N) based on sort */
        // if (arr.empty() || arr.size() == 1) return true;
        // std::sort(arr.begin(), arr.end());
        // int diff = arr[1] - arr[0];
        // for (int i = 2; i < arr.size(); ++ i) {
        //     int cur_diff = arr[i] - arr[i-1];
        //     if (cur_diff != diff) return false;
        // }
        // return true;
        
        /* counting sort, TC: O(N), SC: O(1) */
        if (arr.size() <= 2) return true;
        int min = *min_element(arr.begin(), arr.end());
        int max = *max_element(arr.begin(), arr.end());
        if ((max-min) % (arr.size() - 1) != 0) return false;
        
        int diff = (max - min) / (arr.size() - 1), i = 0;
        while (i < arr.size()) {
            if (arr[i] == min + i*diff) i ++;
            else if ((arr[i] - min) % diff != 0) return false;
            else {
                int idx = (arr[i] - min) / diff;
                if (idx < i || arr[i] == arr[idx]) return false;
                swap(arr[i], arr[idx]);
            }
        }
        return true;
    }
};