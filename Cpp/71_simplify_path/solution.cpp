class Solution {
public:
    string simplifyPath(string path) {
        string res;
        string tmp;
        vector<string> pieces;
        stringstream ss(path);
        
        while (getline(ss,tmp,'/')) 
        {
            if (tmp == "" || tmp == ".") continue;
            if (tmp == ".." && !pieces.empty()) pieces.pop_back();
            else if (tmp != "..") pieces.push_back(tmp);
        }
        for (auto piece : pieces) res += "/" + piece;
        
        return res.empty() ? "/" : res;
    }
};