class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> hm;
        unordered_set<string> visited;
        for (string a : allowed) {
            string key = a.substr(0, 2);
            char val = a[2];
            if (hm.find(key) != hm.end()) 
                hm[key].push_back(val);
            else {
                vector<char> tmp{val};
                hm[key] = tmp;
            }
        }
        
        return dfs(bottom, hm, visited);
    }
    
    bool dfs(string bottom, unordered_map<string, vector<char>> &hm, unordered_set<string> &visited) {
        if (bottom.size() == 1) return true;
        if (!is_next(bottom, hm, visited)) return false;
        
        vector<string> next;
        next.push_back("");
        for (int i = 0; i < bottom.size()-1; ++ i) {
            string key = bottom.substr(i, 2); 
            int size = next.size(), n = hm[key].size(); 
            vector<string> cp(next); 
            for (int j = 0; j < n; ++ j) { 
                if (j == 0) {
                    for (int k = 0; k < size; ++ k) next[k] += hm[key][j];    
                } else {
                    for (int k = 0; k < size; ++ k) cp[k] += hm[key][j];
                    next.insert(next.end(), cp.begin(), cp.end());
                } 
            }
        }
        for (string b : next) {
            if (dfs(b, hm, visited)) return true;
        }
        return false;
    }
    
    bool is_next(string bottom, unordered_map<string, vector<char>> &hm, unordered_set<string> &visited) {
        if (visited.count(bottom)) return false;
        for (int i = 0; i < bottom.size()-1; ++ i) {
            string key = bottom.substr(i, 2);
            if (hm.find(key) == hm.end()) {
                visited.insert(bottom);
                return false;
            }
        }
        return true;
    }
};