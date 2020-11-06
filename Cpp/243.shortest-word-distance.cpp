class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int p1 = -1, p2 = -1, min_dis = INT_MAX, N = words.size();
        
        for (int i = 0; i < N; ++i) {
            if (words[i] == word1) p1 = i;
            else if (words[i] == word2) p2 = i;
            
            if (p1 != -1 && p2 != -1) min_dis = min(min_dis, abs(p1-p2));
        }
        return min_dis;
    }
};