/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
    
    static bool comp(const int a, const int b) {
        int na = getBits(a);
        int nb = getBits(b);
        if (na == nb) {
            return a < b;
        } 
        return na < nb;
    }
    
    static int getBits(int num) {
        int set_bits = 0;
        while (num) {
            num = num & (num-1);
            set_bits ++;
        }
        return set_bits;
    }
};
// @lc code=end

