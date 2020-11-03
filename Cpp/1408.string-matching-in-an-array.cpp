class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for (auto word1 : words) {
            for (auto word2 : words) {
                if (word1 != word2 && word2.find(word1) != string::npos) {
                    res.push_back(word1);
                    break;
                }
            }
        }
        return res;
    }
};