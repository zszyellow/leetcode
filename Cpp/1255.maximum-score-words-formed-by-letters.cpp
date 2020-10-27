class Solution {
public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
        unordered_map<char, int> char_count;
        for (char ch : letters) {
            char_count[ch]++;
        }
        
        int res = 0;
        backtracking(words, score, char_count, 0, 0, res);
        return res;
    }
    
    void backtracking(vector<string> &words, 
                      vector<int> &score,
                      unordered_map<char, int> &char_count, 
                      int pos,
                      int cur_score, 
                      int &res) {
        if (pos == words.size()) {
            res = max(res, cur_score);
            return;
        }
        
        int word_score = 0;
        bool can_fit = true;
        for (char ch : words[pos]) {
            word_score += score[ch - 'a'];
            if (-- char_count[ch] < 0) {
                can_fit = false;
            }
        }
        if (can_fit) {
            backtracking(words, score, char_count, pos+1, cur_score + word_score, res);
        }
        
        for (char ch : words[pos]) {
            char_count[ch]++;
        }
        backtracking(words, score, char_count, pos+1, cur_score, res);
    }
};