class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), mask = 0, res = 0;
        vector<int> masks;
        for (string word : words) {
            mask = 0;
            for (char c : word) mask |= (1 << (c-'a'));
            masks.push_back(mask);
        }
        
        for (int i = 0; i < n-1; ++ i) {
            for (int j = i+1; j < n; ++ j) {
                if ((masks[i] & masks[j]) == 0) res = max(res, static_cast<int>(words[i].size()*words[j].size()));
            }
        }
        return res;        
    }
};