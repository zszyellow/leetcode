class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < pid.size(); i ++) {
            m[ppid[i]].push_back(pid[i]);   
        }
        
        vector<int> res;
        queue<int> q;
        q.push(kill);
        
        while (!q.empty()) {
            int tmp = q.front();
            res.push_back(tmp);
            q.pop();
            for (auto child : m[tmp]) q.push(child);
        }
        
        return res;
    }