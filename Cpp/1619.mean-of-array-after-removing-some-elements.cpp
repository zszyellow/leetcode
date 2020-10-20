class Solution {
public:
    double trimMean(vector<int>& arr) {
        int N = arr.size(), M = N / 20;
        std::sort(arr.begin(), arr.end());
        int sum = std::accumulate(arr.begin()+M, arr.begin()+(N-M), 0);
        return static_cast<double>(sum) / (N-2*M);
    }
};