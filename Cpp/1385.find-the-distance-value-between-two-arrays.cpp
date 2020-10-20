class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        /* brute force, TC: O(MN), SC: O(1) */
//         int res = 0;
        
//         for (int &a1 : arr1) {
//             bool flag = true;
//             for (int &a2 : arr2) {
//                 if (abs(a1 - a2) <= d) flag = false;
//             }
//             res += flag;
//         }
//         return res;
        
        /* binary search, TC: O(MlogN + NlogN), SC: O(1) */
        std::sort(arr2.begin(), arr2.end());
        int res = 0;
        for (int a1 : arr1) {
            int closest = get_closest(arr2, a1);
            if (abs(closest-a1) > d) res ++;
        }
        return res;
    }
    
    int get_closest(vector<int> &arr, int target) {
        if (target <= arr[0]) return arr[0]; 
        if (target >= arr.back()) return arr.back(); 

        int l = 0, r = arr.size(), mid = 0, n = arr.size(); 
        while (l < r) { 
            mid = l + (r - l) / 2; 
            if (arr[mid] == target) return arr[mid]; 
            else if (target < arr[mid]) { 
                if (mid > 0 && target > arr[mid-1]) 
                    return arr[mid] - target <= target - arr[mid-1] ? arr[mid] : arr[mid-1];
                r = mid; 
            } else { 
                if (mid < n - 1 && target < arr[mid + 1]) 
                    return target - arr[mid] <= arr[mid+1] - target ? arr[mid] : arr[mid+1];
                l = mid + 1;  
            } 
        } 

        return arr[mid]; 
    }
};