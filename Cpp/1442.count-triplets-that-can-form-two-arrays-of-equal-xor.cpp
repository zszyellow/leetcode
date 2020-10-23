class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int N = arr.size(), res = 0;
        vector<int> prefix(N+1, 0);
        prefix[0] = 0;
        for (int i = 1; i <= N; ++ i) prefix[i] = prefix[i-1] ^ arr[i-1];
        
        for (int i = 0; i < N-1; ++ i) {
            for (int k = i+1; k < N ; ++ k) {
                if (prefix[i] == prefix[k+1])
                    res += k - i;
            }
        }
        return res;
    }
};