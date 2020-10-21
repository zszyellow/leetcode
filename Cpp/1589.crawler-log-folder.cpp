class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cur_depth = 0;
        for (string &log : logs) {
            if (log == "../") cur_depth = cur_depth == 0 ? 0 : cur_depth - 1;
            else if (log == "./") continue;
            else cur_depth += 1;
        }
        return cur_depth;
    } 
};