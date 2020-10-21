class Solution {
public:
    int nextGreaterElement(int n) {
        if (n < 12) return -1;
        string n_str = to_string(n);
        if (next_permutation(n_str.begin(), n_str.end())) {
            long long tmp = stoll(n_str);
            return tmp > INT_MAX ? -1 : static_cast<int>(tmp);
        }
        return -1;
    }
};