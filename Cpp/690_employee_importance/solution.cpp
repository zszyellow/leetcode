/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> m;
        int res = 0;
        for (int i = 0; i < employees.size(); i ++) m[employees[i]->id] = employees[i];
        dfs(m, id, res);
        return res;
    }
    
    void dfs(unordered_map<int, Employee*> m, int id, int& res) {
        res += m[id]->importance;
        auto tmp = m[id]->subordinates;
        for (int i = 0; i < tmp.size(); i ++) 
            dfs(m, tmp[i], res);
    }
};