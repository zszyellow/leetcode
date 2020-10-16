class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        /* one pass, TC: O(N), SC: O(N) */
//         vector<int> odds;
//         vector<int> evens;
        
//         for (int a : A) {
//             if (a % 2 == 0) evens.push_back(a);
//             else odds.push_back(a);
//         }
        
//         evens.insert(evens.end(), odds.begin(), odds.end());
//         return evens;
        
        /* Two pointers with swap, TC: O(N), SC: O(1) */
        int i = 0, j = A.size()-1;
        while (i < j) {
            if (A[i] % 2 > A[j] % 2) std::swap(A[i], A[j]);
            if (A[i] % 2 == 0) i ++;
            if (A[j] % 2 == 1) j --;
        }
        
        return A;
    }
};