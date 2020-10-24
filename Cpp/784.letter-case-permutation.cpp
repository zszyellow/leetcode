class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        res.push_back("");
        
        for (char c : S) {
            int n = res.size();
            if (isalpha(c)) {
                for (int i = 0; i < n; ++ i) {
                    res.push_back(res[i]);
                    res[i] += tolower(c);
                    res[n+i] += toupper(c);
                } 
            } else {
                for (int i = 0; i < n; ++ i) {
                    res[i] += c;
                }
            }
        }
        return res;
    }
};