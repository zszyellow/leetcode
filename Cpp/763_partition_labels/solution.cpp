class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last_exist[26];
        for (int i = 0; i < S.size(); i ++) last_exist[S[i]-'a'] = i;
        
        int j = 0;
        int anchor = 0;
        vector<int> res;
        for (int i = 0; i < S.size(); i ++) {
            j = std::max(j, last_exist[S[i]-'a']);
            if (i == j) {
                res.push_back(i-anchor+1);
                anchor = i + 1;
            }
        }
        return res;
    }
};