class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream iss(text);
        vector<string> words(istream_iterator<string>{iss}, istream_iterator<string>());
        
        vector<string> res;
        for (int i = 0; i < words.size()-2; ++ i) {
            if (words[i] == first && words[i+1] == second) res.push_back(words[i+2]);
        } 
        return res;
    }
};