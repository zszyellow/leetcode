class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnts(26, 0);
        for (char c : text) {
            cnts[c-'a'] ++;
        }
        
        vector<int> ballon{cnts[0], cnts[1], cnts[11]/2, cnts[14]/2, cnts[13]};
        return *min_element(ballon.begin(), ballon.end());
    }
};