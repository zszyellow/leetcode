class Solution {
public:
    void flip(vector<int>& arr, int k) {
        reverse(arr.begin(), arr.begin()+k);
    }
    
    vector<int> pancakeSort(vector<int>& arr) {
        int N = arr.size(), cur_end = N;
        vector<int> res;
        
        while (cur_end > 1) {
            int max_elem = INT_MIN, max_idx = 0;
            for (int i = 0; i < cur_end; ++i) {
                if (max_elem < arr[i]) {
                    max_elem = arr[i];
                    max_idx = i;
                } 
            }
            
            if (max_idx < cur_end - 1) {
                flip(arr, max_idx + 1);
                res.push_back(max_idx+1);
                flip(arr, cur_end);
                res.push_back(cur_end);
            }
            
            cur_end --;
        }
        
        return res;
    }
};

