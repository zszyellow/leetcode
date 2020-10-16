class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        
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
        
        // bfs
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        unordered_map<string, bool> visited;
        visited[beginWord] = true;
        
        while (!q.empty()) {
            auto node = q.front();
            string cur_word = node.first;
            int level = node.second;
            q.pop();
            
            for (int i = 0; i < L; ++ i) {
                string pattern = string(cur_word.begin(), cur_word.begin()+i) + "*" + 
                                 string(cur_word.begin()+i+1, cur_word.end());
                if (combo_dict.find(pattern) != combo_dict.end()) {
                    for (string &next_word : combo_dict[pattern]) {
                        if (next_word == endWord) return level + 1;
                        else if (!visited[next_word]) {
                            visited[next_word] = true;
                            q.push(make_pair(next_word, level+1));
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};