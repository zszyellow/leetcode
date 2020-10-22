class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int ca = countSetBits(a), cb = countSetBits(b);
            return (ca == cb && a < b) || ca < cb;
        });
        return arr;
    }
    
    int countSetBits(int num) {
        int set_bits = 0;
        while (num) {
            num &= (num-1);
            set_bits ++;
        }
        return set_bits;
    }
};