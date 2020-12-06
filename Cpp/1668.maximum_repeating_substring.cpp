class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int res = 0;
        string tmp = word;
        
        while (sequence.find(tmp) != string::npos) {
            res ++;
            tmp += word;
        }
        
        return res;
    }
};