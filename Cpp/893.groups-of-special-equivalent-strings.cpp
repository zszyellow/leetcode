class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        vector<string> encoded(A.size(), string(52, '0'));
        int n = A[0].size();
        for (int i = 0; i < A.size(); ++ i) {
            string &str = A[i];
            for (int j = 0; j < n; j += 2) encoded[i][str[j]-'a'] ++;
            for (int j = 1; j < n; j += 2) encoded[i][str[j]-'a'+26] ++;
        }

        unordered_set<string> hash_set;
        for (string &str : encoded) hash_set.insert(str);
        return hash_set.size();
    }
};