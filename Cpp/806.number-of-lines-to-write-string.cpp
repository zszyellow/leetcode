class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        const int max_length = 100;
        vector<int> res{1, 0};
        int cur_length = 0;
        for (char c : S) {
            cur_length += widths[c-'a'];
            if (cur_length > max_length) {
                res[0] ++;
                cur_length = widths[c-'a'];
            } 
        }
        res[1] = cur_length;
        return res;
    }
};