class Solution {
public:
    int locate_row(vector<unordered_set<char>> &rows, char c) {
        for (int i = 0; i < 3; ++ i) {
            if (rows[i].count(tolower(c)))
                return i;
        }
        return 0;
    }
    
    bool is_same_row(vector<unordered_set<char>> &rows, string &word) {
        if (word.empty()) return true;
        int cur_row = locate_row(rows, word[0]);
        for (char c: word) {
            if (rows[cur_row].count(tolower(c)) == 0) return false;
        }
        return true;
    }
    
    vector<string> findWords(vector<string>& words) {
        vector<unordered_set<char>> rows{
            {'q','w','e','r','t','y','u','i','o','p'},
            {'a','s','d','f','g','h','j','k','l'},
            {'z','x','c','v','b','n','m'}
        };
        
        vector<string> res;
        for (string &word : words) {
            if (is_same_row(rows, word)) res.push_back(word);
        }
        return res;
    }
};