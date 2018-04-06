class Solution {
public:
  vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    unordered_map<int, set<int>> m;
    vector<int> res;
    for (int i = 0; i < pid.size(); i ++) m[ppid[i]].insert(pid[i]);
    findToKill(m, res, kill);
    return res;
  }
    
  void findToKill(unordered_map<int, set<int>> &m, vector<int> &res, int kill) {
    res.push_back(kill);
    for (auto x : m[kill]) findToKill(m, res, x);
  }
};
