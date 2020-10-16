class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return res;
        
        // preprocessing
        int L = beginWord.size();
        unordered_map<string, vector<string>> combo_dict;
        for (string &word : wordList) {
            for (int i = 0; i < L; ++ i) {
                string pattern = string(word.begin(), word.begin()+i) + "*" + 
                                 string(word.begin()+i+1, word.end());
                if (combo_dict.find(pattern) == combo_dict.end()) combo_dict[pattern] = vector<string>{word};
                else combo_dict[pattern].push_back(word);
            }
        }
        
        // bfs through path not word
        queue<vector<string>> q;
        q.push({beginWord});
        unordered_set<string> visited;
        visited.insert(beginWord);
        unordered_set<string> unvisited_cur_level(wordList.begin(), wordList.end());
        vector<string> sequence;
        int min_level = INT_MAX;
        int level = 0;
        
        while (!q.empty()) {
            auto path = q.front();
            q.pop();
            
            if (path.size() > level) {
                if (path.size() > min_level) break;
                else {
                    level = path.size();
                    for (auto &v : visited) {
                        unvisited_cur_level.erase(v);
                    }
                }
            } 
            string cur_word = path.back();
            
            for (int i = 0; i < L; ++ i) {
                string pattern = string(cur_word.begin(), cur_word.begin()+i) + "*" + 
                                 string(cur_word.begin()+i+1, cur_word.end());
                if (combo_dict.find(pattern) != combo_dict.end()) {
                    for (string &next_word : combo_dict[pattern]) {
                        vector<string> new_path(path);
                        if (next_word == endWord) {
                            min_level = level;
                            new_path.push_back(endWord);
                            res.push_back(new_path);
                        } else if (unvisited_cur_level.find(next_word) != unvisited_cur_level.end()) {
                            visited.insert(next_word);
                            new_path.push_back(next_word);
                            q.push(new_path);
                        }
                    }
                }
            }
        }
        
        return res;
    }
};