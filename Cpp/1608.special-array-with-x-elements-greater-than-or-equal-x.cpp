class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        /* Brute force, TC: O(N^2), SC: O(1) */
//         int N = nums.size();
//         for (int i = 1; i <= N; ++i) {
//             if (count_if(nums.begin(), nums.end(), [&](const int &num) {return num >= i;}) == i) 
//                 return i;
//         }
//         return -1;
        
        /* Sort and Binary Search, TC: O(NlogN), SC: O(1) */
        // sort(nums.begin(), nums.end());
        // for (int i = 1; i <= nums.size(); ++i) {
        //     auto it = lower_bound(nums.begin(), nums.end(), i);
        //     if (distance(it, nums.end()) == i) return i;
        // }
        // return -1;
        
        /* Counting Sort, TC: O(N), SC: O(N) */
        int N = nums.size();
        vector<int> cnts(N+2);
        for (int n : nums) cnts[min(n, N)]++;
        for (int i = N; i >= 0; i--) {
            cnts[i] = cnts[i + 1] + cnts[i];
            if (cnts[i] == i) return i;
        }
        return -1;
    }
};