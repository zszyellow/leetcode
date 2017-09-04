class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {  
        vector<int> result;  
        if(words.empty()) return result;
        
        int n = words.size(), m = words[0].size();  
        int l = m * n, len = s.size();  
        map<string, int> word_map;  
        for (auto& word:words) {  
            word_map[word] ++;  
        }  
        for(int i = 0; i <= len - l; i ++) {  
            string t = s.substr(i, l);  
            if(contains(word_map, t, m))   
                result.push_back(i);  
        }  
        return result;  
    }  
    
    bool contains(map<string, int> word_map, string& s, int m) {  
        for(int i = 0; i <= s.size() - m; i += m) {  
            string t = s.substr(i, m);  
            if((word_map[t] --)<=0) return false;  
        }  
        return true;  
    }  
};