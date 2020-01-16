/*
 * @lc app=leetcode id=937 lang=cpp
 *
 * [937] Reorder Log Files
 */

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letters;
        vector<string> digits;
        
        for (string log : logs) {
            size_t tmp = log.find_first_of(' ');
            if (log[tmp+1] >= '0' && log[tmp+1] <= '9') {
                digits.push_back(log);
            } else {
                letters.push_back(log);
            }
        }
        
        sort(letters.begin(), letters.end(), comp);
        letters.insert(letters.end(), digits.begin(), digits.end());
        return letters;
    }
    
    static bool comp(string log1, string log2) {
        size_t idx1 = log1.find_first_of(' ');
        size_t idx2 = log2.find_first_of(' ');
        if (log1.substr(idx1) == log2.substr(idx2)) 
            return log1 < log2;
        else 
            return log1.substr(idx1) < log2.substr(idx2);
    }
};