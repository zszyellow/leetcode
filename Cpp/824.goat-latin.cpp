class Solution {
public:
    string toGoatLatin(string S) {
        vector<string> words;
        while (S.find(' ') != string::npos) {
            auto pos = S.find(' ');
            words.push_back(S.substr(0, pos));
            S = S.substr(pos+1);
        }
        words.push_back(S);
        
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (int i = 0; i < words.size(); ++ i) {
            if (vowels.count(words[i][0]) == 1) {
                words[i] += "ma";
            } else {
                words[i] = words[i].substr(1) + words[i][0] + "ma";
            }
            words[i] += string(i+1, 'a');
        }
        
        string res = "";
        for (string &word : words) res += word + " ";
        return res.substr(0, res.size()-1);
    }
};