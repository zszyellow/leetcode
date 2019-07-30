/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isTimeEnough(piles, H, mid)) right = mid;
            else left = mid + 1;
        }

        return left;
    }

    bool isTimeEnough(vector<int>& piles, int H, int sp) {
        int count = 0;
        for (int i = 0; i < piles.size(); i ++) {
            count += (piles[i]-1) / sp + 1;
            if (count > H) return false;
        }
        return true;
    }
};

