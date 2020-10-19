class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> indices;
        int N = S.size();
        for (int i = 0; i < N; ++ i) {
            if (S[i] == C) indices.push_back(i);
        }
        
        vector<int> res;
        int M = indices.size(), j = 0;
        for (int i = 0; i < N; ++ i) {
            int diff = i - indices[j];
            if (diff <= 0 || j == M-1) res.push_back(abs(diff));
            else {
                int diff2 = i - indices[j+1];
                if (abs(diff2) > diff) res.push_back(diff);
                else {
                    res.push_back(abs(diff2));
                    j ++;
                }  
            }
        }
        return res;
    }
};