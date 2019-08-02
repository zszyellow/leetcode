/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */
class Solution {
private:
    vector<int> seq;
    // c++11 random number generator
    mt19937 rng{random_device{}()};
    uniform_int_distribution<int> uni;
public:
    Solution(vector<int>& w) {
        int total = 0;
        for (int i : w) {
            total += i;
            seq.push_back(total);
        }
        uni = uniform_int_distribution<int>{0, total-1};
    }
    
    int pickIndex() {
        int target = uni(rng);
        int l = 0, r = seq.size()-1;
        while (l != r) {
            int mid = l + (r - l) / 2;
            if (target >= seq[mid]) {
                l = mid + 1;
            }
            else r = mid;
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

