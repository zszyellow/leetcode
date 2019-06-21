class Solution {
public:
    int fixedPoint(vector<int>& A) {
        int l = 0;
        int r = A.size()-1;
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (A[mid] == mid) {
                return mid;
            }
            else if (A[mid] < mid) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }

        return A[l] == l ? l : -1; 
    }
};