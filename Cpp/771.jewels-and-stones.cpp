/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> m;
        for (char j : J) m[j] = 1;
        
        int res = 0;
        for (char s : S) {
            if (m.find(s) != m.end()) 
                res ++;
        }
        return res;
    }
};

