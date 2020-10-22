class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> hash_map;
        istringstream issA(A), issB(B);
        string token;
        while (getline(issA, token, ' ')) hash_map[token] ++;
        while(getline(issB, token, ' ')) hash_map[token] ++;
        
        vector<string> res;
        for (auto &&[word, cnt] : hash_map) {
            if (cnt == 1) 
                res.push_back(word);
        }
        return res;
    }
};