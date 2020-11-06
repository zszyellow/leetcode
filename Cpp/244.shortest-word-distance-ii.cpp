class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            locs_[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int> &loc1 = locs_[word1], &loc2 = locs_[word2];
        int i1 = 0, i2 = 0, M = loc1.size(), N = loc2.size(), min_dis = INT_MAX;
        while (i1 < M && i2 < N) {
            min_dis = min(min_dis, abs(loc1[i1] - loc2[i2]));
            if (loc1[i1] < loc2[i2]) i1 ++;
            else i2 ++;
        }
        return min_dis;
    }
private:
    unordered_map<string, vector<int>> locs_;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */