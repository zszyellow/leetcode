class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        set<int> r_visited;
        set<int> c_visited;
        int res = 0;
        
        for(int i = 0; i < picture.size(); i ++) {
            for (int j = 0; j < picture[0].size(); j ++) {
                if (picture[i][j] == 'B' && r_visited.find(i) == r_visited.end() && c_visited.find(j) == c_visited.end()) {
                    r_visited.insert(i);
                    c_visited.insert(j);
                    if (check(picture, r_visited, c_visited, i, j)) res ++;
                }
            }
        }
        
        return res;
    }
    
    bool check(vector<vector<char>>& picture, set<int>& r_visited, set<int>& c_visited, int i, int j) {
        bool res = true;
        for (int n = 0; n < picture[0].size(); n ++) {
            if (picture[i][n] == 'B' && n != j) {
                res = false;
                c_visited.insert(n);
            }
        }
        for (int m = 0; m < picture.size(); m ++) {
            if (picture[m][j] == 'B' && m != i) {
                res = false;
                r_visited.insert(m);
            }
        }
        return res;
    }
};