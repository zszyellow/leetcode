/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [x](int a, int b) {
            int xa = abs(x - a), xb = abs(x - b);
            return xa < xb || xa == xb && a < b;
        });
        arr.resize(k);
        sort(arr.begin(), arr.end());
        return arr;
    }
};

